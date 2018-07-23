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
int maxDepth(node *root)
{
	if(root==NULL)
	return;
	int l,r;
	l=maxDepth(root->left);
	r=maxDepth(root->right);
	if(l>r)
	return l+1;
	else return r+1;
}
void print(int a[],int i)
{
	int j;
	for(j=0;j<i;j++)
	printf("%d ",a[j]);
	printf("\n");
	
}
void each_path(node *root,int a[],int i)
{

	if(root==NULL)
	return ;
	 a[i]=root->data;
	  i++;
	 if(root->left==NULL&&root->right==NULL)
	print(a,i);

	each_path(root->left,a,i);
	each_path(root->right,a,i);

}
   
int main()
{
    node *root = newNode(1);
 
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5); 
     root->left->right->left = newNode(6); 
   int x;
   x=maxDepth(root);
   int a[x];
     each_path(root,a,0);
   
    return 0;
}
