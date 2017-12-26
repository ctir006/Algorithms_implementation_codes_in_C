#include <stdio.h>
#include <stdlib.h>

struct node 
{
	int data;
	struct node *next;
};

struct node *head=NULL,*ptr=NULL;

void PUSH(int);
void POP();


int main()
{
	int choice,element;
	while(1)
	{
		printf("Your options\n\tPUSH-1 \n\tPOP-2\n\tEND-3\nEnter your choice :");
		scanf("%d",&choice);
		if(choice==3)
			break;
		switch(choice)
		{
			case 1:
				printf("Enter element to push : ");
				scanf("%d",&element);
				PUSH(element);
				break;
			case 2:
				POP();
				break;
			default:
				printf("Invalid option!!!");
				break;
		}
	}
	printf("Program ends!!!\n");
	return 0;
}

void PUSH(int element)
{
	ptr=(struct node*)malloc(sizeof(struct node));
	if(ptr==NULL){
		printf("error of malloc\n");
	}
	else{
		ptr->data=element;
		ptr->next=head;
		head=ptr;
	}
	return NULL;
}

void POP()
{
	if(head==NULL){
		printf("Stack is empty!!!\n");
	}else{
		printf("POP element : %d\n",head->data);
		ptr=head;
		head=head->next;
		free(ptr);
	}
	return NULL;
}