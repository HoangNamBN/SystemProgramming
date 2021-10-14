#include <iostream>
#include <stdio.h>
#include <winsock2.h>
#include <string.h>
#include <pthread.h>
#include <windows.h>
#include <time.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int sock, length, n;
int fromlen;
struct sockaddr_in server;
struct sockaddr_in from;
char buf[1024];
unsigned short serverPort = 1234;
    
void error (const char *msg)
{
    perror(msg);
    exit(0);
}


void * fun_thread2(void *data)
{
    //for(int i=0;i<50;i++)
   printf("Waiting...\n");
    int i;
    int byteCount;
    while(1)
    {
        n = recvfrom(sock, buf, 1024, 0, (struct sockaddr *)&from, &fromlen);
        //if (n<0) error("recvfrom");
        if(n>0)
        	printf("Received a datagram: %s\n", buf);
           
    }
}


int main(int argc, char** argv) {
	WSAData data;
    WSAStartup( MAKEWORD( 2, 2 ), &data );
    
    int status;
    pthread_t thrd_2;
    pthread_create(&thrd_2,NULL,fun_thread2,(void *)0);    
    pthread_join(thrd_2, (void **)&status);
	system("PAUSE");
	
    
    sock=socket(AF_INET, SOCK_DGRAM, 0);
    if (sock < 0) error("Opening socket");
    length = sizeof(server);
    memset(&server, 0, length);
    server.sin_family = AF_INET;
    server.sin_addr.s_addr=inet_addr("127.0.0.1");//INADDR_ANY;//serAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_port=htons(serverPort);
    if (bind(sock,(struct sockaddr *)&server, length)<0) error ("binding");
    fromlen = sizeof(struct sockaddr_in);
//    printf("Waiting...\n");
//    int i;
//    int byteCount;
//    while(1)
//    {
//        n = recvfrom(sock, buf, 1024, 0, (struct sockaddr *)&from, &fromlen);
//        //if (n<0) error("recvfrom");
//        if(n>0)
//        	printf("Received a datagram: %s\n", buf);
//           
//    }
    closesocket(sock);
    WSACleanup();
	return 0;
}

