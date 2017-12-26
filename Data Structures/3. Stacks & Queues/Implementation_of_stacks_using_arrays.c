#include <stdio.h>

#define MAX 100

void PUSH(int);
void POP();

int stack[MAX],top=-1;

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

void PUSH(int data)
{
	if(top>=MAX-1)
		printf("Stack Overflow!!!\n");
	else
		stack[++top]=data;
	return NULL;
}

void POP()
{
	
	if(top<=-1)
		printf("Stack is empty!!!\n");
	else
		printf("POP element is : %d\n",stack[top--]);
	return NULL;
}