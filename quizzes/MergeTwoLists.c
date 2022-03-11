#include <stdio.h>
#include <assert.h> /*assert*/ 
#include <stdlib.h> /*malloc free*/

typedef struct ListNode
	{
      struct ListNode *next;
      int data;

	} node_ty;

node_ty *GoNext(node_ty *node);
node_ty *NewNode(int data); 
node_ty *MergeTwoLists(node_ty *list_a, node_ty *list_b);
void Insert(node_ty *prev, node_ty *curr);


int main(void) 
{
	return 0; 
}


node_ty *MergeTwoLists(node_ty *list_a, node_ty *list_b) 
{ 
	/*def a new list dummy is the first node*/
	node_ty *dummy = NewNode(0);
	node_ty *curr = dummy;

	/*while a and b in next is not null*/
	while (list_a->next != NULL || list_b->next != NULL)
	{
		/*check who is small to start with*/
		/*insert the small node to new list*/
		/*if is from a then move to next in a*/
		if(list_a->data <= list_b->data)
		{
			Insert(curr, list_a);
			list_a = GoNext(list_a);
		}
		/*if is from b then move to next in b*/
		else if(list_a->data >= list_b->data)
		{
			Insert(curr, list_b);
			list_b = GoNext(list_b);
		}
	}

	/*return the first node in the ret list*/
	return dummy->next;
}


node_ty *NewNode(int data)
{
	node_ty *node = (node_ty *)malloc(sizeof(node_ty));

	node->data = data;

	return node;   	
}

void Insert(node_ty *prev, node_ty *curr)
{
	prev->next = curr;
}


node_ty *GoNext(node_ty *node)
{
	return node->next;
}
