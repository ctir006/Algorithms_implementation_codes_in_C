#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int hash[256]={0};

int main()
{
	char str1[100],str2[100];
	int i;
	printf("Enter string 1: ");
	scanf("%s",str1);
	printf("Enter string 2: ");
	scanf("%s",str2);
	if(strlen(str1)!=strlen(str2)){
		printf("Not anagrams!!!");
		return 0;
	}
	for(i=0;i<strlen(str1);i++)
		hash[str1[i]]++;
	for(i=0;i<strlen(str2);i++)
		hash[str1[i]]--;
	for(i=0;i<256;i++){
		if(hash[i]!=0){
			printf("Not Anagrams!!!");
			return 0;
		}
	}
	printf("Strings are anagrams!!!");
	return 0;
}