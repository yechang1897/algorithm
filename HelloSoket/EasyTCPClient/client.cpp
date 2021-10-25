#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include<iostream>
#include<stdlib.h>
#include"EasyTCPClient.hpp"
#include<vector>
#include<cstring>
#include<thread>
#pragma comment(lib,"ws2_32.lib")
using namespace std;

vector<SOCKET> g_clients;




void cmdThread(EasyTCPClient *client){
	while(true){
		char cmdBuf[256] = {};
		cin >> cmdBuf;
		if (strcmp(cmdBuf, "exit") == 0){
			client->Close();
			cout << "�˳��߳�" << endl;
			break;
		}
		else if (strcmp(cmdBuf, "login") == 0){
			Login login;
			strcpy(login.userName, "�����");
			strcpy(login.Password, "password");
			client->SendData(&login);
		}
		else if (strcmp(cmdBuf, "logout")){
			Logout logout;
			strcpy(logout.userName, "�����");
			client->SendData(&logout);
		}
		else{
			cout << "��֧�ֵ�����" << endl;
		}
	}
}

int main(){
	EasyTCPClient client;
	client.InitSocket();
	client.Connect("127.0.0.1",4567);
	thread t1(cmdThread,&client);
	t1.detach();
	client.OnRun();

	client.Close();
	system("pause");
	return 0;
	
}