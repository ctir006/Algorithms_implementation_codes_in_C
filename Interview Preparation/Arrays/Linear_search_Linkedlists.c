#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
};

struct node *head=NULL,*ptr=NULL,*cur;

void traverse(struct node*);
int linear_search_linkedlist(struct node*,int);

int main()
{
	int d,searchelement;
	printf("Enter 12321 when done!!!\n");
	while(1){
		scanf("%d",&d);
		if(d!=12321){
			ptr=(struct node*)malloc(sizeof(struct node));
			ptr->data=d;
			ptr->next=NULL;
			if(head==NULL){
				cur=ptr;
				head=cur;			
			}else{
				cur->next=ptr;
				cur=ptr;
			}
		}
		else{
			break;
		}
	}
	traverse(head);
	printf("\nEnter element to be searched : ");
	scanf("%d",&searchelement);
	if(linear_search_linkedlist(head,searchelement))
		printf("Element found !!!");
	else
		printf("Element not found !!!");
	return 0;
}

int linear_search_linkedlist(struct node*t,int d)
{
	while(t)
	{
		if(t->data==d)
			return 1;
		t=t->next;
	}
	return 0;
}

void traverse(struct node *t)
{
	while(t)
	{
		printf("%d\t",t->data);
		t=t->next;
	}
}