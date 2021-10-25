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
	//��ʼ��socket
	void InitSocket(){
#ifdef _WIN32
		WORD ver = MAKEWORD(2,2);
		WSADATA dat;
		WSAStartup(ver,&dat);
#endif // _WIN32
		if (_sock !=INVALID_SOCKET){//��һ���socket֮ǰ�ù�û�ص�����������ȷ���ر�һ��
			cout << "�رվ�����" << endl;
			Close();
		}
		_sock = socket(AF_INET,SOCK_STREAM,0);
		if (_sock==INVALID_SOCKET){
			cout << "socket����ʧ��" << endl;
		}
		else{
			cout << "socket�����ɹ�" << endl;
		}
	}
	//���ӷ�����
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
			cout << "���ӷ�����ʧ��" << endl;
		}
		else{
			cout << "���ӷ������ɹ�" << endl;
		}
		return ret;
	}
	//��ѯ����
	void OnRun(){
		while (isRun()){
			fd_set fdReads;
			FD_ZERO(&fdReads);
			FD_SET(_sock, &fdReads);

			timeval t = { 0, 0 };//��tʱ��û��Ӧ��ִ�������
			select(_sock, &fdReads, 0, 0, &t);

			if (FD_ISSET(_sock, &fdReads)){
				FD_CLR(_sock, &fdReads);

				if (RecvData(_sock) == -1){
					_sock = INVALID_SOCKET;
					
				}
			}
		}
	}
	//�ر�socket
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
	//�Ƿ�����
	bool isRun(){
		return _sock != INVALID_SOCKET;
	}
	//��������
	int RecvData(SOCKET _cSock){
		//���տͻ��˵�����
		char szRecv[4096] = {};
		int nLen = recv(_cSock, szRecv, sizeof(DataHeader), 0);
		DataHeader* dataHeader = (DataHeader*)szRecv;
		if (nLen <= 0){
			cout << "��������Ͽ�����" << endl;
			return -1;
		}
		recv(_cSock, szRecv + sizeof(DataHeader), dataHeader->dataLength - sizeof(DataHeader), 0);
		OnNetMsg(dataHeader);
		return 0;
	}
	//��Ӧ����
	virtual void OnNetMsg(DataHeader *dataHeader){
		switch (dataHeader->cmd){
		case CMD_LOGIN_RESULT:{
			LoginResult* loginResult = (LoginResult*)dataHeader;
			cout << "�յ���������Ϣ��CMD_LOGIN_RESULT,���ݳ��ȣ�" << loginResult->dataLength << endl;
		}
		break;
		case CMD_LOGOUT_RESULT:{
			LogoutResult* logoutResult = (LogoutResult*)dataHeader;
			cout << "�յ���������Ϣ��CMD_LOGOUT_RESULT,���ݳ��ȣ�" << logoutResult->dataLength << endl;
		}
		break;
		case CMD_NEW_USER_JOIN:{
			NewUserJoin* newUserJoin = (NewUserJoin*)dataHeader;
			cout << "�յ���������Ϣ��CMD_NEW_USER_JOIN,���ݳ��ȣ�" << newUserJoin->dataLength << endl;
		}
		break;
		default:{
			cout << "nothing:" << dataHeader->cmd << endl;
		}
		break;
		}
	}
	//��������
	int SendData(DataHeader *dataHeader){
		if (isRun()&&dataHeader){
			return send(_sock, (const char*)dataHeader, dataHeader->dataLength, 0);
		}
		return SOCKET_ERROR;
	}
private:


};





#endif