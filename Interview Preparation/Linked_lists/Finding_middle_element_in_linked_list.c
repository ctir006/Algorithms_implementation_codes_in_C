#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct node *head,*ptr,*curr;
void traverse(struct node*);
void find_middle(struct node*);

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
	printf("\nMiddle element in linked list is : ");
	find_middle(head);
	return 0;
}

void find_middle(struct node *t)
{
	struct node *s,*c,*p;
	c=t;
	int count=1;
	while(t){
		if(count%2==0){
			p=c;
			c=c->next;
		}
		count++;
		t=t->next;
	}
	if(count%2==0)
		printf("%d",c->data);
	else
		printf("%d",p->data);
}

void traverse(struct node *t)
{
	while(t){
		printf("%d\t",t->data);
		t=t->next;
	}
}