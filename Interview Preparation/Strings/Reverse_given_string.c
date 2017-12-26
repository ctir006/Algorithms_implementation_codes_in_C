#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char *,int,int);

int main()
{
	char a[100];
	printf("Enter the string to be reversed : ");
	scanf("%[^\n]s",a);
	reverse(a,0,strlen(a)-1);
	printf("%s",a);
	return 0;
}

void reverse(char *a,int b,int e)
{
	char t;
	while(b<e){
		t=a[b];
		a[b]=a[e];
		a[e]=t;
		b++;
		e--;
	}
}