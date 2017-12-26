#include <stdio.h>
int ugly(int);

int main()
{
	int i,k;
	for(i=1;i<25;i++)
	{
		k=ugly(i);
		if(k==1)
			printf("\n%d\n\t",i);
	}
	return 0;
}

int ugly(int n)
{
	while(1)
	{
		if(n%2==0)
		{
			n=n/2;
			if(n==0 || n==1)
				return 1;
		}
		else if(n%3==0)
		{
			n/=3;
			if(n==0 || n==1)
				return 1;
		}
		else if(n%5==0)
		{
			n/=5;
			if(n==0 || n==1)
				return 1;
		}
		else
			return 0;
	}
}