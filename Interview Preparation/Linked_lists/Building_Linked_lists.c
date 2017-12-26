#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct node *head,*ptr,*curr;
void traverse(struct node*);

int main()
{
	int n,i,d;
	printf("How many elements ? ");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&d);
		ptr=(struct node*)malloc(sizeof(struct node));
		ptr->data=d;
		ptr->next=NULL;
		if(!head){
			head=ptr;
			curr=head;
		}else{
			curr->next=ptr;
			curr=ptr;
		}
	}
	printf("Elements in linked list : ");
	traverse(head);
	return 0;
}

void traverse(struct node *t)
{
	while(t){
		printf("%d\t",t->data);
		t=t->next;
	}
}