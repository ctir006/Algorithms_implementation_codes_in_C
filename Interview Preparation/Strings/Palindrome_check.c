#include <stdio.h>
#include <string.h>

int palindrome(char *,int,int);

int main()
{
	char a[100];
	printf("Enter the string to check palindrome : ");
	scanf("%s",a);
	if(palindrome(a,0,strlen(a)-1))
		printf("Given string is palindrome!!!");
	else
		printf("Given string is not palindrome!!!");
	return 0;
}

int palindrome(char *a,int b,int e)
{
	while(b<e){
		if(a[b]!=a[e]){
			return 0;
		}
		else{
			b++;e--;
		}
	}
	return 1;
}