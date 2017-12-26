#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *left,*right;
};

struct node *insert(struct node*,int);
struct node *root=NULL,*ptr;
struct node *new_node(int);
void traverse(struct node*);
struct node *inorder_successor(struct node*);
struct node *inorder_predecessor(struct node*);
int number_of_nodes(struct node*);
struct node *delete(struct node*,int);
int number_of_leafs(struct node*);

int main()
{
	int n,i,d;
	printf("How many elements ? ");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&d);
		if(i==0){
			root=insert(NULL,d);
		}else{
			insert(root,d);
		}
	}
	printf("Minimum element in the tree is  : %d\n",inorder_successor(root)->data);
	printf("Maximum element in the tree is  : %d\n",inorder_predecessor(root)->data);
	printf("Numebr of nodes in the tree : %d\n",number_of_nodes(root));
	printf("Numenr of leafs : %d\n",number_of_leafs(root));
	printf("Enter the element you want to delete : ");
	scanf("%d",&d);
	delete(root,d);
	traverse(root);
	return 0;
}

int number_of_leafs(struct node *t)
{
	if(!t)
		return 0;
	if(t->left==NULL && t->right==NULL)
		return 1;
	else 
		return number_of_leafs(t->left)+number_of_leafs(t->right);;
}

struct node *delete(struct node *t,int d)
{
	if(!t){
		return t;
	}
	else if(t->data>d){
		t->left=delete(t->left,d);
	}
	else if(t->data<d){
		t->right=delete(t->right,d);
	}
	else{
		if(t->left==NULL){
			struct node *temp=t->right;
			free(t);
			t=temp;
		}else if(t->right=NULL){
			struct node *temp=t->left;
			free(t);
			t=temp;
		}
		struct node *temp=inorder_successor(t->right);
		t->data=temp->data;
		t->right=delete(t->right,temp->data);
	}
	return t;
}

int number_of_nodes(struct node *t)
{
	if(t){
		int l,r;
		l=number_of_nodes(t->left);
		r=number_of_nodes(t->right);
		return 1+l+r;
	}else{
		return 0;
	}
}

void traverse(struct node *t)
{
	if(t){
		traverse(t->left);
		printf("%d\t",t->data);
		traverse(t->right);
	}
}

struct node *inorder_predecessor(struct node *t)
{
	while(t->right)
		t=t->right;
	return t;
}

struct node *inorder_successor(struct node *t)
{
	while(t->left)
		t=t->left;
	return t;
}

struct node *insert(struct node *t,int d)
{
	if(!t)
		return new_node(d);
	else if(t->data>d)
		t->left=insert(t->left,d);
	else
		t->right=insert(t->right,d);
}

struct node *new_node(int d)
{
	ptr=(struct node*)malloc(sizeof(struct node));
	ptr->data=d;
	ptr->left=ptr->right=NULL;
	return ptr;
}