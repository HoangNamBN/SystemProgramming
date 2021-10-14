#include <stdio.h>
#include <windows.h>
#include <conio.h>

int main(int argc, char** argv)
{
	for(int i=0; i < argc;i++)
		printf("%s\n",argv[i]);
    DWORD attr;
    if(argc > 1)// co tam so dong lenh
    	attr = GetFileAttributes((LPCSTR)argv[1]);
    else
		attr = GetFileAttributes((LPCSTR)"abc.zip");
    if (attr == INVALID_FILE_ATTRIBUTES )
    {
    	printf("khong phai 1 file");
    	getch();
    	return -1;
    }
    // khi là 1 file thì phân tích ti?p, ví du file read only hay ?
    if ((attr & FILE_ATTRIBUTE_READONLY)) 
    	printf("file chi doc \n ");
    // phat hien file la file nen hay ?
    if ((attr & FILE_ATTRIBUTE_COMPRESSED)) 
    	printf("file nen \n ");
    if ((attr & FILE_ATTRIBUTE_HIDDEN)) 
    	printf("file an \n ");
    if ((attr & FILE_ATTRIBUTE_ARCHIVE)) 
    	printf("file Archive \n ");
    return 1;
}
