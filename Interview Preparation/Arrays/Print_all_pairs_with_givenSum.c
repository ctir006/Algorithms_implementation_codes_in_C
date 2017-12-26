#include <stdio.h>
#include <stdlib.h>

int find(int *,int,int);

int hash[10]={0};

int main()
{
	int i,*a,n,s,f;
	printf("How many ? ");
	scanf("%d",&n);
	a=malloc(n*sizeof(int));
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("Enter the sum :");
	scanf("%d",&s);
	for(i=0;i<n;i++){
		f=s-a[i];
		if(f>0 && hash[f]==1)
			printf("(%d,%d)",a[i],f);
		hash[a[i]]=1;
	}
	return 0;
}

int find(int a[],int f,int n)
{
	int i;
	for(i=0;i<n;i++){
		if(a[i]==f)
			return 1;
	}
	return 0;
}