#include <stdio.h>

int min(int,int,int);

int main()
{
	int i,j,a[][5]={{1,1,1,1,1},{0,1,1,1,1},{1,1,1,1,1},{0,1,1,0,1},{0,0,1,1,1}},b[5][5]={0},l,t,d,max=0,c=0;
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			if(i>0 && j>0 && a[i][j]!=0)
			{
				l=b[i][j-1];t=b[i-1][j];d=b[i-1][j-1];
				b[i][j]=min(l,t,d)+a[i][j];
				if(b[i][j]>max)
					max=b[i][j];
			}
			else
			{
				b[i][j]=a[i][j];
			}
		}
	}
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			if(b[i][j]==max)
				c++;
			printf("%d ",b[i][j]);
		}
		printf("\n");
	}
	printf("Total number of (%d X %d) and count is %d",max,max,c);
	return 0;
}

int min(int a,int b,int c)
{
	if(a<b)
		if(a<c)
			return a;
		if(c<b)
			return c;
	else if(b<c)
		return b;
	else
		return c;
}
