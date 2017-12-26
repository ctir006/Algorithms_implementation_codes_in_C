#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *left,*right;
};

struct node* insert(struct node*,int);
struct node* newElement(struct node*,int);
void traverse(struct node*);
struct node *delete(struct node*,int);
struct node *minVelue(struct node*);
struct node *delete1(struct node*,int);
struct node *minValue1(struct node*);

int main()
{
	int i,n,dat,del;
	printf("Enter Number of Elements :");
	scanf("%d",&n);
	struct node *root;
	for(i=0;i<n;i++)
	{
		printf("Enter element %d :",i);
		scanf("%d",&dat);
		if(i==0)
		{
			root=insert(NULL,dat);
		}else
		{
			insert(root,dat);
		}
	}
	traverse(root);
	printf("Enter the number you want to delete: ");
	scanf("%d",&del);
	//root=delete(root,del);
	root=delete1(root,del);
	traverse(root);
	return 0;
}
struct node *minValue1(struct node* t)
{
	while(t->left!=NULL)
		t=t->left;
	return t;
		
}
struct node *delete1(struct node *t,int del)
{
	if(t==NULL)
	{
		return t;
	}else if(t->data > del)
	{
		t->left=delete1(t->left,del);
	}else if(t->data <del)
	{
		t->right=delete1(t->right,del);
	}else
	{
		if(t->left==NULL)
		{
			struct node *temp=t->right;
			free(t);
			return temp;
		}else if(t->right==NULL)
		{
			struct node *temp=t->left;
			free(t);
			return temp;
		}
		struct node *temp=minValue1(t->right);
		t->data=temp->data;
		t->right=delete1(t->right,temp->data);
	}
}
struct node *minVelue(struct node *t)
{
	struct node *curr=t;
	while(curr->left!=NULL)
		curr=curr->left;
	return curr;
}
struct node *delete(struct node *t,int del)
{
		if(t==NULL)
		{
			return t;
		}
		if(t->data > del)
		{
			t->left=delete(t->left,del);
		}
		else if(t->data < del)
		{
			t->right = delete(t->right,del);
		}
		else
		{
			if(t->left == NULL)
			{
				struct node *temp=t->right;
				free(t);
				return temp;
			}
			else if(t->right == NULL)
			{
				struct node *temp=t->left;
				free(t);
				return temp;
			}
			struct node *temp=minVelue(t->right);
			t->data=temp->data;
			t->right=delete(t->right,temp->data);
		}
}
void traverse(struct node *t)
{
	if(t==NULL)
	{
		return NULL;
	}
	else
	{
		traverse(t->left);
		printf("%d\n",t->data);
		traverse(t->right);
	}
}

struct node * insert(struct node *t,int d)
{
	if(t==NULL)
		return newElement(t,d);
	else if(t->data > d)
		t->left = insert(t->left,d);
	else
		t->right = insert(t->right,d);
}

struct node *newElement(struct node *t,int d)
{
	struct node *ptr;
	ptr=(struct node*)malloc(sizeof(struct node));
	ptr->left=NULL;ptr->right=NULL;
	ptr->data=d;
	return ptr;
}