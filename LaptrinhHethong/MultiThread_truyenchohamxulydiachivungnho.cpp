#include <iostream>
#include <pthread.h>
#include <windows.h>
using namespace std;
#define COUNT 100
int count1=0;
int count2=0;
void * fun_thread1(void *data)
{
	int *pCount=(int*)data;
    for(int i=0;i<COUNT;i++)
    { 
    	(*pCount)++;
        printf("In Thread 1\n");//  //cout<<endl<<"In Thread 1"<<endl;
    }     
}
void * fun_thread2(void *data)
{
	int *pCount=(int*)data;
    for(int i=0;i<COUNT;i++)
    { 
    	(*pCount)++;
    	Sleep(1);
        printf("Thread2\n");//cout<<endl<<"In Thread 2"<<endl;
    }     
}
int main(int argc, char *argv[])
{
    int status;
    // creating thread objects
    pthread_t thrd_1;
    pthread_t thrd_2;
    // create thread
    pthread_create(&thrd_1,NULL,fun_thread1,(void*)&count1);
    pthread_create(&thrd_2,NULL,fun_thread2,(void*)&count1);    
    pthread_join(thrd_1, (void **)&status);
    pthread_join(thrd_2, (void **)&status);
    printf("count1=%i\n",count1);
     printf("count2=%i\n",count2);
    
	system("PAUSE");
    
    return 1;
}
