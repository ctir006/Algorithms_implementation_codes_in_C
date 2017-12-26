#include <stdio.h>
#include <stdlib.h>

int main()
{
	int *a,n,i,j,curr_max=0,s,l;
	printf("How many elements ? ");
	scanf("%d",&n);
	a=malloc(n*sizeof(int));
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if(a[j]>a[i] && (a[j]-a[i])>curr_max){
				s=a[i];l=a[j];
				curr_max=a[j]-a[i];
			}
		}
	}
	printf("%d\t%d\n",s,l);
	return 0;
}