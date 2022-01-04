/*version 1.1 missing ; in findif function*/
/*version 1.2 fixed problem with typedef of sortlist*/
/*version 1.3 fixed double parantheses in function find if,fixed wrong signiture
int function Create*/
/*version 1.4 missing ; in the sort_list struct, reorder in the typedefs*/
/*version 1.5 fixed mistakes in the popfront and popback signiture*/
/* version 1.6 fixed notes in find and findif description */ 
/*version 1.7 fixed description in the find function, *added note in the insert
	function - order of the list will be in the way the compare of higher index 
	to the previous member will return positive*/

#ifndef __SORTED_LIST_H__
#define __SORTED_LIST_H__

#include <stddef.h> /*size_t*/
#include "dlist.h"

#ifndef NDEBUG
	#define DEBUG_ONLY(exp) exp;
#else
	#define DEBUG_ONLY(exp) 
#endif


typedef struct sortlist sortlist_ty;

struct iterator_sort_list
{
	iterator_ty iterator;
	DEBUG_ONLY(sortlist_ty *list)
};

typedef struct iterator_sort_list srt_iter_ty;


/*0 if equal, 0> if data1 lower then data2, 0< if data1 higher then data2*/
typedef int(*cmp_func_ty)(const void *data1, const void *data2);


/*move to src*/
/*struct sortlist*/
/*{*/
/*	dlist_ty *dlist;	*/
/*	cmp_func_ty cmp_func;*/
/*};*/

/******************************************************************************
* Function Description: returns a pointer to an empty SortedList DS.   
* Arguments: compar function.
* Return value: Pointer to SortedList.
* Notes: Return NULL in case of failure

* Time Complexity: O(1)
*******************************************************************************/
sortlist_ty *SortedListCreate(cmp_func_ty cmp_func);

/******************************************************************************
* Function Description: destroys SortedList	       
* Arguments: pointer to a SortedList DS.
* Return value: none
* Notes:

* Time Complexity: O(n)
*******************************************************************************/
void SortedListDestroy(sortlist_ty *sortlist);

/******************************************************************************
* Function Description: count num of elements in SortedList.   
* Arguments: pointer to list,
* Return value: size of the list
* Notes: 
*  
* Time Complexity: O(n)
*******************************************************************************/
size_t SortedListSize(const sortlist_ty *sortlist);

/******************************************************************************
* Function Description: return a boolean if the SortedList is empty	       
* Arguments: pointer to a SortedList DS
* Return value: 1 empty 0 not
* Notes:

* Time Complexity: O(1)
*******************************************************************************/
int SortedListIsEmpty(const sortlist_ty *sortlist);

/******************************************************************************
* Function Description: return a beginning of a SortedList DS
* Arguments: pointer to SortedList.
* Return value: first valid node of the SortedList.
* Notes: Return dummy tail node in case of empty list

* Time Complexity: O(1)
*******************************************************************************/
srt_iter_ty SortedListBegin(const sortlist_ty *sortlist);

/******************************************************************************
* Function Description: return the dummy end of a SortedList DS
* Arguments: pointer to SortedList.
* Return value: last node in SortedList.
* Notes: -

* Time Complexity: O(1)
*******************************************************************************/
srt_iter_ty SortedListEnd(const sortlist_ty *sortlist);

/******************************************************************************
* Function Description: return the next node in a SortedList
* Arguments: iterator.
* Return value: iterator of the next node in SortedList.
* Notes: undifeined behaviour in case user gave the last dummy node.

* Time Complexity: O(1)
*******************************************************************************/
srt_iter_ty SortedListNext(srt_iter_ty current);

/******************************************************************************
* Function Description: return the previous node in a SortedList
* Arguments: iterator.
* Return value: iterator of the previous node in SortedList.
* Notes: undefined in case of first node

* Time Complexity: O(1)
*******************************************************************************/
srt_iter_ty SortedListPrev(srt_iter_ty current);

/****************************************************************************** 
* Function Description: retrun true if two iterators points the same node 
* Arguments: two iterators
* Return value: 1 if true 0 if false
* Notes:  

* Time Complexity: O(1)
*******************************************************************************/
int SortedListIsSameIter(srt_iter_ty first, srt_iter_ty second);

/******************************************************************************
* Function Description: return the data of a given node 
* Arguments: iterator.
* Return value: void * to data.
* Notes: undefined in case of empty SortedList 

* Time Complexity: O(1)
*******************************************************************************/
void *SortedListGetData(srt_iter_ty current);


/******************************************************************************
* Function Description: insert a node and sort it by the compare function. 
*				so that  compare function of member to the previous member
*				will return  positive. 
* Arguments: pointer to sortlist,  void *data to insert.
* Return value: iterator to the new node.
* Notes: return dummy if fail
* Time Complexity: O(n).
*******************************************************************************/
srt_iter_ty SortedListInsert(sortlist_ty *sortlist, const void *data);

/******************************************************************************
* Function Description: remove the given node.   
* Arguments: iterator.
* Return value: iterator to the next element in the list  
* Notes:  removing from an empty SortedList will cause undefined behaviour.
* Time Complexity: O(1)

*******************************************************************************/
srt_iter_ty SortedListRemove(srt_iter_ty where);


/******************************************************************************
* Function Description: remove the node of the beginning of a given SortedList.   
* Arguments: pointer to sortlist.
* Return value: void *data
* Notes:  removing from an empty SortedList will cause undefined behaviour.
* Time Complexity: O(1)

*******************************************************************************/
void *SortedListPopFront(sortlist_ty *sortlist);

/******************************************************************************
* Function Description: remove the node from the end of a given sortlist.   
* Arguments: pointer to sortlist.
* Return value:  void *data
* Notes:  removing from an empty SortedList will cause undefined behaviour.
* Time Complexity: O(1)

*******************************************************************************/
void *SortedListPopBack(sortlist_ty *sortlist);


/******************************************************************************
* Function Description: foreach element in specified range, perform function.
* (not including the end node)
* Arguments: iterator of start of range, iterator of end of range, function,
* parameter
* Return value: 1 if fail 0 if succsess & func stops upon first failure
* Notes: undefined behaviour if start and end not from the same list.

* Time Complexity: O(n)
*******************************************************************************/
int SortedListForEach(srt_iter_ty start,
				 srt_iter_ty end,
				 int(*op_func_ty)(void *data, void *param),
				 void *param);
				 
/******************************************************************************
* Function Description: merge the two list and sort them by the compare function.
* Arguments: two sorted list pointers 
* Return value: pointer to the sortlist of the merged lists  
* Notes: undefined behaviour if user giving the same list.
*		 undefined if the comapare function is not the same.
* the second list will be empty afetr using the function.
* Time Complexity: O(n + m)
*******************************************************************************/
sortlist_ty *SortedListMerge(sortlist_ty *first ,sortlist_ty *second);
				 
/******************************************************************************
* Function Description: find first node that return true by the comapre function
	given the data  
* Arguments: sortlist pointer iterator_ty start, iterator_ty end, void * of 
*			 data to find
* Return value: iterator of data
* Notes: undefined behaviour if start and end not from the same list.
* in case no node found return thr dummy end.

* Time Complexity: O(n)
*******************************************************************************/
srt_iter_ty SortedListFind(sortlist_ty *list,srt_iter_ty start, srt_iter_ty end,
														const void *to_find);

/******************************************************************************
* Function Description: compare the data and the parameter by the function user 
						send to function 
* Arguments: iterator start, itearator end, match function, parameter
* Return value: iterator to matches node
* Notes: undefined behaviour if start and end not from the same list.
*		 in case no node found return thr dummy end.
* Time Complexity: O(n)
*******************************************************************************/
srt_iter_ty SortedListFindIf(srt_iter_ty start,
 					   srt_iter_ty end, 
					   int(*match_func)(const void *data, void *param),
					     void *param);



#endif /*__SORTED_LIST_H__*/
