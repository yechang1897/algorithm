#include<iostream>
#include<WinSock2.h>
#include<windows.h>

#pragma comment(lib,"ws2_32.lib")
int main(){
	WORD ver = MAKEWORD(2,2);
	WSADATA dat;
	WSAStartup(ver,&dat);


	WSACleanup();
	return 0;
}