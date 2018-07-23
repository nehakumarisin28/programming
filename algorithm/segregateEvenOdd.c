#include<stdio.h>
#include<stdlib.h>
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
node *segregateEvenOdd(node *head)
{
	
	if(head==NULL)
	return;
	node *heade,*heado,*laste=NULL,*lasto=NULL,*p;
	heade=NULL;
	heado=NULL;
	p=head;
	while(p!=NULL)
	{
		if(p->data%2==0)
		{
			if(heade==NULL)
			{
				heade=p;
				laste=p;
			}
			else
			{
				laste->next=p;
				laste=p;
			}
		}
		else
		{
			if(heado==NULL)
			{
				heado=p;
				lasto=p;
			}
			else
			{
				lasto->next=p;
				lasto=p;
			}
		}
		p=p->next;
	}
	if(heade!=NULL)
	{
	
	head=heade;
	laste->next=heado;
	if(lasto!=NULL)
	lasto->next=NULL;
	}
	else if(heado!=NULL)
	{
	head=heado;
	lasto->next=heade;
	if(laste!=NULL)
	laste->next=NULL;
	}
	
	return head;

}
int main()
{
	node *head1;
	int x;
	head1=NULL;;
	head1=create(head1,2);
	head1=create(head1,3);
	printf("before 	segregation\n");
	print(head1);
	head1=segregateEvenOdd(head1);
	printf("after 	segregation\n");
	print(head1);
	return 0;
}
