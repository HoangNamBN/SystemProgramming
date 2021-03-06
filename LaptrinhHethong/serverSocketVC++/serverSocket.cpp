// serverSocket.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <winsock2.h>

#pragma comment(lib, "wsock32.lib")
int main()
{
	/* Khai báo biến */
	WSADATA wsaData;
	SOCKADDR_IN serAddr, cliAddr;
	int iRc;
	int adsize;
	char buffer[256];

	/* Nạp thư viện và khởi tạo socket */
	iRc = WSAStartup(MAKEWORD(2, 2), &wsaData);
	SOCKET ssk = socket(AF_INET, SOCK_STREAM, 0);

	/* Thiết lập cấu trúc địa chỉ cho socket */
	serAddr.sin_family = AF_INET;
	serAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	serAddr.sin_port = htons(1024);

	/* Gắn địa chỉ cho socket và thực hiện chờ thiết lập kết nối */
	iRc = bind(ssk, (LPSOCKADDR)&serAddr, sizeof(serAddr));
	iRc = listen(ssk, 5);
	adsize = sizeof(cliAddr);
	SOCKET sk = accept(ssk, (LPSOCKADDR)&cliAddr, &adsize);

	/* Nhận dữ liệu từ Client */
	iRc = recv(sk, buffer, 256, 0);
	if (iRc == SOCKET_ERROR)
		printf("Could not receive data from server.\n");
	else {
		buffer[iRc] = 0;
		printf("Message from client: %s\n", buffer);
	}

	/* Đóng socket và giải phóng tài nguyên */
	closesocket(sk);
	closesocket(ssk);
	WSACleanup();


	return 0;
}
