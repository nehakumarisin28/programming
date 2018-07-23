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
int leaf_nodes(node *root)
{
	int l=0,r=0;
	if(root==NULL)
	return ;
	else if(root->left==NULL&&root->right==NULL)
	return 1;

	l=l+leaf_nodes(root->left);
	r=r+leaf_nodes(root->right);
	return r+l;
}
   
int main()
{
    node *root = newNode(1);
 
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
   root->left->right = newNode(5); 
    root->left->right->left = newNode(6); 
    root->right->left = newNode(7);
    root->right->right = newNode(8);
   
    printf("Hight of tree is %d", leaf_nodes(root));
   
  
    return 0;
}
