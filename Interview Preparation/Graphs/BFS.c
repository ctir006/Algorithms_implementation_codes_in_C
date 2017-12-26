#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 8
int queue[MAX],front=0,rear=0;

void enqueue(int);
int dequeue();

int main()
{
	int i,sp,j,visited[9]={0},a[9][9]={{0},{0,0,1,1,0,0,0,0,0},
				 {0,1,0,0,1,1,0,0,0},
				 {0,1,0,0,0,0,1,1,0},
				 {0,0,1,0,0,0,0,0,1},
				 {0,0,1,0,0,0,0,0,1},
				 {0,0,0,1,0,0,0,0,1},
				 {0,0,0,1,0,0,0,0,1},
				 {0,0,0,0,1,1,1,1,0}};
	printf("Enter the starting point : ");
	scanf("%d",&sp);
	enqueue(sp);
	while(1){
		int curr=dequeue();
		if(curr==-1)
			break;
		if(visited[curr]==1)
			continue;
		visited[curr]=1;
		for(i=1;i<9;i++){
			if(a[curr][i]==1 && visited[i]!=1)
				enqueue(i);
		}
		printf("%d\t",curr);
	}
	return 0;
}

void enqueue(int d)
{
	rear++;
	rear=rear%MAX;
	if(front==rear){
		rear--;
		return;
	}
	else{
		queue[(rear)%MAX]=d;
	}
}

int dequeue()
{
	if(front==rear){
		return -1;
	}
	else{
		front=(front+1)%MAX;
		return queue[front];
	}
}