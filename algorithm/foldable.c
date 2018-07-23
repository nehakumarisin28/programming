#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *left,*right;
}node;

node *newNode(int data)
{
	
    node *temp=(struct node*) malloc(sizeof(struct node)); 
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
 
    return temp;
}
void mirror(node *root)
{
	if(root==NULL)
	return;
	else
	{
		node *temp;
		mirror(root->left);
		mirror(root->right);
		temp=root->left;
		root->left=root->right;
		root->right=temp;
	}
}
int foldable(node *a,node *b)
{
	int l,r;
	if(a==NULL&&b==NULL)
	{
		return 1;
	}
	else if(a!=NULL&&b!=NULL)
	{
		l=foldable(a->left,b->left);
		r=foldable(a->right,b->right);
		if(l&&r)
		return 1;
	}
	else return 0;
}
int isFoldable(node *root)
{
	int x;
	mirror(root->left);
	x=foldable(root->left,root->right);
	mirror(root->left);
	return x;
}
int main()
{
	node *root;
    int x;
 
    /* Constructing tree given in the above figure */
    root = newNode(3);
    root->left = newNode(2);
    root->right = newNode(5);
   // root->left->left = newNode(1);
    //root->right->right = newNode(4); 
    x =isFoldable(root);
    if(x==1)
    	printf("tree is foldable\n");
    else
    	printf("tree is  not foldable\n");
    return 0;
}

