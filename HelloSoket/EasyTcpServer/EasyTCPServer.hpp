#ifndef _EasyTCPServer_hpp_
#define _EasyTCPServer_hpp_

#ifdef _WIN32
	#define WIN32_LEAN_AND_MEAN
	#define _WINSOCK_DEPRECATED_NO_WARNINGS
	#include<windows.h>
	#include<WinSock2.h>
	#pragma comment(lib,"ws2_32.lib")
#else
	#include<unistd.h>
	#include<arpa/inet.h>
	#include<string.h>
	#define SOCKET int
	#define INVALID_SOCKET (SOCKET)(~0)
	#define SOCKET_ERROR (-1)
#endif

#include<iostream>
#include<vector>
#include"MessageHeader.hpp"
#include<thread>
using namespace std;
class EasyTCPServer{
public:
	EasyTCPServer(){
		_sock = INVALID_SOCKET;
	}
	virtual ~EasyTCPServer(){
		Close();
	}
	//初始化socket
	void InitSocket(){
#ifdef _WIN32
		WORD ver = MAKEWORD(2, 2);
		WSADATA dat;
		WSAStartup(ver, &dat);
#endif // _WIN32
		if (_sock != INVALID_SOCKET){
			cout << "关闭旧链接" << endl;
			Close();
		}
		_sock = socket(AF_INET, SOCK_STREAM, 0);
		if (_sock == INVALID_SOCKET){
			cout << "socket建立失败" << endl;
		}
		else{
			cout << "socket建立成功" << endl;
		}
		
	}
	//绑定端口
	int Bind(const char* ip,unsigned short port){
		sockaddr_in _sin = {};
		_sin.sin_family = AF_INET;
		_sin.sin_port = htons(port);
#ifdef _WIN32
		if (ip){
			_sin.sin_addr.S_un.S_addr = inet_addr(ip);
		}
		else{
			_sin.sin_addr.S_un.S_addr = INADDR_ANY;
		}
#else
		if (ip){
			_sin.sin_addr.s_addr = inet_addr(ip);
		}
		else{
			_sin.sin_addr.s_addr = INADDR_ANY;
		}
#endif
		int ret = ::bind(_sock, (sockaddr*)&_sin, sizeof(_sin));
		if ( ret== SOCKET_ERROR){
			cout << "用于接收客户端连接的网络端口绑定NG" << endl;
		}
		else{
			cout << "用于接收客户端连接的网络端口绑定OK" << endl;
		}
		return ret;
	}
	//监听端口
	int Listen(int n){
		int ret = listen(_sock,n);
		if (ret == SOCKET_ERROR){
			cout << "监听失败 socket="<<_sock << endl;
		}
		else{
			cout << "监听成功 socket=" << _sock<< endl;
		}
		return ret;
	}
	//接收客户端连接
	SOCKET Accept(){
		sockaddr_in clientAddr = {};
		int nAddrLen = sizeof(clientAddr);
		SOCKET _cSock = INVALID_SOCKET;
#ifdef _WIN32
		_cSock = accept(_sock, (sockaddr*)&clientAddr, &nAddrLen);
#else
		_cSock = accept(_sock, (sockaddr*)&clientAddr, (socklen_t*)&nAddrLen);
#endif
		
		if (_cSock == INVALID_SOCKET){
			cout << "接收无效客户端socket" << endl;
		}
		else{
			NewUserJoin userJoin;
			SendDataToAll(&userJoin);
			cout << "新客户端加入--IP：" << inet_ntoa(clientAddr.sin_addr) << "    Socket:" << (int)_cSock << endl;
			g_clients.push_back(_cSock);
		}
		return _cSock;
	}
	//关闭socket
	void Close(){
		if (_sock != INVALID_SOCKET){
#ifdef _WIN32
		for (int n = g_clients.size() - 1; n >= 0; n--){
			closesocket(g_clients[n]);
		}
		closesocket(_sock);
		WSACleanup();
#else
		for (int n = g_clients.size() - 1; n >= 0; n--){
			close(g_clients[n]);
		}
#endif
			_sock = INVALID_SOCKET;
		}
	}
	//是否工作中
	bool isRun(){
		return _sock != INVALID_SOCKET;
	}
	//接收数据，处理粘包
	int RecvData(SOCKET _cSock){
		char szRecv[4096] = {};
		int nLen = recv(_cSock, szRecv, sizeof(DataHeader), 0);
		DataHeader* dataHeader = (DataHeader*)szRecv;
		if (nLen <= 0){
			cout << "客户端退出  socket："<<_cSock << endl;
			return -1;
		}
		recv(_cSock, szRecv + sizeof(DataHeader), dataHeader->dataLength - sizeof(DataHeader), 0);
		OnNetMsg(_cSock,dataHeader);
		return 0;
	}
	bool OnRun(){
		if (isRun()){
			fd_set fdRead;
			fd_set fdWrite;
			fd_set fdExp;

			FD_ZERO(&fdRead);
			FD_ZERO(&fdWrite);
			FD_ZERO(&fdExp);

			FD_SET(_sock, &fdRead);
			FD_SET(_sock, &fdWrite);
			FD_SET(_sock, &fdExp);

			for (int n = g_clients.size() - 1; n >= 0; n--){
				FD_SET(g_clients[n], &fdRead);
			}
			timeval t = { 1, 0 };//过t时间没反应就执行下面的
			if (select(_sock + 1, &fdRead, &fdWrite, &fdExp, &t)<0){
				Close();
				return false;
			}
			if (FD_ISSET(_sock, &fdRead)){
				FD_CLR(_sock, &fdRead);
				Accept();


			}
			for (size_t n = 0; n< fdRead.fd_count; n++){
				if (RecvData(fdRead.fd_array[n]) == -1){
					auto iter = find(g_clients.begin(), g_clients.end(), fdRead.fd_array[n]);
					if (iter != g_clients.end()){
						g_clients.erase(iter);
					}
				}
			}
			return true;
		}
		return false;
		
	}
	//响应网络消息
	virtual void OnNetMsg(SOCKET _cSock,DataHeader *dataHeader){
		switch (dataHeader->cmd){
		case CMD_LOGIN:{
			Login* login=(Login*)dataHeader;
			cout << "CMD_LOGIN     " << "uername:" << login->userName << "   password:" << login->Password << endl;
			LoginResult loginResult = {};
			cout << loginResult.cmd<<endl;
			//loginResult.cmd = CMD_LOGIN_RESULT;
			send(_cSock, (char*)&loginResult, sizeof(LoginResult), 0);
		}
		break;
		case CMD_LOGOUT:{
			Logout* logout=(Logout*)dataHeader;
			cout << "CMD_LOGOUT   " << "uername:" << logout->userName << endl;
			LogoutResult logoutResult;
			send(_cSock, (char*)&logoutResult, sizeof(LogoutResult), 0);
		}
		break;
		default:{
			dataHeader->cmd = CMD_ERROR;
			dataHeader->dataLength = 0;
			send(_cSock, (char*)&dataHeader, sizeof(dataHeader), 0);
		}
		break;
		}
	}
	//发送数据
	int SendData(SOCKET _cSock, DataHeader *dataHeader){
		if (isRun() && dataHeader){
			return send(_cSock, (const char*)dataHeader, dataHeader->dataLength, 0);
		}
		return SOCKET_ERROR;
	}
	//群发数据
	void SendDataToAll(DataHeader *dataHeader){
		if (isRun() && dataHeader){
			for (int n = (int)g_clients.size() - 1; n >= 0;n--){
				SendData(g_clients[n],dataHeader);
			}
		}
	}

private:
	SOCKET _sock;
	vector<SOCKET> g_clients;
};


#endif