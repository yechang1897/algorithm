#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include<iostream>
#include<WinSock2.h>
#include<windows.h>
#include<cstring>
#include"EasyTCPServer.hpp"
#pragma comment(lib,"ws2_32.lib")
using namespace std;


int main(){
	EasyTCPServer server;
	server.InitSocket();
	server.Bind(nullptr,4567);
	server.Listen(5);
	while (server.isRun()){
		server.OnRun();
	}
	server.Close();
	system("pause");
	return 0;
}