#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void push(int);
int pop();

int stack[MAX],top=-1;

int main()
{
	int i,sp,visited[9]={0},a[9][9]={{0},{0,0,1,1,0,0,0,0,0},
				 {0,1,0,0,1,1,0,0,0},
				 {0,1,0,0,0,0,1,1,0},
				 {0,0,1,0,0,0,0,0,1},
				 {0,0,1,0,0,0,0,0,1},
				 {0,0,0,1,0,0,0,0,1},
				 {0,0,0,1,0,0,0,0,1},
				 {0,0,0,0,1,1,1,1,0}};
	printf("Enter the starting point : ");
	scanf("%d",&sp);
	push(sp);
	while(1){
		int curr=pop();
		if(curr==-1)
			break;
		if(visited[curr]==1)
			continue;
		visited[curr]=1;
		for(i=1;i<9;i++){
			if(a[curr][i]==1 && visited[i]!=1)
				push(i);
		}
		printf("%d\t",curr);
	}
	return 0;
}

void push(int d)
{
	top+=1;
	stack[top]=d;
}

int pop()
{
	if(top==-1)
		return -1;
	int d=stack[top];
	top--;
	return d;
}





