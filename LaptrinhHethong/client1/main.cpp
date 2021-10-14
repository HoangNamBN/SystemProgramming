// clientSocket.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <winsock2.h>
#include <conio.h>

int main()
{
	/* Khai b�o bi?n */
	WSADATA wsaData;
	SOCKADDR_IN rAddr;
	char buffer[20]="Hello2";
	int iRc;

	/* N?p thu vi?n v� kh?i t?o socket */
	iRc = WSAStartup(MAKEWORD(2, 2), &wsaData);
	SOCKET sk = socket(AF_INET, SOCK_STREAM, 0);

	/* K?t n?i d?n Server */
	rAddr.sin_family = AF_INET;
	rAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	rAddr.sin_port = htons(1024);
	iRc = connect(sk, (LPSOCKADDR)&rAddr, sizeof(rAddr));

	/* Nh?n v� g?i th�ng di?p */
	//printf("Message:");
	//gets(buffer);
	iRc = send(sk, buffer, strlen(buffer), 0);

	/* ��ng socket v� gi?i ph�ng t�i nguy�n */
	closesocket(sk);
	WSACleanup();

	getch();	
    return 0;
}


