#include <stdio.h>
#include <stdlib.h>

int hash[256]={0};

int main()
{
	char a[100],max_char;
	int i=0,max_count=0;
	printf("Enter the string : ");
	scanf("%s",a);
	while(a[i]!='\0'){
		hash[a[i]]++;
		if(hash[a[i]]>max_count){
			max_char=a[i];
			max_count=hash[a[i]];
		}
		i++;
	}
	printf("Max occuring character : %c\tcount: %d",max_char,max_count);
	return 0;
}