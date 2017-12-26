#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
};

struct node *head=NULL;
void push(struct node*,int);
int pop(struct node *);

int main()
{
	int choice,d,pe;
	while(1){
		printf("\n1. Push,2. Pop, 3. Exit \n Enter your choice :");
		scanf("%d",&choice);
		if(choice==3)
			break;
		switch(choice){
			case 1:
				printf("Enter element to Push into the stack : ");
				scanf("%d",&d);
				push(head,d);
				break;
			case 2:
				pe=pop(head);
				if(pe==0)
					printf("Stack Underflow!!!");
				else
					printf("Pop element from stack is : %d",pe);
				break;
			default:
				printf("Invalid option!!! Please try again...\n");
		}
	}
	return 0;
}

void push(struct node *t, int d)
{
	struct node *ptr=(struct node*)malloc(sizeof(struct node));
	ptr->data=d;
	ptr->next=NULL;
	if(!head){
		head=ptr;
	}else{
		while(t->next){
			t=t->next;
		}
		t->next=ptr;
	}
}	

int pop(struct node *t)
{
	if(!t){
		return 0;
	}else if(!t->next){
		head=NULL;
		return t->data;
	}else{
		int dat;
		struct node *p;
		while(t->next->next){
			t=t->next;
		}
		p=t->next;
		dat=t->next->data;
		t->next=NULL;
		free(p);
		return dat;
	}
}





