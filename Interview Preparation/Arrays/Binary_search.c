#include <stdio.h>
#include <stdlib.h>

void insertion(int*,int);
int binarysearch(int*,int,int,int);
int binarysearchwhile(int*,int,int,int);

int main()
{
	int *a,n,i,searchelement;
	printf("How many element ? ");
	scanf("%d",&n);
	a=malloc(n*sizeof(int));
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	insertion(a,n);
	printf("Enter the element to be searched :");
	scanf("%d",&searchelement);
	if(binarysearch(a,searchelement,0,n-1))
		printf("Element found!!!\n");
	else	
		printf("Element not found!!!\n");
	if(binarysearchwhile(a,searchelement,0,n-1))
		printf("Element found!!!\n");
	else	
		printf("Element not found!!!\n");
	return 0;
}

int binarysearchwhile(int a[],int d,int s,int l)
{
	int m;
	while(s<=l)
	{
		m=(s+l)/2;
		if(a[m]==d)
			return 1;
		else if(a[m]>d)
			l=m;
		else
			s=m+1;
	}
	return 0;
}

int binarysearch(int a[],int d,int s,int l)
{
	if(s>l)
		return 0;
	int m;
	m=(s+l)/2;
	if(a[m]==d)
		return 1;
	else if(a[m]>d)
		binarysearch(a,d,s,m);
	else
		binarysearch(a,d,m+1,l);
}

void insertion(int a[],int n)
{
	int i,j,key;
	for(i=1;i<n;i++){
		key=a[i];
		j=i-1;
		while(j>=0 && a[j]>key){
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=key;
	}
	return NULL;
}