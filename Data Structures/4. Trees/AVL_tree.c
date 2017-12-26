#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *left;
	struct node *right;
	int height;
};

struct node *insertAVL(struct node*,int);
struct node *newElement(struct node*,int);
void traverse(struct node*);
int max(int,int);
int heightAVL(struct node*);
int getBalance(struct node*);

int heightAVL(struct node *t)
{
	if(t==NULL)
		return 0;
	return t->height;
}

int getBalance(struct node *t)
{
	if(t==NULL)
		return 0;
	return heightAVL(t->left)-heightAVL(t->right);
}

int max(int a,int b)
{
	if(a>b)
		return a;
	else
		return b;
}

struct node *insertAVL(struct node *t,int d)
{
	if(t==NULL)
		return newElement(t,d);
	else if(t->data > d)
		t->left=insertAVL(t->left,d);
	else if(t->data <d)
		t->right=insertAVL(t->right,d);
	else
		return t;
	t->height=1+max(heightAVL(t->left),heightAVL(t->right));
	int balance=getBalance(t);
	if(balance>1&&d<t->left->data)
		return rightRotate(t);
	if(balance<-1&&d>t->left->data)
		return leftRotate(t);
	if(balance >1 && d > t->left->data)
	{
		t->left=leftRotate(t->left);
		return rightRotate(t);
	}
	if(balance<-1 && d<t->right->data)
	{
		t->right=rightRotate(t->right);
		return leftRotate(t);
	}
	return t;
}

struct node *newElement(struct node *t,int d)
{
	struct node *ptr = (struct node*)malloc(sizeof(struct node));
	ptr->data=d;
	ptr->left=NULL;
	ptr->right=NULL;
	ptr->height=0;
	return ptr;
}

void traverse(struct node *t)
{
	if(t!=NULL)
	{
		traverse(t->left);
		printf("%d\n",t->data);
		traverse(t->right);
	}
}

int main()
{
	int i,n,d;
	printf("Enter Number of elements :");
	scanf("%d",&n);
	struct node *root=NULL;
	for(i=0;i<n;i++)
	{
		printf("Enter element %d :",i+1);
		scanf("%d",&d);
		if(root==NULL)
		{
			root=insertAVL(root,d);
		}else
		{
			insertAVL(root,d);
		}
	}
	traverse(root);
	return 0;
}