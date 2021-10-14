#include <iostream>


#include <stdio.h>
#include <winsock2.h>
#include <conio.h>
int main()
{
	/* Khai báo bi?n */
	WSADATA wsaData;
	SOCKADDR_IN serAddr, cliAddr;
	int iRc;
	int adsize;
	char buffer[256];

	/* N?p thu vi?n và kh?i t?o socket */
	iRc = WSAStartup(MAKEWORD(2, 2), &wsaData);
	SOCKET ssk = socket(AF_INET, SOCK_STREAM, 0);

	/* Thi?t l?p c?u trúc d?a ch? cho socket */
	serAddr.sin_family = AF_INET;
	serAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	serAddr.sin_port = htons(1024);

	/* G?n d?a ch? cho socket và th?c hi?n ch? thi?t l?p k?t n?i */
	iRc = bind(ssk, (LPSOCKADDR)&serAddr, sizeof(serAddr));
	iRc = listen(ssk, 5);
	adsize = sizeof(cliAddr);
	SOCKET sk = accept(ssk, (LPSOCKADDR)&cliAddr, &adsize);

	/* Nh?n d? li?u t? Client */
	iRc = recv(sk, buffer, 256, 0);
	if (iRc == SOCKET_ERROR)
		printf("Could not receive data from server.\n");
	else {
		buffer[iRc] = 0;
		printf("Message from client: %s\n", buffer);
	}

	/* Ðóng socket và gi?i phóng tài nguyên */
	closesocket(sk);
	closesocket(ssk);
	WSACleanup();

	getch();

	return 0;
}

