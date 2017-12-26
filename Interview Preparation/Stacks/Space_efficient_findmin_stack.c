#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int stack[MAX];

int top=-1,curr_min=-1;

void push();
void pop();
void min();

int main()
{
	int choice;
	while(1){
		printf("Enter 1-Push, 2-Pop, 3-Min, 4-Exit :");
		scanf("%d",&choice);
		if(choice==4)
			break;
		switch(choice){
			case 1:
				push();
				break;
			case 2:
				pop();
				break;
			case 3:
				min();
				break;
			default:
				printf("Invalid Option!!! try again\n");
		}
	}
	return 0;
}

void push()
{
	int d;
	printf("Enter the element to Push : ");
	scanf("%d",&d);
	top++;
	if(top<MAX){
		if(top==0){
			stack[top]=d;
			curr_min=d;
		}
		else if(d<curr_min){
			stack[top]=d-curr_min;
			curr_min=d;
		}else{
			stack[top]=d;
		}
	}else{
		top--;
		printf("Stack Overflow!!!\n");
	}
}

void pop()
{
	if(stack[top]>curr_min){
		printf("Popped element is : %d\n",stack[top]);
		top--;
	}else if(top>=0 && stack[top]<curr_min){
		printf("Popped element is : %d\n",curr_min);
		curr_min=curr_min-stack[top];
		top--;
	}else if(stack[top]==curr_min){
		printf("Popped element is : %d\n",curr_min);
		top--;
	}
	else{
		printf("Stack Underflow!!!\n");
	}
}

void min()
{
	if(top==-1)
		printf("Stack is empty !!!\n");
	else
		printf("Min value in the stack is : %d\n",curr_min);
}






