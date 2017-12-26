#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int stack[MAX];

int top=-1;
void push(int);
int pop();

int *a,*r;

int main()
{
	int n,i,j=0;
	printf("How many elements ? : ");
	scanf("%d",&n);
	a=malloc(n*sizeof(int));
	r=malloc(n*sizeof(int));
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(i=0;i<n;i++){
		if(top==-1){
			push(a[i]);
		}else if(a[i]>stack[top]){
			r[j++]=a[i];
			pop();
			push(a[i]);
		}else{
			push(a[i]);
		}
	}
	for(;j<n;j++)
		r[j]=-1;
	for(i=0;i<n;i++)
		printf("%d\t",r[i]);
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

int pop()
{
	if(top<0){
		printf("Stack Underflow!!!\n");
		return 0;
	}else{
		printf("Popped element is : %d\n",stack[top]);
		return stack[top--];
	}
}

