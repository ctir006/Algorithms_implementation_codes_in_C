#include <stdio.h>

void printpair(int *,int);
#define MAX 11

int hash[MAX]={0};

int main()
{
	int a[]={1,2,10,6,9,11,5,3,7,8,0};
	int s,i;
	for(i=0;i<11;i++)
		hash[a[i]]=1;
	printf("Enter the sum :");
	scanf("%d",&s);
	printpair(a,s);
	return 0;
}

void printpair(int a[],int s)
{
	int b,i;
	for(i=0;i<11;i++)
	{
		b=s-a[i];
		if(b>=0 && b<=11)
			if(hash[b]==1)
				printf("(%d,%d)\n",a[i],b);
	}
}