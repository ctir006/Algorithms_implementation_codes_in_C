#include <stdio.h>

int search(int *,int,int,int);

int main()
{
	int a[]={0,1,2,3,4,5,6,7,8,9};
	int f=0,se;
	printf("Enter element to search ::");
	scanf("%d",&se);
	f=search(a,0,9,se);
	if(f==1)
		printf("found!");
	else
		printf("not found!");
	return 0;
}

int search(int a[],int start,int end,int selement)
{
	if(start<=end)
	{
		int mid=(start+end)/2;
		if(a[mid]==selement)
		{
			return 1;
		}
		else
		{
			if(a[mid]>selement)
				return search(a,start,mid-1,selement);
			else
				return search(a,mid+1,end,selement);
		}
	}
	return -1;
}

