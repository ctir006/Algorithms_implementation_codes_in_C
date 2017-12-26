#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next,*prev;
};

void traverse(struct node*);
void delete(struct node*,int);
struct node *find_middle(struct node*);

struct node *head=NULL,*ptr,*curr;

int main()
{
	int d;
	while(1){
		printf("Enter element (-1 to exit): ");
		scanf("%d",&d);
		if(d==-1)
			break;
		ptr=(struct node*)malloc(sizeof(struct node));
		ptr->data=d;
		ptr->next=NULL;
		if(!head){
			ptr->prev=NULL;
			head=ptr;
			curr=ptr;
		}else{
			ptr->prev=curr;
			curr->next=ptr;
			curr=ptr;
		}
	}
	traverse(head);
	printf("Enter element to delete : ");
	scanf("%d",&d);
	delete(head,d);
	traverse(head);
	printf("Middle element in the list : %d\n",find_middle(head)->data);
	return 0;
}

struct node *find_middle(struct node *t)
{
	ptr=head;
	while(t){
		if(!t->next)
			break;
		t=t->next->next;
		ptr=ptr->next;
	}
	return ptr;
}

void delete(struct node *t,int d)
{
	while(t){
		if(t->data==d){
			if(t==head){
				head=head->next;
				head->prev=NULL;
				free(t);
				break;
			}else if(t->next==NULL){
				t->prev->next=NULL;
				free(t);
				break;
			}else{
				t->prev->next=t->next;
				free(t	);
				break;
			}
		}
		t=t->next;
	}
}

void traverse(struct node *t)
{
	while(t){
		// To print prev element
		/*if(t->prev!=NULL)
			printf("Prev : %d",t->prev->data);*/
		printf("\t%d\n",t->data);
		t=t->next;
	}
}