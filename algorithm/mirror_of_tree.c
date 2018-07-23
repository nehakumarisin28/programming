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
void print(node *root)
{
	if(root==NULL)
	return;
	print(root->left);
	printf("%d ",root->data);
	print(root->right);
}
int mirror_of_tree(node *root)
{
	int l=0,r=0;
	node *temp;
	if(root==NULL)
	return 0;
	mirror_of_tree(root->left);
	mirror_of_tree(root->right);
	temp=root->left;
	root->left=root->right;
	root->right=temp;
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
    printf("before modification:\n");
    print(root);
  	 mirror_of_tree(root);
  	printf("\nafter modification:\n");
  	 print(root);
   
  
    return 0;
}
