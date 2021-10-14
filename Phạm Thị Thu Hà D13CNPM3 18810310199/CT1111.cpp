
#include <stdio.h>
#include <winsock2.h>
#include <conio.h>
#include<iostream>
#include<string.h>
#include <pthread.h>
using namespace std;
void*func1(void*data)
{
 WSADATA wsaData;
 SOCKADDR_IN rAddr;
 int iRc;
 iRc = WSAStartup(MAKEWORD(2, 2), &wsaData);
 SOCKET sk = socket(AF_INET, SOCK_STREAM, 0);
 rAddr.sin_family = AF_INET;
 rAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
 rAddr.sin_port = htons(100);
 iRc = connect(sk, (LPSOCKADDR)&rAddr, sizeof(rAddr));
 while(1)
 {
 char st;
 cout<<"Nhap ki tu:";
 st=getch();
 cout<<st<<endl;
 send(sk,(const char*)&st, sizeof(st), 0);
 int br=int(st);
 if(br==27)
   break;
 }
 closesocket(sk);
 WSACleanup();
 getch(); 
    return 0;
}
int main(int argc, char *argv[])
{
    int status;
    pthread_t thrd_1;
    pthread_create(&thrd_1,NULL,func1,NULL);
    pthread_join(thrd_1, (void **)&status);
    system("PAUSE");
    return 1;
}

