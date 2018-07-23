#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *left,*right;
}node;

struct node* newNode(int data)
{
  struct node* node =
      (struct node*)malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return(node);
}
void inorder(node *root)
{
	if(root==NULL)
	return ;
	else
	{
		inorder(root->left);
		printf("%d ",root->data);
		inorder(root->right);
	}
	
}
void increment(node *root,int diff)
{
 printf("neha\n");
		if(root->left!=NULL)
		{
			root->left->data=root->left->data+diff;
			increment(root->left,diff);
		}
		else if(root->right!=NULL)
		{
			root->right->data=root->right->data+diff;
			increment(root->right,diff);
		}
}
 void convertTree(node *root)
 {
 	int l=0,r=0,ro=0;
 	if((root->left==NULL&&root->right==NULL)||root==NULL)
 	return ;
 	else
 	{
	 printf("neha\n");
 	convertTree(root->left);
 	convertTree(root->right);
 	if(root->left!=NULL)
 	 l=root->left->data;
 	 	if(root->right!=NULL)
 	 r=root->right->data;
 	 ro=root->data;
 	int diff=l+r-ro;
 	if(diff>0)
 	root->data=root->data+diff;
 	if(diff<0)
 	increment(root,-diff);
 	
 }
 }
 int main()
{
  struct node *root = newNode(10);
  root->left        = newNode(7);
  root->right       = newNode(2);
  root->left->left  = newNode(3);
  root->left->right = newNode(5);
  root->right->left  = newNode(1);
  root->right->right = newNode(30);
 
  printf("\n Inorder traversal before conversion ");
  inorder(root);
 
  convertTree(root);
 
  printf("\n Inorder traversal after conversion ");
  inorder(root);
 
  getchar();
  return 0;
}
