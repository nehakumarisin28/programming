#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *next;
}node;
void del_left(node *head)
{
	int max=head->data;
	node *q,*p=head;
	q=p;
	while(q!=NULL)
	{
		if(max>q->data)
		{
		p->next=q->next;
		}
		else
		{
			max=q->data;
			p=q;
		}
		q=q->next;
	}
	
}
node *revers(node *head)
{
	node *n,*c,*prev;
	prev=NULL;
	c=head;
	while(c!=NULL)
	{
		n=c->next;
		c->next=prev;
		prev=c;
		c=n;
	}
	head=prev;
//	print(head);
	return prev;
}
node *delete_left(node *head)
{
	head=revers(head);
	del_left(head);
	head=revers(head);
	return head;
}
node *push(node *head,int x)
{
	node *n=(node*)malloc(sizeof(node));
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
}
int main()
{
	node *head=NULL;
	 head=push(head,3);
     head=push(head,2);
     head=push(head,6);
     head=push(head,5);
     head=push(head,11);
     head=push(head,10);
     head=push(head,15);
     head=push(head,12);
      head=push(head,13);
     printf("before modification:");
     print(head);
     head=delete_left(head);
      printf("\nafter modification:");
    print(head);
    return 0;
     
}
