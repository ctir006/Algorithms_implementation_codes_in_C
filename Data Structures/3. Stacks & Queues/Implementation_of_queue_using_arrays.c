#include <stdio.h>

#define MAX 4

void enqueue(int);
void dequeue();

int queue[MAX],front=0,rear=0;

int main()
{
	int choice,element;
	while(1)
	{
		printf("Your options\n\tEnqueue-1 \n\tDequeue-2\n\tEND-3\nEnter your choice :");
		scanf("%d",&choice);
		if(choice==3)
			break;
		switch(choice)
		{
			case 1:
				printf("Enter element to enqueue : ");
				scanf("%d",&element);
				enqueue(element);
				break;
			case 2:
				dequeue();
				break;
			default:
				printf("Invalid option!!!");
				break;
		}
	}
	printf("Program ends!!!\n");
	return 0;
}

void enqueue(int data)
{
	rear=(rear+1)%MAX;
	if(front==rear)
	{
		printf("Queue if full!!!\n");
		if(rear==0)
			rear=MAX-1;
		else
			rear=rear-1;
	}
	else{
		queue[rear]=data;
	}
	return NULL;
}

void dequeue()
{
	if(front==rear)
	{
		printf("Queue is empty!!!\n");
	}else{
		front=(front+1)%MAX;
		printf("Dequeue element is :%d\n",queue[front]);
	}
	return NULL;
}