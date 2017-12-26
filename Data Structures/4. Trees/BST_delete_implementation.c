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
struct node* delete(struct node*,int);

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
	printf("\nEnter element to delete :");
	scanf("%d",&d);
	if(delete(head,d))
		printf("Element found!!!\n");
	else
		printf("Element not found!!!\n");
	traverse(head);
	return 0;
}

struct node* delete(struct node *t,int d)
{
	if(t==NULL){
		return t;
	}
	else if(t->data > d){
		t->left=delete(t->left,d);
	}else if(t->data <d){
		t->right=delete(t->right,d);
	}else{
		if(t->left == NULL && t->right==NULL)
		{
			free(t);
			t=NULL;
		}else if(t->left==NULL){
			struct node*temp=t;
			t=t->right;
			free(temp);
		}else if(t->right==NULL){
			struct node*temp=t;
			t=t->left;
			free(temp);
		}else{
			struct node *temp=min(t);
			t->data=temp->data;
			t->right=delete(t->right,temp->data);
		}
	}
	return t;
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