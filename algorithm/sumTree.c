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
int sumTree(node *root)
{
	 int l,r;
	if(root==NULL)
	return 0;
	else if(root->left==NULL&&root->right==NULL)
	return root->data;
	else
	{
		
		l=sumTree(root->left);
		r=sumTree(root->right);
		if((l+r)==root->data)
		{
		return (l+r+root->data);
	}
	else return 0;
	}
}
int main()
{
  struct node *root = newNode(28);
  root->left        = newNode(11);
  root->right       = newNode(3);
  root->left->left  = newNode(4);
  root->left->right = newNode(7);
  //root->right->left  = newNode(1);
  root->right->right = newNode(3);
  int x=sumTree(root);
  if(x==(2*root->data))
   printf("The given tree is a SumTree ");
   else
    printf("The given tree is not a SumTree ");
  return 0;
}
