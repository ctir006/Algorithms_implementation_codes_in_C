#include <stdio.h>
#include <stdlib.h>

int main()
{
	int key,i,j,a[]={8,7,6,5,0,4,3,2,1};
	for(i=0;i<9;i++){
		key=a[i];
		j=i-1;
		while(j>=0 && a[j]>key){
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=key;
	}
	for(i=0;i<9;i++)
		printf("%d ",a[i]);
	return 0;
}