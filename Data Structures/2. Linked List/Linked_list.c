#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
};

struct node *ptr=NULL,*head=NULL,*cur=NULL;

void traverse(struct node*);
void insert(struct node*);
void delete(struct node*);
void recursive_traverse(struct node*);
void reverse_linked_list(struct node*,struct node*);

int main()
{
	int num,choice;
	while(1)
	{
		printf("Enter number (0 to quit/print values): ");
		scanf("%d",&num);
		if(num==0)
		{
			printf("List elements in reverse order...\n");
			recursive_traverse(head);
			printf("Normal order list of elements\n");
			reverse_linked_list(NULL,head);
			traverse(head);
			printf("Linked list creation has been done. \nEnter your choice of operation.");
			printf("To insert 1 to delete 2 : ");
			scanf("%d",&choice);
			if(choice==1)
			{
				insert(head);
				traverse(head);
			}else if(choice==2)
			{
				delete(head);
				traverse(head);
			}
			break;
		}else
		{
			ptr=(struct node*)malloc(sizeof(struct node));
			if(ptr==NULL)
			{
				printf("Couldn't allocate the memory");
				break;
			}
			if(head==NULL)
			{
				ptr->data=num;
				ptr->next=cur;
				head=ptr;
				cur=head;
			}else
			{
				ptr->data=num;
				ptr->next=NULL;
				cur->next=ptr;
				cur=ptr;
			}	
		}	
	}
	return 0;
}
void recursive_traverse(struct node *t)
{
	if(t==NULL)
	{
		return;
	}
	else
	{
		recursive_traverse(t->next);
		printf("%d\n",t->data);
	}
}
void reverse_linked_list(struct node *p,struct node *c)
{
	if(c)
	{
		reverse_linked_list(c,c->next);
		c->next=p;
	}
	else
	{
		head=p;
	}
}
void traverse(struct node *t)
{
	while(t)
	{
		printf("%d\n",t->data);
		t=t->next;
	}
}
void insert(struct node *t)
{
		int num,choice,element;
		struct node *temp;
		printf("Press 1 to insert starting 2 to at the end 3 to in middle :");
		scanf("%d",&choice);
		printf("Enter the number to insert : ");
		scanf("%d",&num);
		ptr=(struct node*)malloc(sizeof(struct node));
		ptr->data=num;
		if(choice!=1 && choice!=2 && choice!=3)
		{
			printf("Invalid option\n");
			return NULL;
		}
		switch(choice)
		{
			case 1:
				ptr->next=head;
				head=ptr;
				printf("Operation done... Your new list is as below \n");
				break;
			case 2:
				while(t->next)
				{
					t=t->next;
				}
				ptr->next=NULL;
				t->next=ptr;
				printf("Operation done... Your new list is as below \n");
				break;
			default:
				printf("Enter after which element to insert :");
				scanf("%d",&element);
				while(t->data!=element)
				{
					t=t->next;
				}
				temp=t->next;
				t->next=ptr;
				ptr->next=temp;
				printf("Operation done... Your new list is as below \n");
				break;
		}
}
void delete(struct node *t)
{
	int num;
	struct node *temp;
	printf("Enter the element you want to delete :");
	scanf("%d",&num);
	while(t)
	{
		if(t->next->data==num)
		{
			temp=t->next;
			t->next=t->next->next;
			free(temp);
			printf("Operation done...\n");
			break;
		}
		t=t->next;
	}
	return NULL;
}