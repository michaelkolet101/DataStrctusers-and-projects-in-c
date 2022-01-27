/*******************************************************************************
*  Version 0.1 - post - API approved.										   *	
*  Version 1.0 - post - DlistEnd - function name changed from Dlistend.        *
*                                                                              *
*  Version 1.1 - post - following functions were changed DlistBegin, DlistEnd, * 
*												  		DlistPrev, DlistNext.  *
*												  		                       *
*  Version 1.2 - following functions arguments were changed DlistSize,         * 
*												  	  DlistEnd, DlistSetData.  * 
*												  				               *
*  Version 1.3 - following functions time Complexity were changed              *
*  										                  DlistInsertBefore.   *								  	
*******************************************************************************/
#ifndef __DLIST_H__
#define __DLIST_H__

#include <stddef.h> /*size_t*/
/*
#ifndef NDEBUG
	#define DEBUG_ONLY(exp) exp;
#else
	#define DEBUG_ONLY(exp) 
#endif
*/


typedef struct dlist dlist_ty;

typedef struct node node_ty;

typedef struct iterator iterator_ty;

struct iterator
{
	node_ty *dlist_node;
	/*DEBUG_ONLY(dlist_ty *list)*/
};

/*DlistForEach && DlistFind & DlistMultiFind*/
typedef int(*op_func_ty)(void *data, void *param);

typedef int(*match_func_ty)(const void *data, void *param);

/******************************************************************************
* Function Description: returns a pointer to an empty Dlist DS.   
* Arguments: - 
* Return value: Pointer to Dlist.
* Notes: Return NULL in case of failure

* Time Complexity: O(1)
*******************************************************************************/
dlist_ty *DlistCreate(void);

/******************************************************************************
* Function Description: destroys Dlist	       
* Arguments: pointer to a Dlist DS.
* Return value: none
* Notes:

* Time Complexity: O(n)
*******************************************************************************/
void DlistDestroy(dlist_ty *dlist);

/******************************************************************************
* Function Description: count num of elements in Dlist.   
* Arguments: pointer to Dlist,
* Return value: size of list
* Notes: 
*  
* Time Complexity: O(n)
*******************************************************************************/
size_t DlistSize(const dlist_ty *dlist);

/******************************************************************************
* Function Description: return a boolean if the Dlist is empty	       
* Arguments: pointer to a Dlist DS
* Return value: 1 empty 0 not
* Notes:

* Time Complexity: O(1)
*******************************************************************************/
int DlistIsEmpty(const dlist_ty *dlist);

/******************************************************************************
* Function Description: return first valid node in a Dlist DS
* Arguments: pointer to Dlist.
* Return value: head node Dlist.
* Notes: Return dummy in case of empty Dlist

* Time Complexity: O(1)
*******************************************************************************/
iterator_ty DlistBegin(const dlist_ty *dlist);

/******************************************************************************
* Function Description: return the end of a Dlist DS
* Arguments: pointer to Dlist.
* Return value: last node in Dlist.
* Notes: 

* Time Complexity: O(1)
*******************************************************************************/
iterator_ty DlistEnd(const dlist_ty *dlist);

/******************************************************************************
* Function Description: return the next node in a Dlist
* Arguments: iterator.
* Return value: iterator of the next node in Dlist.
* Notes: 

* Time Complexity: O(1)
*******************************************************************************/
iterator_ty DlistNext(iterator_ty current);

/******************************************************************************
* Function Description: return the previous node in a Dlist
* Arguments: iterator.
* Return value: iterator of the previous node in Dlist.
* Notes: undefined in case of first node

* Time Complexity: O(1)
*******************************************************************************/
iterator_ty DlistPrev(iterator_ty current);

/****************************************************************************** 
* Function Description: retrun true if two iterators are the same 
* Arguments: two iterators
* Return value: 1 if true 0 if false
* Notes:  

* Time Complexity: O(1)
*******************************************************************************/
int DlistIsSameIter(iterator_ty first, iterator_ty second);

/******************************************************************************
* Function Description: return the data of a given node 
* Arguments: iterator.
* Return value: void * to data.
* Notes: undefined in case of empty Dlist 

* Time Complexity: O(1)
*******************************************************************************/
void *DlistGetData(iterator_ty current);

/******************************************************************************
* Function Description: set data in a node of Dlist 
* Arguments: iterator, data pointer.
* Return value: -
* Notes: -

* Time Complexity: O(1)
*******************************************************************************/
void DlistSetData(iterator_ty current, void *data);

/******************************************************************************
* Function Description: insert a node before begginig of a given node.   
* Arguments: iterator,  void *data to insert.
* Return value: iterator to the new element.
* Notes: return dummy if fail
* Time Complexity: O(1) in case of failure O(n)
*******************************************************************************/
iterator_ty DlistInsertBefore(iterator_ty where, const void *data);

/******************************************************************************
* Function Description: remove a node before begginig of a given node.   
* Arguments: iterator.
* Return value: iterator to the next element in the list  
* Notes:  removing from an empty Dlist will cause undefined behaviour.
* Time Complexity: O(1)

*******************************************************************************/
iterator_ty DlistRemove(iterator_ty where);

/******************************************************************************
* Function Description: insert a node before the head of Dlist.   
* Arguments: pointer to dlist,  void *data to insert.
* Return value: iterator to new element.
* Notes: 
* Time Complexity: O(1)
*******************************************************************************/
iterator_ty DlistPushFront(dlist_ty *dlist, const void *data);

/******************************************************************************
* Function Description: insert a node after the tail of Dlist.   
* Arguments: pointer to node,  void *data to insert.
* Return value: iterator to new element.
* Notes: 
* Time Complexity: O(1)
*******************************************************************************/
iterator_ty DlistPushBack(dlist_ty *dlist, const void *data);

/******************************************************************************
* Function Description: remove the node of the begginig of a given Dlist.   
* Arguments: pointer to dlist.
* Return value: void *data
* Notes:  removing from an empty Dlist will cause undefined behaviour.
* Time Complexity: O(1)

*******************************************************************************/
void *DlistPopFront(dlist_ty *dlist);

/******************************************************************************
* Function Description: remove the node from the end of a given dlist.   
* Arguments: pointer to dlist.
* Return value:  void *data
* Notes:  removing from an empty Dlist will cause undefined behaviour.
* Time Complexity: O(1)

*******************************************************************************/
void *DlistPopBack(dlist_ty *dlist);


/******************************************************************************
* Function Description: foreach element in specified range, perform function.
* Arguments: iterator of start of range, iterator of end of range, function
* Return value: 1 if fail 0 if succsess & fuc stops upon first failure
* Notes: undefined behaviour if start and end not from the same list.

* Time Complexity: O(n)
*******************************************************************************/
int DlistForEach(iterator_ty start,
				 iterator_ty end,
				 op_func_ty op_func,
				 void *param);

/******************************************************************************
* Function Description: slice range of nodes from start to end and appends 
		   to dest
* Arguments: iterator of start of range, iterator of end of range, 
			 iterator of dest 
* Return value: iterator to start of dest 
* Notes: undefined behaviour if start and end not from the same list.
		 can be cut to another list
		 dest cannot be in the range - undefined

* Time Complexity: O(1)
*******************************************************************************/
iterator_ty DlistSplice(iterator_ty start,
				 iterator_ty end,
				  iterator_ty dest);
				 
/******************************************************************************
* Function Description: find first occurrence of data in dlist.   
* Arguments: iterator_ty start, iterator_ty end, match_func, void *param
* Return value: iterator of data
* Notes: undefined behaviour if start and end not from the same list.

* Time Complexity: O(n)
*******************************************************************************/
iterator_ty DlistFind(iterator_ty start,
 					   iterator_ty end, 
					    match_func_ty op_func,
					     void *param);

/******************************************************************************
* Function Description: find occurrence of data in Dlist.   
* Arguments: iterator_ty start, iterator_ty end, match_func, void *param, 
			 dlist *dest
* Return value: number of match nodes, if fail return -1
* Notes: undefined behaviour if start and end not from the same list.
* Time Complexity: O(n)
*******************************************************************************/
int DlistMultiFind(iterator_ty start,
 					   iterator_ty end,
 					    dlist_ty *dest, 
					     match_func_ty op_func,
					      void *param);

#endif /*__DLIST_H__*/

