
#include <iostream>
#include <stdio.h>
#include <winsock2.h>
#include <conio.h>
#include <pthread.h>
using namespace std;
void *func1(void*data)
{
 WSADATA wsaData;
 SOCKADDR_IN serAddr, cliAddr;
 int iRc;
 int adsize;
 char buffer[256];
 iRc = WSAStartup(MAKEWORD(2, 2), &wsaData);
 SOCKET ssk = socket(AF_INET, SOCK_STREAM, 0);
 serAddr.sin_family = AF_INET;
 serAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
 serAddr.sin_port = htons(100);
 iRc = bind(ssk, (LPSOCKADDR)&serAddr, sizeof(serAddr));
 iRc = listen(ssk, 5);
 adsize = sizeof(cliAddr);
 SOCKET sk = accept(ssk, (LPSOCKADDR)&cliAddr, &adsize);
 while(1)
 {
 char st;
 iRc=recv(sk,(char *)&st,sizeof(st), 0);
 cout<<st<<endl;
 int a=int(st);
 if(a==27)
  break; 
 }
 closesocket(sk);
 closesocket(ssk);
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

