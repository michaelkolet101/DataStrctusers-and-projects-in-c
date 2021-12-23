#include <stddef.h>/*NULL*/
#include <assert.h> /* assert */

#include "../includ/SLIST_EXERCISES.h"
 
/* Link list node */

static int GetCount(node_ty* head);

node_ty *Flip(node_ty *head)
{
   	
   	/*make iterator to the previous node */
    node_ty *prev = NULL;
    
    /*make iterator to the current node */
    node_ty *current = head;
    
    /*make iterator to the next node */
    node_ty *next_node = NULL;
    
    /*while the current node is not NULL*/
    while (current != NULL) 
    {
		/*the next iterator point to the next node*/
		next_node = current->next;
		
		/*insert in the "next" of the current node NULL*/
		current->next = prev;
		
		/*make the iterator of the previous to pint on current*/
		prev = current;
		
		/*make the current iterator to point on the next node 
		                                               and make it current*/
		current = next_node;
	}
	
	/*make the new head of the list*/
	head = prev;
}

int HasLoop(const node_ty *head)
{
	/*pointer that run one by one and pointer that run fast*/
	node_ty *ptr_to_head = (node_ty *)head;
	node_ty *slow_p = ptr_to_head, *fast_p = ptr_to_head;

	/*while slow_p and fast_p not ended */
	while (NULL != slow_p && NULL != fast_p && NULL != fast_p->next)
	{
		slow_p = slow_p->next;
		fast_p = fast_p->next->next;
		/*if ther is a loop the pointers will meet*/
		if (slow_p == fast_p) 
		{
			return 1;
		}
	}
	return 0;
}

node_ty *FindIntersection(node_ty *head1, node_ty *head2)
{

	node_ty *iter1 = head1;
	node_ty *iter2 = head2;
	
	size_t count1 = 0, count2 = 0, x = 0; 
	
	assert(head1);
	assert(head2);
	
	count1 = GetCount(head1);
	count2 = GetCount(head2);
	
	iter1 = head1;
	iter2 = head2;
	
	while (count1 > count2)
	{
		iter1 = iter1->next;
		--count1;
	}
		
	while (count1 < count2)
	{
		iter2 = iter2->next;
		--count2;
	}

	while (NULL != iter1)
	{		
		if (iter2 == iter1)
		{
			return iter2;
		}
			
		iter2 = iter2->next;
		iter1 = iter1->next;
	}
	
	return NULL;
}

static int GetCount(node_ty *head)
{
    node_ty *current = head;
    int count = 0;
    
    assert(head);
 
    while (current != NULL)
    {
        ++count;
        current = current->next;
    }
 
    return count;
}











