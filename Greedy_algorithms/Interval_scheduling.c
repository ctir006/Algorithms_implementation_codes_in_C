#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n,i,a[10][2],j,temp1,temp2,prev;
	printf("How many intervals ? ");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("Enter : ");
		scanf("%d%d",&a[i][0],&a[i][1]);
	}
	for(i=1;i<n;i++){
		temp1=a[i][0];
		temp2=a[i][1];
		j=i-1;
		while(j>=0 && a[j][1]>temp2){
			a[j+1][1]=a[j][1];
			a[j+1][0]=a[j][0];
			j--;
		}
		a[j+1][0]=temp1;
		a[j+1][1]=temp2;
	}
	for(i=0;i<n;i++){
		if(i==0){
			printf("(%d , %d)\n",a[i][0],a[i][1]);
			prev=i;
		}else{
			if(a[prev][1]<a[i][0]){
				printf("(%d , %d)\n",a[i][0],a[i][1]);
				prev=i;
			}
		}
	}
	return 0;
}