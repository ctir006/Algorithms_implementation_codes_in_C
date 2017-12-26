#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
};

void push(struct node*);
void pop(struct node*);

struct node *head=NULL,*ptr;

int main()
{
	int choice;
	printf("Enter 1-Push, 2-Pop, 3-Exit: ");
	while(1){
		scanf("%d",&choice);
		if(choice==3)
			break;
		switch(choice){
			case 1:
				push(head);
				break;
			case 2:
				pop(head);
				break;
			default:
				printf("Invalid input!!! try again\n");
		}
	}
	return 0;
}

void push(struct node *t)
{
	int d;
	printf("Enter the element to push :");
	scanf("%d",&d);
	ptr=(struct node*)malloc(sizeof(struct node));
	ptr->data=d;
	ptr->next=t;
	head=ptr;
	return NULL;
}

void pop(struct node *t)
{
	if(!t){
		printf("Stack underflow!!!");
	}
	else{
		printf("Popped element is %d ",t->data);
		head=t->link;
		free(t);
	}	
}


