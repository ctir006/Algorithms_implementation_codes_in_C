#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char a[100],b,c[100];
	int i=0,j=0,k,f=0;
	printf("Enter the string : ");
	scanf("%s",a);
	printf("Enter the checking string : ");
	scanf("%s",c);
	if(strlen(a)!=strlen(c)){
		printf("Match Not Found!!!");
		return 0;
	}
	for(k=0;k<strlen(a);k++){
		for(i=0;i<strlen(a);i++){
			if(i==0)
				b=a[i];
			a[j++]=a[i+1];
		}
		a[--j]=b;
		j=0;
		if(!strcmp(a,c)){
			printf("Match found!!!");
			f=1;
		}
	}
	if(!f)
		printf("Match Not Found!!!");
	return 0;
}
