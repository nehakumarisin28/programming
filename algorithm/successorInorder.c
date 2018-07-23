#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *left,*right,*next;
}node;

 node* newNode(int data)
{
  node* nod =(node* )malloc(sizeof(node));
  nod->data = data;
  nod->left = NULL;
  nod->right = NULL;
  return(nod);
}
void successorInorder( node* root)
{
	static node* p=NULL;
     if (root == NULL)
          return;
          
 else
 {
    successorInorder(root->right);
		root->next=p;
		p=root;
 	successorInorder(root->left);
 }
}
void printInorder(struct node* node)
{
     if (node == NULL)
          return;
 
     /* first recur on left child */
     printInorder(node->left);
 
     /* then print the data of node */
     printf("%d ", node->data);  
 
     /* now recur on right child */
     printInorder(node->right);
}
int main()
{
 
    /* Constructed binary tree is
              10
            /   \
          8      12
        /
      3
    */
    node *root = newNode(10);
    root->left        = newNode(8);
    root->right       = newNode(12);
    root->left->left  = newNode(3);
     root->right->left       = newNode(2);
     printf("\nwithout successor\n");
 printInorder(root);
    // Populates nextRight pointer in all nodes
    successorInorder(root);
 
    // Let us see the populated values
    node *ptr = root->left->left;
    printf("\nwith successor\n");
    while(ptr!=NULL)
    {
    
        printf("  %d  ", ptr->data);
        ptr = ptr->next;
    }
 
    return 0;
}
