#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int stack1[MAX];
int stack2[MAX];

int top1=-1,top2=-1;

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
	printf("Enter element to Push :");
	scanf("%d",&d);
	top1++;
	if(top1<MAX){
		stack1[top1]=d;
		if(top2==-1)
			stack2[++top2]=d;
		else if(stack2[top2]>=d)
			stack2[++top2]=d;
	}else{
		printf("Stack Overflow!!!\n");
	}
}

void pop()
{
	if(top1<0){
		printf("Stack Underflow!!!\n");
	}else{
		printf("Popped element is : %d\n",stack1[top1--]);
		if(stack1[top1+1]==stack2[top2])
			top2--;
	}
}

void min()
{
	if(top2!=-1)
		printf("Minimum value in the stack is : %d\n",stack2[top2]);
	else	
		printf("No elements in the stack !!!\n");
}











