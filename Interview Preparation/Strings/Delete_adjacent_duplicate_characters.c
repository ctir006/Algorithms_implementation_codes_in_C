#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* remove_duplicates(char *,int);

int main()
{
	char a[100];
	printf("Enter the string : ");
	scanf("%s",a);
	remove_duplicates(a,strlen(a));
	printf("%s",a);
	return 0;
}

char* remove_duplicates(char *a,int n)
{
	int k=0,i;
	for(i=1;i<n;i++){
		if(a[i-1]!=a[i]){
			a[k++]=a[i-1];
		}else{
			if(a[i-1]==a[i])
				i++;
		}
	}
	a[k++]=a[i-1];
	a[k]='\0';
	if(k!=n)
		return remove_duplicates(a,k);
	return a;
}