#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *next;
}node;
node *newNode(node *head,int x)
{
	node *new=(node*)malloc(sizeof(node));
	new->data=x;
	new->next=head;
	head=new;
	return head;
	
}
void print(node *head)
{
	node *p;
	p=head;
	while(p!=NULL)
	{
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
}
node *reverse(node *head)
{
	node *p,*c,*n;
	p=NULL;
	c=head;
	while(c!=NULL)
	{
		n=c->next;
		c->next=p;
		p=c;
		c=n;
	}
	return p;
}
node *rearrange(node *head)
{
	node *c1,*c2,*p,*q;
	c1=c2=head;
	while(c2!=NULL&&c2->next!=NULL)
	{
		c1=c1->next;
		c2=c2->next->next;
	}
	c2=reverse(c1);
	c1=head;
	while(c2->next!=NULL&&c1->next!=NULL)
	{
	
		p=c1->next;
		q=c2->next;
		c1->next=c2;
		c2->next=p;
		c1=p;
		c2=q;
	}
	return head;
}
int main()
{
	node *head=NULL;
	head = newNode(head,7);
	 head = newNode(head,6);
    head = newNode(head,5);
    head = newNode(head,4);
    head = newNode(head,3);
    head = newNode(head,2);head = newNode(head,1);
    print(head);    
   	head=rearrange(head);      
    print(head);    
    return 0;
}
