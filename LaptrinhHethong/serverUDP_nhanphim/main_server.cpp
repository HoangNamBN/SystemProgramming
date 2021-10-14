#include <iostream>
#include <stdio.h>
#include <winsock2.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void error (const char *msg)
{
    perror(msg);
    exit(0);
}

int main(int argc, char** argv) {
	WSAData data;
    WSAStartup( MAKEWORD( 2, 2 ), &data );
	
    int sock, length, n;
    int fromlen;
    struct sockaddr_in server;
    struct sockaddr_in from;
    char buf[1024];
    unsigned short serverPort = 1234;
    sock=socket(AF_INET, SOCK_DGRAM, 0);
    if (sock < 0) error("Opening socket");
    length = sizeof(server);
    memset(&server, 0, length);
    server.sin_family = AF_INET;
    server.sin_addr.s_addr=inet_addr("127.0.0.1");//INADDR_ANY;//serAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_port=htons(serverPort);
    if (bind(sock,(struct sockaddr *)&server, length)<0) error ("binding");
    fromlen = sizeof(struct sockaddr_in);
    printf("Waiting...\n");
    int i;
    int byteCount;
    while(1)
    {
        n = recvfrom(sock, buf, 1024, 0, (struct sockaddr *)&from, &fromlen);
        if (n<0) error("recvfrom");
        //write(1,"Received a datagram: ", 21);
        //write(1,buf,n);
        //for(i=0;i < strlen(buf);i++)
        //	buf[i]=buf[i]-'a'+'A';
        printf("Received a datagram: %s\n", buf);
        if(strcmp(buf,"begin")==0){
        	n = sendto(sock, "ready",5,0,(struct sockaddr *)&from,fromlen);
        	//continue;
        	n = recvfrom(sock, (char*)&byteCount, sizeof(byteCount), 0, (struct sockaddr *)&from, &fromlen);
        	printf("%i\n",byteCount);
        	unsigned char *byteFile=new unsigned char[byteCount];
        	n = recvfrom(sock, (char*)byteFile, byteCount, 0, (struct sockaddr *)&from, &fromlen);
        	////////////////////////////
        	FILE *fp=fopen("c:\\vdcopy.txt","w+b"); 
        	////////////////
			fwrite(byteFile,1,byteCount,fp);
			
        	////////////////
        	fclose(fp);
        	///////////////////////////
        	delete [] byteFile;
		}  
		
		
		   
    }
    closesocket(sock);
    WSACleanup();
	return 0;
}
