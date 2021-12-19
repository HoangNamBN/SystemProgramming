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
   
    FILE *fp=fopen("c:\\vd.txt","rb");
    if(fp==NULL)
    {
    	printf("file ko mo duoc\n");
    	return -1;
	}
	//chuyen xuong cuoi file
	fseek(fp,0L,SEEK_END);
	int byteCount=ftell(fp);
	printf("file co do dai = %i\n",byteCount);
	// quay ve dau file
	fseek(fp,0L,SEEK_SET);
	//doc noi dung file
	unsigned char *byteFile=new unsigned char[byteCount];
	if(byteFile==NULL)
	{
		printf("khong cap phat duoc\n");
		closesocket(socketC);
       	fclose(fp);
       	return -1;
	}
	// doc toan bo file vao bo nho byteFile, file kich thuoc nho thi doc toan bo 1 lan
	int countRead=fread(byteFile,1,byteCount,fp);
	if(countRead!=byteCount)
	{
		printf("khong doc file hop le\n");
		closesocket(socketC);
       	fclose(fp);
       	delete [] byteFile;
       	return -1;
	}
	
	/////////////////////////////
	// gui toi server xau begin va vao vong lap cho ready
	char buffer[1024];
	strcpy(buffer,"begin");
	if (sendto(socketC, buffer, sizeof(buffer), 0, (sockaddr*)&serverInfo, len) == SOCKET_ERROR)
	{
		printf("khong gui duoc\n");
		closesocket(socketC);
       	fclose(fp);
       	delete [] byteFile;
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
	printf("Gui toi server do dai file\n");
	// bat dau gui do dai file va noi dung file
	sendto(socketC, (const char*)&byteCount, sizeof(byteCount), 0, (sockaddr*)&serverInfo, len);
	sendto(socketC, (const char*)byteFile, byteCount, 0, (sockaddr*)&serverInfo, len);
	
	 /*
    while (1)
    {
        char buffer[1024];
        ZeroMemory(buffer, sizeof(buffer));
        printf("Please input your message: ");
        gets( buffer);
        if (strcmp(buffer,"exit") == 0)
            break;
        if (sendto(socketC, buffer, sizeof(buffer), 0, (sockaddr*)&serverInfo, len) != SOCKET_ERROR)
        {
            if (recvfrom(socketC, buffer, sizeof(buffer), 0, (sockaddr*)&serverInfo, &len) != SOCKET_ERROR)
            {
                printf("Receive response from server: %s\n", buffer);
            }
        }
    }
    */
	
	
	
	
	
	/////////////////////////////
    closesocket(socketC);
    
    fclose(fp);
    delete [] byteFile;
    return(0);
}
