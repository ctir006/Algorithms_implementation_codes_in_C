#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int stack[MAX];

int top=-1;
void push(int);
void pop();

int main()
{
	int choice,d;
	while(1){
		printf("Enter 1-Push, 2-Pop, 3-Exit :");
		scanf("%d",&choice);
		if(choice==3)
			break;
		switch(choice){
			case 1:
				printf("Enter element to push :");
				scanf("%d",&d);
				push(d);
				break;
			case 2:
				pop();
				break;
			default:
				printf("Invalid Input!!!\n");
		}
	}
	return 0;
}

void push(int d)
{
	top++;
	if(top>=10){
		printf("Stack Overflow!!!\n");
		top--;
		return;
	}else{
		stack[top]=d;
	}
}

void pop()
{
	if(top<0){
		printf("Stack Underflow!!!\n");
		return;
	}else{
		printf("Popped element is : %d\n",stack[top--]);
	}
}

