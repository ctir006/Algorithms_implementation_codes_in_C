#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
};

void traverse(struct node*);

struct node *head=NULL,*ptr,*curr;

int main()
{
	int d;
	while(1){
		printf("Enter element (-1 to exit): ");
		scanf("%d",&d);
		if(d==-1)
			break;
		ptr=(struct node*)malloc(sizeof(struct node));
		ptr->data=d;
		ptr->next=NULL;
		if(!head){
			head=ptr;
			curr=ptr;
		}else{
			curr->next=ptr;
			curr=ptr;
		}
	}
	traverse(head);
	return 0;
}

void traverse(struct node *t)
{
	while(t){
		printf("%d\t",t->data);
		t=t->next;
	}
}