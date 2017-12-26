#include <stdio.h>
#include <stdlib.h>

int main()
{
	int *a,n,i,s,l,min_sofar,max_diff_sofar=0;
	printf("How many elements ? ");
	scanf("%d",&n);
	a=malloc(n*sizeof(int));
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	min_sofar=a[0];
	for(i=1;i<n;i++){
		if(a[i]>min_sofar){
			if((a[i]-min_sofar)>max_diff_sofar){
				max_diff_sofar=a[i]-min_sofar;
				l=a[i];
				s=min_sofar;
			}
		}else{
			min_sofar=a[i];
		}
	}
	printf("Max difference is %d in between %d %d ",max_diff_sofar,s,l);
	return 0;
}