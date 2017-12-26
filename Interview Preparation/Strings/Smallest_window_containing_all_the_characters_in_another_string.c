#include <stdio.h>
#include <string.h>

int hash[265]={0};

int main()
{
	char s1[100],s2[10];
	int i,j,k,curr_min=100,s,e,f;
	printf("Enter string 1 : ");
	scanf("%[^\n]s",s1);
	printf("Enter string 2 : ");
	scanf("%s",s2);
	for(i=0;i<strlen(s2);i++)
		hash[s2[i]]++;
	for(i=0;i<strlen(s1);i++)
		if(hash[s1[i]]!=1)
			s1[i]='_';
	i=0;j=0,f=0;
	while(j<strlen(s1)){
		if(hash[s1[j]]>0 && i==0 && f==0){
			i=j;
			f=1;
		}
		if(hash[s1[j]]>0){
			hash[s1[j]]--;
			k=0;
			for(k=0;k<256;k++){
				if(hash[k]>0){
					k=1;
					break;
				}
			}
			if(k==1){
				j++;
				continue;
			}else{
				if(curr_min>(j-i)){
					s=i;
					e=j;
					printf("Window size id  %d  starting %d ending %d ",e-s,s,e);
				}
				if(hash[s1[i]]<0){
					while(1){
						if(hash[s1[i]]<0 || s1[i]=='_'){
							i++;
							if(s1[i]!='_')
								hash[s1[i]]++;
						}
						else{
							
						}
					}
				}else{
					while(1){
						if(s1[j]==s1[i]){
							break;
						}
						else{
							if(s1[j]!='_')
								hash[s1[j]]--;
							j++;
						}
					}
				}
				continue;
			}
		}
		j++;
	}
	return 0;
}