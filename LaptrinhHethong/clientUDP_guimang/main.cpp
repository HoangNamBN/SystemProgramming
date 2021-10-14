#include <iostream>
#include <winsock2.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//https://stackoverflow.com/questions/14665543/how-do-i-receive-udp-packets-with-winsock-in-c


int main(int argc, char** argv) {
	WSADATA wsaData;
    WSAStartup(MAKEWORD(2, 2), &wsaData);

    SOCKET socketC;

    struct sockaddr_in serverInfo;
    int len = sizeof(serverInfo);
    serverInfo.sin_family = AF_INET;
    serverInfo.sin_port = htons(1234);
    serverInfo.sin_addr.s_addr = inet_addr("127.0.0.1");

    socketC = socket(AF_INET,SOCK_DGRAM,0);
   
    // gui toi server xau begin va vao vong lap cho ready
	char buffer[1024];
	strcpy(buffer,"begin");
	if (sendto(socketC, buffer, sizeof(buffer), 0, (sockaddr*)&serverInfo, len) == SOCKET_ERROR)
	{
		printf("khong gui duoc\n");
		closesocket(socketC);
       	return -1;
	}
	while(1)
	{
		 if (recvfrom(socketC, buffer, sizeof(buffer), 0, (sockaddr*)&serverInfo, &len) != SOCKET_ERROR)
		 {
		 	if(strcmp(buffer,"ready")==0)
			 {
		 		printf("Server da san sang\n");
				 break;	
			 }
		 }
	}
    
    
    float a[10];
  
  	// nhap tu ban phim
    for(int i=0; i<10; i++)
	{
		printf("Gia tri phan tu a[%d]=", i);
		scanf("%d", &a[i]);
	}

	// gui tung phan tu mang toi server
    for(int i=0; i<10; i++){
    	sendto(socketC, (const char*)&a[i], sizeof(a[i]), 0, (sockaddr*)&serverInfo, len);
	
	}
	
	/////////////////////////////
    closesocket(socketC);
    
    
    return(0);
}
