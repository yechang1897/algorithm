#ifndef _EasyTCPClient_hpp_
#define _EasyTCPClient_hpp_
#ifdef _WIN32
	#define WIN32_LEAN_AND_MEAN
	
	#include<windows.h>
	#include<Winsock2.h>
	#pragma comment(lib,"ws2_32.lib")
#else
	#include<unistd.h>
	#include<arpa/inet.h>
	#include<string.h>
	#define SOCKET int
	#define INVALID_SOCKET (SOCKET)(-0)
	#define SOCKET_ERROR (-1)
#endif
#include<iostream>
#include"MessageHeader.hpp"
using namespace std;
class EasyTCPClient{
public:
	SOCKET _sock;
public:
	EasyTCPClient(){
		_sock = INVALID_SOCKET;
	}
	virtual ~EasyTCPClient(){
		Close();
	}
	//初始化socket
	void InitSocket(){
#ifdef _WIN32
		WORD ver = MAKEWORD(2,2);
		WSADATA dat;
		WSAStartup(ver,&dat);
#endif // _WIN32
		if (_sock !=INVALID_SOCKET){//万一这个socket之前用过没关掉，所以这里确保关闭一下
			cout << "关闭旧链接" << endl;
			Close();
		}
		_sock = socket(AF_INET,SOCK_STREAM,0);
		if (_sock==INVALID_SOCKET){
			cout << "socket建立失败" << endl;
		}
		else{
			cout << "socket建立成功" << endl;
		}
	}
	//连接服务器
	int Connect(char* ip,unsigned short port){
		if (_sock==INVALID_SOCKET){
			InitSocket();
		}
		sockaddr_in _sin;
		_sin.sin_family = AF_INET;
		_sin.sin_port = htons(port);
#ifdef _WIN32
		_sin.sin_addr.S_un.S_addr=inet_addr(ip);
#else
		_sin.sin_addr.s_addr=inet_addr(ip);
#endif
		int ret = connect(_sock,(sockaddr*)&_sin,sizeof(sockaddr_in));
		if (ret==SOCKET_ERROR){
			cout << "连接服务器失败" << endl;
		}
		else{
			cout << "连接服务器成功" << endl;
		}
		return ret;
	}
	//查询数据
	void OnRun(){
		while (isRun()){
			fd_set fdReads;
			FD_ZERO(&fdReads);
			FD_SET(_sock, &fdReads);

			timeval t = { 0, 0 };//过t时间没反应就执行下面的
			select(_sock, &fdReads, 0, 0, &t);

			if (FD_ISSET(_sock, &fdReads)){
				FD_CLR(_sock, &fdReads);

				if (RecvData(_sock) == -1){
					_sock = INVALID_SOCKET;
					
				}
			}
		}
	}
	//关闭socket
	void Close(){
		if (_sock!=INVALID_SOCKET){
#ifdef _WIN32
			closesocket(_sock);
			WSACleanup();
#else
			close(_sock);
#endif
			_sock = INVALID_SOCKET;
		}

	}
	//是否工作中
	bool isRun(){
		return _sock != INVALID_SOCKET;
	}
	//接收数据
	int RecvData(SOCKET _cSock){
		//接收客户端的数据
		char szRecv[4096] = {};
		int nLen = recv(_cSock, szRecv, sizeof(DataHeader), 0);
		DataHeader* dataHeader = (DataHeader*)szRecv;
		if (nLen <= 0){
			cout << "与服务器断开连接" << endl;
			return -1;
		}
		recv(_cSock, szRecv + sizeof(DataHeader), dataHeader->dataLength - sizeof(DataHeader), 0);
		OnNetMsg(dataHeader);
		return 0;
	}
	//响应数据
	virtual void OnNetMsg(DataHeader *dataHeader){
		switch (dataHeader->cmd){
		case CMD_LOGIN_RESULT:{
			LoginResult* loginResult = (LoginResult*)dataHeader;
			cout << "收到服务器信息：CMD_LOGIN_RESULT,数据长度：" << loginResult->dataLength << endl;
		}
		break;
		case CMD_LOGOUT_RESULT:{
			LogoutResult* logoutResult = (LogoutResult*)dataHeader;
			cout << "收到服务器信息：CMD_LOGOUT_RESULT,数据长度：" << logoutResult->dataLength << endl;
		}
		break;
		case CMD_NEW_USER_JOIN:{
			NewUserJoin* newUserJoin = (NewUserJoin*)dataHeader;
			cout << "收到服务器信息：CMD_NEW_USER_JOIN,数据长度：" << newUserJoin->dataLength << endl;
		}
		break;
		default:{
			cout << "nothing:" << dataHeader->cmd << endl;
		}
		break;
		}
	}
	//发送数据
	int SendData(DataHeader *dataHeader){
		if (isRun()&&dataHeader){
			return send(_sock, (const char*)dataHeader, dataHeader->dataLength, 0);
		}
		return SOCKET_ERROR;
	}
private:


};





#endif