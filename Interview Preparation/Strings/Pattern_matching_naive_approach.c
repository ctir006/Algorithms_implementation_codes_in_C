#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char str1[100],str2[10];
	int i,j;
	printf("String 1? : ");
	scanf("%s",str1);
	printf("String 2? : ");
	scanf("%s",str2);
	for(i=0;i<strlen(str1)-strlen(str2)+1;i++){
		if(str1[i]==str2[0]){
			for(j=0;j<strlen(str2);j++){
				if(str1[i+j]!=str2[j])
					break;
			}
			if(j==strlen(str2))
				printf("Match Found at starting %d !!!\n",i);
		}
	}
	return 0;
}