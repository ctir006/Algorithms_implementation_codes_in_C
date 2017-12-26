#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *left;
	struct node *right;
};

struct node *root=NULL,*ptr;
struct node* insert(struct node*,int);
void traverse(struct node*);

int main()
{
	int i,n,d;
	printf("How many elements ? ");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&d);
		insert(root,d);
	}
	traverse(root);
	return 0;
}

struct node* insert(struct node *r,int d)
{
	if(!r){
		ptr=(struct node*)malloc(sizeof(struct node));
		ptr->data=d;
		ptr->left=ptr->right=NULL;
		if(!root)
			root=ptr;
		return ptr;
	}else if(r->data>d){
		r->left=insert(r->left,d);
	}else{
		r->right=insert(r->right,d);
	}
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


