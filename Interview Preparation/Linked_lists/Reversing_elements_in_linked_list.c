#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct node *head,*ptr,*curr;
void traverse(struct node*);
void reverse(struct node*,struct node*);

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
	printf("Elements in linked list before reverse : ");
	traverse(head);
	reverse(head,NULL);
	printf("\nElements in linked list after reverse : ");
	traverse(head);
	return 0;
}

void reverse(struct node *curr,struct node *prev)
{
	if(!curr){
		head=prev;
		return NULL;
	}
	else{
		reverse(curr->next,curr);
		curr->next=prev;
	}
}

void traverse(struct node *t)
{
	while(t){
		printf("%d\t",t->data);
		t=t->next;
	}
}