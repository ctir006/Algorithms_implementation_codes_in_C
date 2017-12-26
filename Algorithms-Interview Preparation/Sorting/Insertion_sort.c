#include <stdio.h>

int main()
{
	int j,i,key,a[]={9,6,5,0,8,2,7,1,3};
	for(i=1;i<9;i++)
	{
		key=a[i];
		j=i-1;
		while(j>=0 && a[j]>key)
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=key;
	}
	for(i=0;i<9;i++)
		printf("%d\t",a[i]);
	return 0;
}