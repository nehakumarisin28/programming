#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node
{
	char data;
	int num;
	struct node *next;
}node;
node *newnode(char data,int num)
{
	node *n=(node*)malloc(sizeof(node));
	n->data=data;
	n->num=num;
	n->next==NULL;
	return n;
}
node *runLength(char *p)
{
	int c=1,j=1;
	node *head,*t;
	while(*p!= '\0')
	{
		
		if(*p == *(p+1))
		{
			c++;
			p++;
		}
		else
		{
			if(j==1)
			{
				j=2;
				t=newnode(*p,c);
				head=t;
			}
			else
			{
				
				
				t->next=newnode(*p,c);
				t=t->next;
				//	printf("%c %d",t->data,t->num);
			}
			c=1;
			p++;
		}
	}
	t->next=NULL;
	return head;
}
void print(node *head)
{
	while(head!=NULL)
	{
		printf("%c %d\n",head->data,head->num);
		head=head->next;
	}
}
int main()
{
	node *head;
	char a[]="geeksforgeeks";
		printf("%s ",a);
	head=runLength(a);
	print(head);
	return 0;
}
