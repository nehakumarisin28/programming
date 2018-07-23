#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node
{
	char data;
	struct node *next;
}slist;
int c=0;
void chek(char s)
{
	slist *p,*q,*head,*m,*l;
	p=(slist*)malloc(sizeof(slist));
	printf("%s",p->data);
	if(p->data==NULL)
	{
		p->data=s;
		head=p;
		q=p;
		c++;
	}
	else
	{
		p->data=s;
		q->next=p;
		q=p;
		c++;	
	}
	if(c==1)
	printf("pallindrome\n");
	else if(c%2==0)
	{
		m=head;
		l=head;
		while(!c/2+1)
		{
			l=l->next;
		}
		while(m!=NULL&&l!=NULL)
		{
			if(m->data==l->data)
			{
				m=m->next;
				l=l->next;
			}
			else
			{
				printf("not pallindrome\n");
			}
		}
	}
}
int main()
{
	int len,i;
	char n[10];

			printf("enter  string\n");
			scanf("%s",n);
			len=strlen(n);
			printf("neha and lenth %d\n",len);
			for(i=0;i<len;i++)
			chek(n[i]);
		
	return 0;
}
