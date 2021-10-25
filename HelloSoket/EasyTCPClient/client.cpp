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
			cout << "退出线程" << endl;
			break;
		}
		else if (strcmp(cmdBuf, "login") == 0){
			Login login;
			strcpy(login.userName, "吴煜铮");
			strcpy(login.Password, "password");
			client->SendData(&login);
		}
		else if (strcmp(cmdBuf, "logout")){
			Logout logout;
			strcpy(logout.userName, "吴煜铮");
			client->SendData(&logout);
		}
		else{
			cout << "不支持的命令" << endl;
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