#include<stdio.h>
#include<stdio.h>
#include<stdio.h>
#include<stdlib.h>
 
typedef struct node 
{
	int data;
	struct node *left,*right;
}node;
node* newNode(int data) 
{
    node* node = (struct node*) malloc(sizeof(struct node));               
    node->data = data;
    node->left = NULL;
    node->right = NULL;
   
    return(node);
}
int max_depth(node *root)
{
	int l=0,r=0;
	if(root==NULL)
	return 0;
	else
	{
	l=max_depth(root->left);
	r=max_depth(root->right);
	if(l>r)
	return l+1;
	else
	return r+1;
	}
	
}
void level(node *root,int i,int j,int a[])
{
	if(root==NULL)
	return;
	if(j==i)
	{
		a[i]=a[i]+1;
	}
	else
	{
		level(root->left,i,j+1,a);
		level(root->right,i,j+1,a);
	}
	
}
void level_order(node *root)
{
	
	int i,max;
	max=max_depth(root);
	 int a[max];
	for(i=1;i<=max;i++)
	{
		a[i]=0;
		level(root,i,1,a);
		printf("\n");
	}
	for(i=1;i<=max;i++)
	printf("%d: %d\n",i,a[i]);
}
   
int main()
{
    node *root1= newNode(1);
 
    root1->left = newNode(2);
    root1->right = newNode(3);
    root1->left->left = newNode(4);
   root1->left->right = newNode(5); 
    root1->left->right->left = newNode(6); 
   root1->right->left = newNode(7);
   root1->right->right = newNode(8);
   root1->right->right->left = newNode(9);
    
     level_order(root1); 
   
  
    return 0;
}
