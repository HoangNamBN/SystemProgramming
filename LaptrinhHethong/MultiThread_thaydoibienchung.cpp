#include <iostream>
#include <pthread.h>
using namespace std;
#define COUNT 100
int count=0;
void * fun_thread1(void *data)
{
    for(int i=0;i<COUNT;i++)
    { 
    	count++;
        printf("In Thread 1\n");//  //cout<<endl<<"In Thread 1"<<endl;
        
    }     
}
void * fun_thread2(void *data)
{
    for(int i=0;i<COUNT;i++)
    { 
    	count++;
        printf("Thread2\n");//cout<<endl<<"In Thread 2"<<endl;
    }     
}
int main(int argc, char *argv[])
{
    int status;
    pthread_t thrd_1,thrd_2;// thread objects
    // create thread
    pthread_create(&thrd_1,NULL,fun_thread1,NULL);
    pthread_create(&thrd_2,NULL,fun_thread2,NULL;    
    pthread_join(thrd_1, (void **)&status);
    pthread_join(thrd_2, (void **)&status);
    system("PAUSE");
    return 1;
}
