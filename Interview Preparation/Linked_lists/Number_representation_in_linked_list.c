#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
};

struct node *head1=NULL,*head2=NULL,*ptr,*curr,*result=NULL;

void traverse(struct node*);
void reverse(struct node*,struct node*,int);
void addition(struct node*,struct node*);

int main()
{
	int number1,number2,d;
	printf("Enter number1 : ");
	scanf("%d",&number1);
	printf("Enter number2 : ");
	scanf("%d",&number2);
	while(number1>0){
		d=number1%10;
		ptr=(struct node*)malloc(sizeof(struct node));
		ptr->data=d;
		ptr->next=NULL;
		if(!head1){
			head1=ptr;
			curr=ptr;
		}else{
			curr->next=ptr;
			curr=ptr;
		}
		number1/=10;
	}
	printf("\n");
	while(number2>0){
		d=number2%10;
		ptr=(struct node*)malloc(sizeof(struct node));
		ptr->data=d;
		ptr->next=NULL;
		if(!head2){
			head2=ptr;
			curr=ptr;
		}else{
			curr->next=ptr;
			curr=ptr;
		}
		number2/=10;
	}
	//traverse(head1);
	printf("\n");
	//traverse(head2);
	//reverse(NULL,head1,1);
	//reverse(NULL,head2,2);
	printf("\n");
	//traverse(head1);
	printf("\n");
	//traverse(head2);
	addition(head1,head2);
	reverse(NULL,result,3);
	printf("\n");
	traverse(result);
	return 0;
}

void addition(struct node *t1,struct node *t2)
{
	int c=0,s;
	while(t1 || t2){
		s=c+t1->data+t2->data;
		c=s/10;
		s=s%10;
		ptr=(struct node*)malloc(sizeof(struct node));
		ptr->data=s;
		ptr->next=NULL;
		if(!result){
			result=ptr;
			curr=ptr;
		}else{
			curr->next=ptr;
			curr=ptr;
		}
		t1=t1->next;
		t2=t2->next;
	}
	if(c>0){
		ptr=(struct node*)malloc(sizeof(struct node));
		ptr->data=c;
		ptr->next=NULL;
		curr->next=ptr;
	}
}

void reverse(struct node *prev,struct node *curr,int p)
{
	if(!curr){
		if(p==1)
			head1=prev;
		else if(p==2)
			head2=prev;
		else
			result=prev;
	}
	else{
		reverse(curr,curr->next,p);
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









