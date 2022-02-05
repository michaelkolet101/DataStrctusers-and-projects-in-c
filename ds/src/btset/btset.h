/* API Log:
    - version 1.1 - changed names from set to btset. 
    - version 1.2 - fixed typos.  
    - version 1.3 - added BTSetIsIterBad func.
                    added comparison function description 
    - version 1.4 - updated notes of Remove Next, Prev and GetData */


#ifndef __BTSET_H__
#define __BTSET_H__

#include <stddef.h> /*size_t*/

#include "utils.h" /* DEBUG_ONLY */

typedef struct binary_tree_node bt_node_ty;

typedef struct binary_tree_set btset_ty;

/*  The comparison function returns an integer less than, equal to,  or
    greater  than  zero  if elem1 is considered to be respec‐
    tively less than, equal to, or greater than the elem2.  If two members
    compare as equal, the behaviour is undefined. */
typedef int(*bts_cmp_fnc_ty)(const void *elem1,
                             const void *elem2,
                             const void *param);

typedef struct binary_tree_iterator
{
    bt_node_ty* node;
    /*DEBUG_ONLY(btset_ty *set);*/
}btset_iter_ty;

/* General notes:
    * set performance is best when keys are not sorted before added.
 */

/* Return value: returns null when fails */
btset_ty *BTSetCreate(bts_cmp_fnc_ty cmp_fnc, const void *cmp_param);


void BTSetDestroy(btset_ty *set);


btset_iter_ty BTSetInsert(btset_ty *set, void *element);


/*  Notes:  all iterators except returned iterator 
            might be (and likely be) invalid after using BTSetRemove
    Return value: iterator to the next element */
btset_iter_ty BTSetRemove(btset_ty *set, btset_iter_ty where);


btset_iter_ty BTSetFind(btset_ty *set, const void *key_element);


size_t BTSetSize(const btset_ty *set);

/*  Returns pointer to the first element */
btset_iter_ty BTSetBegin(btset_ty *set);

/*  Returns pointer to the end */
btset_iter_ty BTSetEnd(btset_ty *set);

/*  Notes: next on end is undefined */
btset_iter_ty BTSetNext(btset_iter_ty iterator_to_inc);

/*  Notes: prev on begin is undefined */
btset_iter_ty BTSetPrev(btset_iter_ty iterator_to_dec);


int BTSetIsSameIter(btset_iter_ty first, btset_iter_ty second);


int BTSetIsIterBad(btset_iter_ty check);


/*  Notes:  never change values of key fields
            do not use GetData on BTSetEnd */
void *BTSetGetData(btset_iter_ty where);


/* 1 empty 0 not */
int BTSetIsEmpty(const btset_ty *set);



#endif /*__BTSET_H__*/