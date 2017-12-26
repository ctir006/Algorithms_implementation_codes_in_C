#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int stack[MAX];

int top=-1;
void push(int);
void pop();
void reverse();
int pop_reverse();
void insertatbottom();

int main()
{
	int choice,d;
	while(1){
		printf("Enter 1-Push, 2-Pop, 3-Reverse, 4-Exit :");
		scanf("%d",&choice);
		if(choice==4)
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
			case 3:
				reverse();
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
int pop_reverse()
{
	if(top<0){
		return 0;
	}else{
		return stack[top--];
	}
}

void reverse()
{
	if(top==-1)
		return;
	int ele=pop_reverse();
	reverse();
	insertatbottom(ele);
}

void insertatbottom(int item){
	if(top==-1){
		push(item);
	}
	else{
		int topitem=pop_reverse();
		insertatbottom(item);
		push(topitem);
	}
}










