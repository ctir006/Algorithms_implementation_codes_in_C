#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct node *front=NULL,*rear=NULL,*curr,*ptr;

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
	printf("Enter element to enqueue :: ");
	scanf("%d",&d);
	ptr=(struct node*)malloc(sizeof(struct node));
	if(!ptr){
		printf("Memory not available!!!\n");
		return;
	}
	ptr->data=d;
	ptr->next=NULL;
	if(rear==NULL){
		rear=ptr;
		curr=rear;
	}else{
		curr->next=ptr;
		curr=ptr;
	}
	if(!front)
		front=ptr;
}

void dequeue()
{
	if(!front){
		printf("Queue is empty!!!\n");
		return;
	}
	if(front==rear){
		rear=NULL;
	}
	struct node *temp;
	printf("Dequeue element is : %d\n",front->data);
	temp=front;
	front=front->next;
	free(temp);
}




