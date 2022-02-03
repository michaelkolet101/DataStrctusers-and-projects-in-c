
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

void BTSetDestroy(btset_ty *set)
{
    /*As long as the tree is not empty*/
    /*iterator to end*/
    /*Moves to the prev one*/
    /*Releases his next*/
}


btset_ty *BTSetCreate(bts_cmp_fnc_ty cmp_fnc, const void *cmp_param)
{
    /*A memory will be assigned to a tree*/
    /*We will initialize the members of the struct*/
    /*We will return the pointer to the root    */
}

btset_iter_ty BTSetInsert(btset_ty *set, void *element
{
/*We will define an iterator and a status equal to 0*/
/*We will allocate space for a new node*/

/*Loop that ran until status equals 1*/

    /*We will check if the place is available */

    /*If yes: 
        we will insert the new node and status equals 1 */
        /*Values ​​are given to the various pointers at the node*/
        
    /*if not: 
        We will check if the value at the inserted node is
        greater than the value at the current node*/
            /*We will progress to the next child accordingly*/

/*return iterator*/
}


/* Return value: iterator to the next element */
btset_iter_ty BTSetRemove(btset_ty *set, btset_iter_ty where)
{
    /*if Node to be deleted is the leaf  or without chiled: 
        Simply remove from the tree. */

    /*if Node to be deleted has only one child: 
    Copy the child to the node and delete the child */

    /*if Node to be deleted has two children:*/
    /* Find the next of the node. */
    /* Copy contents of the next to the node*/
    /* delete the next.*/
    
}

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
