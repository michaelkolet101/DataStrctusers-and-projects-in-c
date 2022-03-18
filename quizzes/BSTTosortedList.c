#include <stdio.h>
#include <assert.h> 
 
typedef struct node node_ty;

struct node
{
	node_ty *left;
	node_ty *right;
	node_ty *parent;
	int data;
};







node_ty *Marge(node_ty *root, node_ty *arr[]);


node_ty *BSTTosortedList(node_ty *root);




 
int main(void) 
{ 
 	return(0);			 
}

node_ty *Marge(node_ty *root, node_ty *arr[]) 
{ 
	assert(root);

	if (NULL != root->left)
	{
		root->left = BSTTosortedList(root->left);
		arr[0] = root->left;
	}
	
	if (NULL != root->right)
	{
		root->right = BSTTosortedList(root->right);
		arr[1] = root->right;
	}

	return arr;
}

node_ty *BSTTosortedList(node_ty *root)
{
	node_ty *start_end[2] = {0};
	return Marge(root, start_end);
}