#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int queue1[MAX];
int queue2[MAX];

int f1=0,f2=0,r1=0,r2=0;

void push();
void pop();
void enqueue(int*,int*,int*,int);
int dequeue(int*,int*,int*);
void pdequeue(int*,int*,int*);

int main()
{
	int choice;
	while(1){
		printf("Enter 1-Push, 2-Pop, 3-Exit :");
		scanf("%d",&choice);
		if(choice==3)
			break;
		switch(choice){
			case 1:
				push();
				break;
			case 2:
				pop();
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
	printf("Enter element to push :");
	scanf("%d",&d);
	if(f1==r1){
		enqueue(queue1,&f1,&r1,d);
		while(queue2[f2]!=0){
			enqueue(queue1,&f1,&r1,dequeue(queue2,&f2,&r2));
		}
	}else{
		enqueue(queue2,&f2,&r2,d);
		while(queue1[f1]!=0){
			enqueue(queue2,&f2,&r2,dequeue(queue1,&f1,&r1));
		}
	}
}

void pop()
{
	if(f1==r1){
		pdequeue(queue2,&f2,&r2);
	}else{
		pdequeue(queue1,&f1,&r1);
	}
}

void pdequeue(int queue[],int *front,int *rear)
{
	if(*front%MAX==*rear%MAX){
		printf("Stack is empty!!!\n");
	}else{
		(*front)++;
		printf("Popped element is : %d\n",queue[*front]);
		queue[*front]=0;
	}
}

void enqueue(int queue[],int *front,int *rear,int data)
{
	(*rear)++;
	if((*rear)%MAX==*front){
		printf("Stack is full!!!\n");
		(*rear)--;
		return;
	}else{
		queue[*rear]=data;
	}
}

int dequeue(int queue[],int *front,int *rear)
{
	int d;
	if(*front==*rear){
		printf("Stack is empty!!!\n");
	}else{
		d=queue[++(*front)];
		queue[*front]=0;
		return d;
	}
}








