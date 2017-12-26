#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

struct node{
	int data;
	struct node *next;
};

void traverse(struct node*);
int cycle_detect(struct node*);

struct node *head=NULL,*ptr,*curr,*temp;

int main()
{
	int i,n,d;
	printf("How many ? ");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("Enter element : ");
		scanf("%d",&d);
		ptr=(struct node*)malloc(sizeof(struct node));
		ptr->data=d;
		ptr->next=NULL;
		if(!head){
			head=ptr;
			curr=ptr;
		}else{
			if(i==4)
				temp=ptr;
			curr->next=ptr;
			curr=ptr;
		}
	}
	ptr->next=temp;
	//traverse(head);
	if(cycle_detect(head)==1)
		printf("Cycle is present!!!");
	else
		printf("Cycle is not present!!!");
	return 0;
}

int cycle_detect(struct node *t)
{
	struct node *s,*f;
	s=f=t;
	while(t){
		if(t->next==NULL)
			return 0;
		t=t->next->next;
		s=s->next;
		if(s==t)
			return 1;
	}
}

void traverse(struct node *t)
{
	while(t){
		printf("%d\t",t->data);
		sleep(1);
		t=t->next;
	}
}