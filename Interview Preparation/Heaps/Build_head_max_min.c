#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void min_heap(int*,int);
void max_heap(int*,int);
void min_heapify(int*,int,int);
void max_heapify(int*,int,int);
void min_heap_insert(int*,int);

int main()
{
	int *a,i,n;
	char b[10],c[10],d[10];
	printf("How many elements ? ");
	scanf("%d",&n);
	a=malloc(n*sizeof(int));
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	printf("Do you want to build heap (yes/no)??? ");
	scanf("%s",b);
	if(!strcmp(b,"yes")){
		printf("What kind of heap (min/max)? ");
		scanf("%s",c);
		if(!strcmp(c,"min")){
			min_heap(a,n);
			printf("Heap building done!!! \n\t\tDo you want to look at the heap (yes/no)? ");
			scanf("%s",d);
			if(!strcmp(d,"yes")){
				for(i=1;i<=n;i++)
					printf("%d\t",a[i]);
			}else{
				printf("Ok!!!\n");
			}
		}else{
			max_heap(a,n);
			printf("Heap building done!!! \n\t\tDo you want to look at the heap (yes/no)? ");
			scanf("%s",d);
			if(!strcmp(d,"yes")){
				for(i=1;i<=n;i++)
					printf("%d\t",a[i]);
			}else{
				printf("Ok!!!\n");
			}
		}
	}else{
		printf("Ok!!!\n");
	}
	int choice,data;
	while(1){
		printf("\nEnter 1-Insert, 2-Delete min, 3-Exit :");
		scanf("%d",&choice);
		if(choice==3)
			break;
		switch(choice){
			case 1:
				printf("Enter element to insert :");
				scanf("%d",&data);
				n=n+1;
				a[n]=data;
				min_heap_insert(a,n);
				printf("Heap after insertion : ");
				for(i=1;i<=n;i++)
					printf("%d\t",a[i]);
				break;
			case 2:
				if(n==0){
					printf("Heap is empty!!!\n");
					break;
				}
				printf("Minimum element is : %d\n",a[1]);
				a[1]=a[n];
				n=n-1;
				min_heapify(a,n,1);
				printf("Heap after deletion : ");
				for(i=1;i<=n;i++)
					printf("%d\t",a[i]);
				break;
			default:
				printf("Invalid Option!!! try again  \n");
		}
	}
	return 0;
}

void min_heap_insert(int a[],int n)
{
	int temp;
	while((n/2)>=1){
		if(a[n/2]>a[n]){
			temp=a[n/2];
			a[n/2]=a[n];
			a[n]=temp;
			n=n/2;
		}else{
			break;
		}
	}
}

void min_heap(int a[],int n)
{
	int i;
	for(i=n/2;i>=1;i--){
		min_heapify(a,n,i);
	}
}

void max_heap(int a[],int n)
{
	int i;
	for(i=n/2;i>=1;i--){
		max_heapify(a,n,i);
	}
}

void min_heapify(int a[],int n,int k)
{
	int l,r,smallest,temp;
	l=2*k;
	r=2*k+1;
	if(l<=n && a[l]<a[k])
		smallest=l;
	else
		smallest=k;
	if(r<=n && a[smallest]>a[r])
		smallest=r;
	if(smallest!=k){
		temp=a[smallest];
		a[smallest]=a[k];
		a[k]=temp;
		min_heapify(a,n,smallest);
	}
}

void max_heapify(int a[],int n,int k)
{
	int l,r,largest,temp;
	l=2*k;
	r=2*k+1;
	if(l<=n && a[l]>a[k])
		largest=l;
	else
		largest=k;
	if(r<=n && a[largest]<a[r])
		largest=r;
	if(largest!=k){
		temp=a[largest];
		a[largest]=a[k];
		a[k]=temp;
		max_heapify(a,n,largest);
	}	
}
