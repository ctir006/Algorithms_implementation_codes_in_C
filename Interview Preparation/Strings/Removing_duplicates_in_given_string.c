#include <stdio.h>
#include <stdlib.h>

int hash[256]={0};

int main()
{
	char a[100];
	int k=0,i=0;
	printf("Chitti Enter the string : ");
	scanf("%s",a);
	while(a[k]!='\0'){
		if(!hash[a[k]]){
			a[i++]=a[k];
			hash[a[k]]++;
		}
		k++;
	}
	a[i]='\0';
	printf("String after removing duplicates : %s",a);
	return 0;
}