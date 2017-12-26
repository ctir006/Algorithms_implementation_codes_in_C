#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int number,k=0;
	printf("Enter the number : ");
	scanf("%d",&number);
	if(number%26==0 && number/26<26)
		k=1;
	while(number>26){
		if(number==26 || number%26==0)
			printf("%d\t",26);
		else
			printf("%d\t",number%26);
		number/=26;
	}
	if(k==1)
		printf("%d\n",number-1);
	else
		printf("%d\n",number);
	return 0;
}