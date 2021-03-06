// clientSocket.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <winsock2.h>

#pragma comment(lib, "wsock32.lib")
int main()
{
	/* Khai báo biến */
	WSADATA wsaData;
	SOCKADDR_IN rAddr;
	char buffer[20]="Hello";
	int iRc;

	/* Nạp thư viện và khởi tạo socket */
	iRc = WSAStartup(MAKEWORD(2, 2), &wsaData);
	SOCKET sk = socket(AF_INET, SOCK_STREAM, 0);

	/* Kết nối đến Server */
	rAddr.sin_family = AF_INET;
	rAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	rAddr.sin_port = htons(1024);
	iRc = connect(sk, (LPSOCKADDR)&rAddr, sizeof(rAddr));

	/* Nhận và gửi thông điệp */
	//printf("Message:");
	//gets(buffer);
	iRc = send(sk, buffer, strlen(buffer), 0);

	/* Đóng socket và giải phóng tài nguyên */
	closesocket(sk);
	WSACleanup();

    return 0;
}

