#include <stdio.h>

int lay_nghich_dao(int a,int m)
{
	for(int b=1;b < m; b++)	
	{
		if((a*b)%m==1)
			return b;		
	}
	return -1;
}

int main()
{
	unsigned char a=17;
	int m=257;
	int b=lay_nghich_dao((int)a,m);
	printf("b=%i\n",b);
	int c=lay_nghich_dao(b,m);
	printf("c=%i\n",c);
}
