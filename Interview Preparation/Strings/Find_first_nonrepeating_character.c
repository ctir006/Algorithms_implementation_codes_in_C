#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
	char data;
	struct node *next,*prev;
};

struct node *head=NULL,*ptr,*temp,*curr;

int hash[256]={0};

int main()
{
	char a[100];
	char t;
	scanf("%s",a);
	int i;
	for(i=0;i<strlen(a);i++){
		t=a[i];
		if(t=='0'){
			break;
		}
		else{
			hash[t]++;
			if(hash[t]==1){
				if(!head){
					ptr=(struct node*)malloc(sizeof(struct node));
					ptr->data=t;
					ptr->prev=ptr->next=NULL;
					head=ptr;
					curr=ptr;
				}else{
					ptr=(struct node*)malloc(sizeof(struct node));
					ptr->data=t;
					ptr->next=NULL;
					ptr->prev=curr;
					curr->next=ptr;
					curr=ptr;
				}
			}
			if(hash[t]==2){
				if(head->data==t && head->next==NULL){
					free(head);
					head=NULL;
				}else if(head->data==t && head->next!=NULL){
					temp=head;
					head=head->next;
					free(temp);
				}
				else{
					temp=head;
					while(temp){
						if(temp->data==t){
							if(!temp->next){
								temp->prev->next=NULL;
								free(temp);
								break;
							}else{
								temp->prev->next=temp->prev;
								free(temp);
								break;
							}
						}
						temp=temp->next;
					}
				}
			}
		}
		printf("\nFirst non repreating character : %c\n",head->data);
	}
	return 0;
}