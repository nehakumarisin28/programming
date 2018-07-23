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

void sort(node *head)
{
	int c[3]={0,0,0};
	node *p;
	p=head;
	while(p!=NULL)
	{
		c[p->data]+=1;
		p=p->next;
	}
	p=head;
	int i=0;
	while(p!=NULL)
	{
		if(c[i]==0)
		i++;
		else
		{
		p->data=i;
		c[i]=c[i]-1;
		p=p->next;
		}
	
	}
}

int main()
{
	node *head;
	int x;
	head=NULL;;
	head=create(head,0);
	head=create(head,1);
	head=create(head,0);
	head=create(head,2);
	head=create(head,1);
	head=create(head,2);
	head=create(head,2);
	head=create(head,0);
	printf("before sorting:\n");
	print(head);
	sort(head);
	printf("after sorting:\n");
	print(head);
	
	return 0;
}

