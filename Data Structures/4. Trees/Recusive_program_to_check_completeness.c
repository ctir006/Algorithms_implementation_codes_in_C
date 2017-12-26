#include <stdio.h>
#include <stdlib.h>

struct node 
{
	int data;
	struct node *left,*right;
};

void traverse(struct node*);
struct node* insert(struct node*, int);
struct node* newElement(int);
int isComplete(struct node*);

struct node *head;

int main()
{
	int d,f=0;
	while(1)
	{
		printf("Enter 0 to exit : ");
		scanf("%d",&d);
		if(d==0)
			break;
		if(f++==0)
			head=insert(NULL,d);
		else
			insert(head,d);
	}
	traverse(head);
	if(isComplete(head))
		printf("\nTree is complete");
	else
		printf("\nTree is not complete");
	return 0;
}

int isComplete(struct node *t)
{
	if(t==NULL)
		return 1;
	if(t->left==NULL && t->right==NULL)
		return 1;
	else if(t->left &&  t->right)
		return isComplete(t->left) && isComplete(t->right);
	else
		return 0;
}

struct node* insert(struct node* t,int d)
{
		if(t==NULL)
		{
			return newElement(d);
		}
		else if(t->data > d)
		{
			t->left=insert(t->left,d);
		}else
		{
			t->right=insert(t->right,d);
		}
}


struct node* newElement(int d)
{
	struct node *ptr=(struct node*)malloc(sizeof(struct node));
	ptr->data=d;
	ptr->left=ptr->right=NULL;
	return ptr;
}

void traverse(struct node *t)
{
	if(t)
	{
		traverse(t->left);
		printf("%d\t",t->data);
		traverse(t->right);
	}
}