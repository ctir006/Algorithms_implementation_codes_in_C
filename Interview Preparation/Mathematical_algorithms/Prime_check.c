#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	int n,var,f=0,i;
	printf("Enter the number :");
	scanf("%d",&n);
	var=(int)sqrt(n);
	for(i=2;i<=var;i++)
		if(n%i==0)
			f=1;
	if(f==1)
		printf("Number %d is not prime",n);
	else
		printf("Number %d is prime",n);
}