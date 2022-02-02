
#include "btset.h"

struct binary_tree_set
{
    binary_tree_node *root;
    bts_cmp_fnc_ty *cmp_func;
    void *param;
};


struct binary_tree_node
{
    bt_node_ty *right;
    bt_node_ty *left;
    bt_node_ty *perrent;
    void *data; 
};



btset_iter_ty BTSetEnd(btset_ty *set)
{
/* We will set an iterator for SET */
/* As long as the next step to the right is not NULL we will go right */
/* We return the iterator and up to one step to the right */
}

btset_iter_ty BTSetNext(btset_iter_ty iterator_to_inc)
{
    /* We will go right one step */
   /* We will check if there is a left value */
   /* If yes, then loop as long as the value is not NULL */
   /* We will step left */
   /* We will exit the loop and return an iterator */
}

btset_iter_ty BTSetPrev(btset_iter_ty iterator_to_dec)
{
/* We will take one step left */
/* We will check if there is a right value */
/* If yes then loop as long as the value is not NULL */
/* We will step right */
/* We will exit the loop and return an iterator */
}

int BTSetIsSameIter(btset_iter_ty first, btset_iter_ty second)
{
    /* We will check if the iterators are equal and we will 
                            return 1 otherwise we will return 0 */
}

void *BTSetGetData(btset_iter_ty where)
{
/* We will return the information through the iterator */
}

int BTSetIsEmpty(const btset_ty *set)
{
/* If the value of SET NULL we return 1 otherwise we return 0 */
}
