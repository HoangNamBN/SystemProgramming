#include<iostream>
#include<winsock2.h>
#include<string>
#include<string.h>
#include<windows.h>
#include<stdio.h>
#pragma comment(lib, WS2_32.Lib)
using namespace std;

//Ma hoa RSA
int sodu(int a, int b)
{
	if (b<0) b=-b;
	while (a<0)
		a+=b;
	return (a%b);
}
int  ucln(int a, int b)
{
	if (a == b) return a;
	if(a>b) return ucln(a-b,b);
	if(b>a) return ucln(a,b-a);
}
int NghichDaoModun (int a, int m)
{
	if (m<0) m =-m;
	if(ucln(a,m)>1) return -1;
	if(m==1) return -1;
	a = a%m;
	int r,q,y0,y1,y;
	y0 = 0;
	y1 =1;
	int m_org = m;
	while(1)
	{
		r = m%a;
		if(r==0)
			return sodu(y,m_org);
		q = (int)(m/a);
		y = y0 - y1 * q;
		y0 = y1;
		y1 = y;
		m=a;
		a=r;
	}
}
int soduluythua (int a, int b, int c) // a^b*(mod c)
{
	if (b ==0) return 1;
	if (b==1) return a%c;
	if (b%2==0)
		return soduluythua(((a%c)*(a%c))%c,b/2,c);
	if (b%2 == 1)
	{
		int d = soduluythua(((a%c)*(a%c))%c,(b-1)/2,c);
		d = (a*d) %c;
		return d;
	}
}
int mahoaRSA (int x, int e, int n)
{
	return soduluythua(x,e,n);
}
//int giaimaRSA (int y, int d, int n)
//{
//	return soduluythua(y,d,n);
//}
int main()
{
	char buff[256];
	FILE *fpt;
	cout << "Doc file!!\n";
	if((fpt = fopen("C:\Users\marin_000\Desktop\PRLT\FILE_RSA\C++\fileX.txt", "r+")) == NULL)
		cout << "File khong ton tai \n";
	else
	{
		fscanf(fpt, "%c", &buff);
	}
	fclose(fpt);
	cout << "Ma hoa RSA: ";
	int encryptRSA[sizeof(buff)];
	int p = 53, q = 61, e = 17;
	int d = NghichDaoModun(e, (p-1)*(q-1));
	for(int i = 0; i < strlen(buff); i++);
	{
		encryptRSA[i] = mahoaRSA((int)buff[i], e, p*q);
	}
	cout << "Chuoi duoc ma hoa RSA: ";
	for(int i = 0; i < strlen(buff); i++)
	{
		cout << encryptRSA[i];
	}
	
	WSADATA wsaData;
	SOCKADDR_IN rAddr;
	int iRc;
	iRc = WSAStartup(MAKEWORD(2, 2), &wsaData);
	SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);
	rAddr.sin_family = AF_INET;
	rAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	rAddr.sin_port = htons(100);
    cout <<"Cho thiet lap ket noi toi server!!" << endl;
	iRc = connect(sock, (LPSOCKADDR)&rAddr, sizeof(rAddr));
    if (iRc != 0)
    {
        cout << "Ket noi toi server that bai!!" << endl;
    }
    else
    {
        cout << "Ket noi toi server thanh cong!!" << endl;
        cout << "Gui chuoi ma hoa RSA sang server!!" << endl;
        char *buffKT = new char();
        sprintf(buffKT, "%d", strlen(buff));
        for(int i = 0; i < strlen(buff); i++)
        {
            //Chuyen doi
            char *buffRSA = new char();
            sprintf(buffRSA, "%d", encryptRSA[i]);
            //Gui sang server
            send(sock, buffRSA, strlen(buffRSA), 0);
            delete buffRSA;
            Sleep(10);
        }
        cout << "Gui khoa cong khai sang server";
        int key[2];
        key[0] = d;
        key[1] = p*q;
        for(int i = 0; i < 2; i++)
        {
        	char *buffKey = new char();
        	sprintf(buffKey, "%d", key[i]);
        	send(sock, buffKey, strlen(buffKey), 0);
        	delete buff;
        	Sleep(10);
		}
		cout << "Chuyen du lieu hoan tat!!" << endl;
	}
	return 0;
	
}
