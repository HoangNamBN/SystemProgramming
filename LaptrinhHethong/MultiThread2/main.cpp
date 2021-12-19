#include <iostream>
#include <pthread.h>
#include <string.h>
#include <stdio.h>
#include <windows.h>
#include <time.h>


using namespace std;
void gotoxy(short x, short y) {
COORD pos = {x, y};
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int flag = 0;
const std::string currentDateTime() {
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    // Visit http://en.cppreference.com/w/cpp/chrono/c/strftime
    // for more information about date/time format
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);

    return buf;
}
void * fun_thread1(void *data)
{
	flag=0;
    FILE *fp=fopen("c:\\vd.txt","rt");
    if(fp==NULL)
    {
    	printf("file ko mo duoc\n");
    	return 0;
	}
	char buffer[1024]="";
	while(1)
	{
    	if(fgets(buffer,1024,fp)==NULL)
      		break;
      	gotoxy(1,10);
    	puts(buffer);
    }
    flag =1;
   
}
void * fun_thread2(void *data)
{
    //for(int i=0;i<50;i++)
    while(1)
    {
    	
        //printf("*****************Thread2\n");
         
         if (flag ==1 ){
         	gotoxy(1,21);
         	 std::cout << "Finsh" << std::endl;
         	 break;
		 }
		 else
		 {
		 	gotoxy(1,20);
		 	std::cout << "currentDateTime()=" << currentDateTime() << std::endl;
		 }
		 
    }     
}

int main(int argc, char *argv[])
{
    int status;
    Sleep(1000);
    // creating thread objects
    pthread_t thrd_1;
    pthread_t thrd_2;
    // create thread
    pthread_create(&thrd_1,NULL,fun_thread1,(void *)0);
    pthread_create(&thrd_2,NULL,fun_thread2,(void *)0);    
    pthread_join(thrd_1, (void **)&status);
    pthread_join(thrd_2, (void **)&status);
    system("PAUSE");
    return 1;
} 



