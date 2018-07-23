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
void level(node *root,int i)
{
	if(root==NULL)
	return;
	if(i==1)
	printf("%d ",root->data);
	else
	{
		level(root->left,i-1);
		level(root->right,i-1);
	}
	
}
void level_order(node *root)
{
	
	int i,max;
	max=max_depth(root);
	for(i=1;i<=max;i++)
	{
		level(root,i);
		printf("\n");
	}
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
    
     level_order(root1); 
   
  
    return 0;
}
