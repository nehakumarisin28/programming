#include<stdio.h>
typedef struct q
{
	int front;
	int rear;
}q;
int isFull(q fr,int n)
{
	return ((fr.front==0&&fr.rear==(n-1))||(fr.front==(fr.rear+1)));

}
int isEmpty(q fr)
{
	return (fr.front==-1||fr.rear==-1);
 } 
q insert_front(q fr,int a[],int n)
{
	int x;
	if((isFull(fr,n)))
	{
		printf("queue is full\n");
	}
	else
	{
	
	printf("element to enter\n");
	scanf("%d",&x);
	if(fr.front==0)
	fr.front=n-1;
	else if(fr.front==-1)
	{
	fr.front= fr.rear=0;
	}
	else
	fr.front--;
	a[fr.front]=x;
}
	return fr;
}
q insert_rear(q fr,int a[],int n)
{
	int x;
	if((isFull(fr,n)))
	{
		printf("queue is full\n");
	}
	else
	{
	printf("element to enter\n");
	scanf("%d",&x);
	if(fr.rear==(n-1))
	fr.rear=0;
	if(fr.rear==-1)
	{
		fr.rear=fr.front=0;
	}
	else fr.rear++;
	a[fr.rear]=x;
}
	return fr;
}
q delete_front(q fr,int a[],int n)
{
	if(isEmpty(fr))
	{
		printf("queue is empty\n");
		printf("%d %d\n",fr.front,fr.rear);
	}
	else
	{
	
	if(fr.front==fr.rear)
	{
	fr.front=-1;
	fr.rear=-1;
	}
	else	if(fr.front==(n-1))
	fr.front=0;
	else
	fr.front++;
}
	return fr;
}
q delete_rear(q fr,int a[],int n)
{
		printf("%d %d\n",fr.front,fr.rear);
	if(isEmpty(fr))
	{
			printf("queue is empty\n");
	}
	else
	{
		if(fr.rear==fr.front)
		{
			fr.front=fr.rear=-1;
		}
	else if(fr.rear==0)
		fr.rear=n-1;
		else
		fr.rear--;
	}
	return fr;
}
int get_front(q fr,int a[],int n)
{
	if(isEmpty(fr))
	{
		printf("q is empty\n");
	}
	else
	{
	printf("%d is element at frisrt\n",a[fr.front]);
	}
	
}


int get_rear(q fr,int a[],int n)
{
	if(isEmpty(fr))
	{
		printf("q is empty\n");
	}
	else
	{
	printf("%d is element at rear\n",a[fr.rear]);
	}
	
}
void print(int a[],int n,q fr)
{
	int i;
	if(isEmpty(fr))
	{
		printf("q is empty\n");
	}
	else
	{
	for(i=fr.front;i!=fr.rear;i++)
	{
	
	printf("%d ",a[i]);
	if(fr.front>fr.rear)
	{
		if(i==(n-1))
		i=-1;
	}

	}
	
		printf("%d ",a[i]);
	printf("\n");
}
}
int main()
{
	int n,i;
	q fr;
	fr.front=-1;
	fr.rear=-1;
	printf("enter size of array\n");
	scanf("%d",&n);
	int a[n];
	int ch,x;
		printf("1:insert_front\t2:insert_rear\t3:delete front\t4:delete rear\t5:get front\t6:get rear\t7:isEmpty\t8:isFull\t9:print\n");
	for(;;)
	{
		printf("enter choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				
				fr=insert_front(fr,a,n);
				printf("%d %d\n",fr.front,fr.rear);
				break;
			case 2:
			
				fr=insert_rear(fr,a,n);
				break;
			case 3:
				fr=delete_front(fr,a,n);
				printf("%d %d\n",fr.front,fr.rear);
				break;
			case 4:
					printf("%d %d\n",fr.front,fr.rear);
				fr=delete_rear(fr,a,n);
				//	printf("%d %d\n",fr.front,fr.rear);
				break;
			case 5:
				get_front(fr,a,n);
				break;
			case 6:
				get_rear(fr,a,n);
				break;
			case 9:
				print(a,n,fr);
				break;
		}
	}
}
