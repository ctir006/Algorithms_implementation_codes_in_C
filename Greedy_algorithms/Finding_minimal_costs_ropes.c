#include <stdio.h>
#include <stdlib.h>

void build_heap(int *);
void min_heapify(int *,int);
int del_min(int*);
void add_item(int*,int);

int n=7;

int main()
{
	int i,ropes[]={0,13,9,2,3,5,7};
	build_heap(ropes);
	int cost=0,temp;
	while(n!=1){
		temp=del_min(ropes)+del_min(ropes);
		printf("%d\t",temp);
		add_item(ropes,temp);
		for(i=1;i<=n;i++)
			printf("%d ",ropes[i]);
		printf("\n");
		/*temp=del_min(ropes)+del_min(ropes);
		cost+=temp;
		printf("%d\t",cost);
		add_item(ropes,cost);*/
	}
	printf("\nThe cost is : %d\n",del_min(ropes));
	return 0;
}

void build_heap(int *a)
{
	int i;
	for(i=n/2;i>=1;i--)
		min_heapify(a,i);
}

void add_item(int *a,int d)
{
	int t,s;
	n++;
	a[n]=d;
	t=n;
	while(t>=1){
		if(a[t/2]>a[t]){
			s=a[t/2];
			a[t/2]=a[t];
			a[t]=s;
		}
		t=t/2;
	}
}

int del_min(int *a)
{
	int min=a[1];
	a[1]=a[n];
	n--;
	min_heapify(a,1);
	return min;
}

void min_heapify(int *a,int i)
{
	int l,r,min,t;
	l=i*2;
	r=i*2+1;
	min=i;
	if(l<=n && a[l]<a[min])
		min=l; 
	if(r<=n && a[r]<a[min])
		min=r;
	if(min!=i){
		t=a[min];
		a[min]=a[i];
		a[i]=t;
		min_heapify(a,min);
	}
}