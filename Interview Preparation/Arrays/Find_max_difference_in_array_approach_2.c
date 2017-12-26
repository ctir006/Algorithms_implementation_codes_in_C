#include <stdio.h>
#include <stdlib.h>

int main()
{
	int *a,n,i,*b,cur_max;
	printf("How many elements ? ");
	scanf("%d",&n);
	a=malloc(n*sizeof(int));
	b=malloc(n*sizeof(int));
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(i=0;i<n-1;i++)
		b[i]=a[i+1]-a[i];
	cur_max=b[0];
	for(i=1;i<n-1;i++){
		if(b[i-1]>0){
			b[i]=b[i]+b[i-1];
			if(b[i]>cur_max)
				cur_max=b[i];
		}
	}
	printf("Grand sum is %d\n",cur_max);
	return 0;
}