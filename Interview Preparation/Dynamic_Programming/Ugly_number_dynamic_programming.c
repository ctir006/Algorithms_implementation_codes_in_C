#include <stdio.h>
int min(int,int,int);

int main()
{
	int n=0,i=0,j=0,k=0,p=1;
	int u[100]={0},d;
	u[0]=1;
	while(n<=25)
	{
		d=min(u[i]*2,u[j]*3,u[k]*5);
		if(d==1)
		{
			if(u[p-1]!=u[i]*2)
				u[p++]=u[i]*2;
			i++;
		}
		else if(d==2)
		{
			if(u[p-1]!=u[j]*3)
				u[p++]=u[j]*3;
			j++;
		}
		else
		{
			if(u[p-1]!=u[k]*5)
				u[p++]=u[k]*5;
			k++;
		}
		n++;
	}
	i=-1;
	while(u[++i]!=0)
		printf("%d\t",u[i]);
	return 0;
}

int min(int a,int b,int c)
{
	if(a<b)
		if(a<c)
			return 1;
		if(c<b)
			return 3;
	else if(b<c)
		return 2;
	else
		return 3;
}