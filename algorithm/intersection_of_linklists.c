#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef struct node
{
	int data;
	struct node *next;
}node;
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
node *create(node *head,int x)
{
	node *n;
	n=(node*)malloc(sizeof(node));
	n->data=x;
	n->next=head;
	head=n;
	return head;
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
int intersection(node *head1,node *head2)
{
	printf("neha\n");
	int c1=0,c2=0,c;
	c1=count(head1);
	c2=count(head2);
	c=0;
	if(c1>c2)
	{
		c=c1-c2;
		c1=0;
		while(c1!=c)
		{
		head1=head1->next;
		c1++;
		}
	}
	else
	{
		c=c2-c1;
		c2=0;
		while(c2!=c)
		{
		head2=head2->next;
		c2++;
		}
	}
	while(head1!=NULL&&head2!=NULL)
	{
		if(head1->data==head2->data)
		return head1->data;
		head1=head1->next;
		head2=head2->next;
	}
	return -1;
}
int main()
{
	node *head1,*head2;
	int x;
	head1=NULL;head2=NULL;
	head1=create(head1,2);
	head1=create(head1,3);
	head1=create(head1,4);
	head1=create(head1,5);
	head1=create(head1,6);
	print(head1);
	head2=create(head2,2);
	head2=create(head2,3);
	head2=create(head2,4);
	head2=create(head2,8);
	print(head2);
	 x=intersection(head1,head2);
	 if(x==-1)
	 printf("there is no intersection node\n");
	 else
	printf("The node of intersection is %d \n",x);
	return 0;
}
