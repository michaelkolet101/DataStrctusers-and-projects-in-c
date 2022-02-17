#include <stdio.h>
#include <stdlib.h>
#include "avl_tree.h"

enum avl_ty {
	LEFTHEAVY = -1,
	BALANCED = 0,
	RIGHTHEAVY = 1
};


typedef struct avl_node 
{
	avl_node_ty *left;
	avl_node_ty *right;
	avl_node_ty *parent;
	void *data;
    int *balance_factor;
} avl_node_ty;



typedef struct avl_tree 
{
    avl_node_ty root;
    avl_cmp_fnc_ty cmp_func;
    const void *param;
};


avl_tree_ty *AVLCreate(avl_cmp_fnc_ty cmp_fnc, const void *cmp_param)
{
    
    /*def ret pointer new_tree to the return value*/

    /*alloc a avl tree*/

    /*alloc a node to root*/

    /*check allocations*/

    /*init members is structs*/

    /*return the new tree pointer*/
}

int AVLRemove(avl_tree_ty *tree, const void *key_to_remove)
{
    /* Find the node that needs to be removed */
    /*Removal of the node funcIMP*/
    /*Balance the tree funcIMP*/
}


void AVLInsert(avl_tree_ty *tree,  void *element_to_insert)
{
    /*if the node key is larger than the key you want to insert into the tree*/

        /*if there is a son left to the junction*/

            /*perform the test for the sub-tree beginning with that son recutsiv.*/

            /* Otherwise, the new node will be the left son of the node.*/

        /*if the node key is smaller than the key you want to insert into the tree.*/

            /* if there is a right-hand son to the junction*/ 
                /*perform the test for the sub-tree beginning with that son.*/

            /* Otherwise, the new node will be the right-hand son of the node.*/


    /*we need to check the route from the new node up to the root*/

    /*if there is a node whose balance factor has been disturbed */

        /* Balance the tree funcIMP */
}

void *AVLFind(const avl_tree_ty *tree, const void *key)
{
    /* If the node key matches the requested key - return it  */

    /*If the node key is larger than the requested key*/

        /* perform a search that begins with the node that is the left son of the current node, 
        and returns the result with AVLFind.*/

    /*If the node key is smaller than the requested key*/
        /* perform a search on the node that
         is the right-hand son of the current node, and return the result with AVLFind.*/

    /*else The requested figure is not found in the tree.*/
}

int AVLForEach(avl_tree_ty *tree,
					   op_func_ty,
					   void *op_param,
					   tree_travel_ty travel_type);
{
    
    /*perform the AVLForEach for the left son of the node*/

    /*call the op func*/

    /*perform the AVLForEach for the right son of the node*/
   
}