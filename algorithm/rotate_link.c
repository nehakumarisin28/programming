#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *next;
 }node;

node *create(node *head,int x)
{
	node *n;
	n=(node*)malloc(sizeof(node));
	n->data=x;
	n->next=head;
	head=n;
	return head;
}
void print(node *head)
{
	node *p=head;
	while(p!=NULL)
	{
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
}
int count(node *head)
{
	node *p=head;
	int c=0;
	while(p!=NULL)
	{
		c++;
		p=p->next;
	}
	return c;
}
node *rotate(node *head,int k)
{
	int c=count(head);
	node *p=head,*q,*t;
	t=head;
	k=(k%c);
	if(k==0)
	return head;
	c=0;
	while(p->next!=NULL)
	{
		q=p;
		p=p->next;
		c++;
		if(c==k)
		{
		q->next=NULL;
		head=p;
		}
	}
	p->next=t;
	return head;
	
	
}


int main()
{
	node *head;
	int x;
	head=NULL;;
	head=create(head,1);
	head=create(head,2);
	head=create(head,3);
	head=create(head,4);
	head=create(head,5);
	printf("before rotation:\n");
	print(head);
	head=rotate(head,6);
	printf("after rotation:\n");
	print(head);
	
	return 0;
}

