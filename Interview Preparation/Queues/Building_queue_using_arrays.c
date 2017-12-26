#include <stdio.h>
#include <stdio.h>

#define MAX 5

int queue[MAX];
int front=0,rear=0;

void enqueue();
void dequeue();

int main()
{
	int choice;
	while(1){
		printf("Enter 1-Enqueue, 2-Dequeue, 3-Exit :");
		scanf("%d",&choice);
		if(choice==3)
			break;
		switch(choice){
			case 1:
				enqueue();
				break;
			case 2:
				dequeue();
				break;
			default:
				printf("Invalid Option!!! try again\n");
		}
	}
	return 0;
}

void enqueue()
{
	int d;
	rear++;
	if(rear%MAX==front){
		printf("Queue is full !!!\n");
		rear--;
	}else{
		printf("Enter element : ");
		scanf("%d",&d);
		queue[rear]=d;
	}
}

void dequeue()
{
	if(front==rear){
		printf("Queue is empty!!!\n");
	}else{
		printf("Dequeue element is : %d\n",queue[++front]);
	}
}







