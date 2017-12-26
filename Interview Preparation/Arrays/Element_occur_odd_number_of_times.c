#include <stdio.h>
#include <stdlib.h>

int main()
{
	int *a,n,i,exor_sofar=0;
	printf("How many elements ? ");
	scanf("%d",&n);
	a=malloc(n*sizeof(int));
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(i=0;i<n;i++){
		exor_sofar=exor_sofar^a[i];
		printf("%d\t",exor_sofar);
	}
	printf("\n%d\n",exor_sofar);
	return 0;
}