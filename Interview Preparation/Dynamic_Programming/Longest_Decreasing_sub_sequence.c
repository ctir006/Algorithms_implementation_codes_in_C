#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n,*a,i,*b,j;
	printf("Enter number of elements in array : ");
	scanf("%d",&n);
	a=(int*)malloc(sizeof(int)*n);
	b=(int*)malloc(sizeof(int)*n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(i=n-1;i>=0;i--)
	{
		j=i;
		b[i]=1;
		while(j<=n-1)
		{
			if(a[j]>a[i])
			{
				if(b[i]<b[j]+1)
					b[i]=b[j]+1;
			}
			j++;
		}
	}
	for(i=0;i<n;i++)
		printf("%d\t",b[i]);
	return 0;
}