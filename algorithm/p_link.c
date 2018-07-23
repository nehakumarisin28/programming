#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node
{
	 int data;
	 struct node *next;
}node;

node* insert(node *head,int x)
{
	node *p,*q;
	p=(node*)malloc(sizeof(node));
	p->data=x;
	if(head==NULL)
	{
	p->next=NULL;
	head=p;
	}
	else
	{
		q=head;
		while(q->next!=NULL)
		{
			q=q->next;
		}
		q->next=p;
		p->next=NULL;
	}
	return head;
}

void print(node *head)
{
	node *p;
	p=head;
	if(p==NULL)
	{
		printf("empty list\n");
		return;
	}
	while(p!=NULL)
	{
		printf("%d  ",p->data);
		p=p->next;
	}
	printf("\n");
}
node* reverse(node* head)
{
	node *c,*n,*p;
	p=NULL;
	c=head;
	while(c!=NULL)
	{
		n=c->next;
		c->next=p;
		p=c;
		c=n;
	}
	head=p;
	return head;
}
int number(node *head)
{
	int num=0;
	node *p=head;
	while(p!=NULL)
	{
		p=p->next;
		num++;
	}
	return num;
}
int nth_node(node* head,int n)
{
	int num=number(head);
	if(n>num)
	{
		printf("nth number is greater than total number\n");
		//return;
	}
	else
	{
	
	int i=1;
	node *p;
	p=head;
	while(i!=n)
	{
		p=p->next;
		i++;
	}
	return p->data;
	}
}
node *delete_first(node *head)
{
	if(head!=NULL)
	{
		node *temp=head;
		head=head->next;
		free(temp);
	}
	return head;
}
int nth_from_last(node *head,int n)
{
	int n1=number(head);
	node *p;
	p=head;
	n=(n1-n+1);
	n=1;
	while(n!=n1)
	{
		p=p->next;
		n++;
	}
	return p->data;
	
}
int main()
{
	node *head=NULL;
	int x,ch,n;
	for(;;)
	{
		printf("1:create list\t2:print\t3:reverse\t4:nth_node\t5:delete_first_node\t6:nth_node_from_last\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("enter data\n");
				scanf("%d",&x);
				head=insert(head,x);
				break;
			case 2:
				print(head);
				break;
			case 3:
				head=reverse(head);
				break;
			case 4:
				printf("enter n_th number\n");
				scanf("%d",&n);
				x=nth_node(head,n);
				printf("%d\n",x);
			case 5:
				head=delete_first(head);
				break;
			case 6:
				printf("enter the nth number\n");
				scanf("%d",&n);
				x=nth_from_last(head,n);
				printf("%d is nth node from last\n",x);
				break;
				
		}
	}
}
