#include <stdio.h>
#include <windows.h>
#include <pthread.h>
#include <queue>
using namespace std;
queue<char> Q;
char c=' ';
bool flag=false;
void * fun_thread1(void *data)
{
	while(c!=27){c=getc(stdin);Q.push(c);lag=true;}
}
void * fun_thread2(void *data)
{
	while(c!=27)
	{
		if(Q.empty()==false)
		{
			fflush(stdin);printf("%c\n",Q.front());Q.pop();flag=false;
		}
   }     
}
int main(int argc, char *argv[])
{
    int status;
    pthread_t thrd_1, thrd_2;
    pthread_create(&thrd_1,NULL,fun_thread1,(void *)0);pthread_create(&thrd_2,NULL,fun_thread2,(void *)0);    
    pthread_join(thrd_1, (void **)&status);pthread_join(thrd_2, (void **)&status);
    system("PAUSE");
    return 1;
}
