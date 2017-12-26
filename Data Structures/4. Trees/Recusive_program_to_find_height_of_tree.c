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
struct node* min(struct node*);
struct node* max(struct node*);
int H(struct node*);

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
	printf("\nThe min value is %d\n",min(head)->data);
	printf("\nThe max value is %d\n",max(head)->data);
	printf("\nThe heihgt of the tree is %d\n",H(head));
	return 0;
}
int H(struct node*t)
{
	if(!t) 
		return 0;
	if(!(t->left)&&!(t->right)) 
		return 1;
	int l,r;
	l=H(t->left);
	r=H(t->right);
	printf("%d\t%d\n",l,r);
	return (1+((l>r)?l:r));
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

struct node* min(struct node *t)
{
	if(t==NULL)
		return NULL;
	while(t->left)
		t=t->left;
	return t;
}

struct node* max(struct node *t)
{
	if(t==NULL)
		return NULL;
	while(t->right)
		t=t->right;
	return t;
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