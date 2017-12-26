#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    /*char  input_string[100];
    scanf("%[^\n]s",&input_string);
    printf("Hello ,world.\n");
    printf("%s",input_string);*/
	char a[100],t[100];
	char *b=malloc(50);
	int i,j=0,l=0,k;
	printf("Enter the string to reverse : ");
	scanf("%[^\n]s",&a);
	for(k=0;k<=strlen(a);k++){
		if(a[k]==' ' || a[k]=='\0'){
			t[l]='\0';
			for(i=strlen(t)-1;i>=0;i--)
				*(b+j++)=t[i];
			*(b+j++)=' ';
			l=0;
		}
		else{	
			t[l++]=a[k];
		}
	}
	*(b+j)='\0';
	for(--j,i=0;j>=0;j--,i++)
		a[i]=*(b+j);
	printf("%s",a);
	return 0;
}