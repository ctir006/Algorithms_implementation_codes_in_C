#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void computelps(char pat[],int lps[],int plen)
{
	int index=1,len=0,i;
	lps[0]=0;
	while(index < plen){
		if(pat[index]==pat[len]){
			len++;
			lps[index++]=len;
		}else{
			if(len)
				len=lps[len-1];
			else
				lps[index++]=0;
		}
	}
	for(i=0;i<plen;i++)
		printf("%d\t",lps[i]);
	printf("\n");
}

int main()
{
	char text[100],pat[10];
	int i,j,plen,tlen;
	printf("Enter the text : ");
	scanf("%s",text);
	printf("Enter pattern : ");
	scanf("%s",pat);
	plen=strlen(pat);
	tlen=strlen(text);
	int lps[plen];
	computelps(pat,lps,plen);
	for(i=0,j=0;i<tlen;){
			if(text[i]==pat[j]){
				i++;
				j++;
			}
			if(j==plen){
				printf("Pattern found at the index %d \n",i-j);
				j=lps[j-1];
			}else if(i<tlen && text[i]!=pat[j]){
				if(j)
					j=lps[j-1];
				else
					i++;
			}
	}
	return 0;
}
