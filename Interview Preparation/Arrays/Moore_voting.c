#include <stdio.h>
#include <stdlib.h>

int main()
{
	int *a,n,i,voter,votes=0,count=0;
	printf("How many elements :");
	scanf("%d",&n);
	a=malloc(n*sizeof(int));
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(i=0;i<n;i++){
		if(votes==0 && a[i]!=voter){
			voter=a[i];
			votes++;
		}else if(voter==a[i]){
			votes++;
		}else{
			votes--;
		}
	}
	for(i=0;i<n;i++){
		if(a[i]==voter)
			count++;
	}
	if(count>=n/2)
		printf("%d is Master number!!!",voter);
	else
		printf("No Master number!!!");
	return 0;
}