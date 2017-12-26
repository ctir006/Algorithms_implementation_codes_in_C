#include <stdio.h>

void max_heapify(int a[],int);
void min_heapify(int a[],int);

int main()
{
	int i,a[]={0,1,6,2,9,8,3,7,0,4,5};
	for(i=5;i>=1;i--)
		max_heapify(a,i);
	for(i=1;i<=10;i++)
		printf("%d\t",a[i]);
	printf("\n");
	for(i=5;i>=1;i--)
		min_heapify(a,i);
	for(i=1;i<=10;i++)
		printf("%d\t",a[i]);
}

void max_heapify(int a[],int i)
{
	int l,r,largest,temp;
	l=2*i;
	r=2*i+1;
	if(l<=10 && a[l]>a[i])
		largest=l;
	else
		largest=i;
	if(r<=10 && a[r]>a[largest])
		largest=r;
	if(largest!=i)
	{
		temp=a[i];
		a[i]=a[largest];
		a[largest]=temp;
		max_heapify(a,largest);
	}		
}

void min_heapify(int a[],int i)
{
	int l,r,largest,temp;
	l=2*i;
	r=2*i+1;
	if(l<=10 && a[l]<a[i])
		largest=l;
	else
		largest=i;
	if(r<=10 && a[r]<a[largest])
		largest=r;
	if(largest!=i)
	{
		temp=a[i];
		a[i]=a[largest];
		a[largest]=temp;
		min_heapify(a,largest);
	}		
}