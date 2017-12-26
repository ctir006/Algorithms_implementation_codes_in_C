#include <stdio.h>
int min(int,int,int);

int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	printf("%d\n",min(a,b,c));
}

int min(int a,int b,int c)
{
	if(a>b)
		if(a>c)
			return a;
		if(c>b)
			return c;
	else if(b>c)
		return b;
	else
		return c;
}