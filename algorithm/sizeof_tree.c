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
int size_of_tree(node *root)
{
	int l=0,r=0;
	if(root==NULL)
	return 0;
	l=size_of_tree(root->left);
	r=size_of_tree(root->right);
	return r+l+1;
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
   
    printf("size of tree is %d", size_of_tree(root));
   
  
    return 0;
}
