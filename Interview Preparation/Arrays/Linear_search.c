#include <stdio.h>
#include <stdlib.h>

int linear_search(int*,int,int);

int main()
{
	int n,*a,i,selement;
	printf("How many number of elements: ");
	scanf("%d",&n);
	a=malloc(n*sizeof(int));
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("Enter the element to be searched :");
	scanf("%d",&selement);
	if(linear_search(a,selement,n))
		printf("Element found!!!");
	else
		printf("Element not found!!!");
	return 0;
}

int linear_search(int a[],int selement,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(a[i]==selement)
			return 1;
	}
	return 0;
}