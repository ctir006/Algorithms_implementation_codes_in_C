#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char a[][4]={"0","1","ABC","DEF","GHI","JKL","MNO","PQRS","TUV","WXYZ"};
	char number[10];
	int pos,i;
	printf("Enter the number : ");
	scanf("%s",number);
	for(i=0;i<strlen(number);i++){
		pos=number[i]-'0';
		printf("%s\t",a[pos]);
	}
	return 0;
}


	/*int i,j,k;
	char a[]="ABC";
	char b[]="DEF";
	char c[]="GHI";
	for(i=0;i<strlen(a);i++){
		for(j=0;j<strlen(b);j++){
			for(k=0;k<strlen(c);k++){
				printf("%c %c %c \n",a[i],b[j],c[k]);
			}
		}
	}*/