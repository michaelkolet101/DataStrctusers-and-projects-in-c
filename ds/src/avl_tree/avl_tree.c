#include <stdio.h>
#include <stdlib.h>
#include "avl_tree.h"
#include <assert.h>
#define CHILDEREN 2

enum
 {
    LEFT = 0, 
    RIGHT = 1
};


typedef enum balansd {
	LEFTHEAVY = -1,
	BALANCED = 0,
	RIGHTHEAVY = 1
}balansd_ty ;


struct avl_node 
{
	avl_node_ty *m_kids[CHILDEREN];	
	void *m_data;
    balansd_ty m_balance_factor;
};


struct avl_tree 
{
    avl_node_ty *m_root;
    avl_cmp_fnc_ty m_cmp_func;
    const void *m_param;
};

static size_t MaxIMP(size_t num1, size_t num2);
static avl_node_ty *MakeNewNodeIMP();
void *FindIMP(const avl_tree_ty *tree ,avl_node_ty *node, void *key);



avl_tree_ty *AVLCreate(avl_cmp_fnc_ty cmp_fnc, const void *cmp_param)
{        
    /*alloc a avl tree*/
    avl_tree_ty *new_tree = (avl_tree_ty *) malloc(sizeof(avl_node_ty));

    /*alloc a node to root*/
    avl_node_ty *new_node = MakeNewNodeIMP();
    
    /*check allocations*/
    if (NULL == new_node || NULL == new_tree)
    {
        free(new_node);
        free(new_tree);
        return NULL;
    }
    
    /*init members is structs*/
    new_node->m_balance_factor = 0;
    new_node->m_data = NULL;
    
    new_tree->m_root = new_node;
    new_tree->m_cmp_func = cmp_fnc;
    new_tree->m_param = cmp_param;

    /*return the new tree pointer*/
    return new_tree;
}

int AVLRemove(avl_tree_ty *tree, const void *key_to_remove)
{
    /* Find the node that needs to be removed funcIMP*/

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
    return FindIMP(tree, tree->m_root->m_kids[LEFT], key);
}


int AVLForEach(avl_tree_ty *tree,
					   op_func_ty op_func,
					   void *op_param,
					   tree_travel_ty travel_type)
{
    
    /*perform the AVLForEach for the left son of the node*/

    /*call the op func*/

    /*perform the AVLForEach for the right son of the node*/
   
}

static avl_node_ty *MakeNewNodeIMP()
{
    avl_node_ty *new_node = (avl_node_ty *)malloc(sizeof(avl_node_ty));
    new_node->m_kids[RIGHT] = NULL;
    new_node->m_kids[LEFT] = NULL;

    return new_node;
}


static void AVLInsertIMP(avl_tree_ty *tree_, avl_node_ty **sub_tree_, void *elem_to_insert_ )
{
    /*assert sub tree and tree*/
    assert(tree_);
    assert(sub_tree_);

    /*if *sub tree == NULL*/
    if (NULL == *sub_tree_)
    {
        /*insert here*/
        *sub_tree_= MakeNewNodeIMP();
        *sub_tree_->data = elem_to_insert_;
    }
    
    /* assert not equal to this one */
    assert()

    /*AVLInsertIMP()*/     
    AVLInsertIMP(...);

    /*if there is a node whose balance factor has been disturbed */
    /* Balance the tree funcIMP */
}

size_t AVLHeight(const avl_tree_ty *tree)
{
    /* base case: empty tree has a height of 0*/
    if (AVLIsEmpty(tree))
    {
        return 0;
    }
    /*recur for the left and right subtree and consider maximum depth*/
    return MaxIMP(AVLHeight(tree->m_root->m_kids[LEFT]), AVLHeight(tree->m_root->m_kids[RIGHT]));
}

size_t AVLSize(const avl_tree_ty *tree)
{
    /*If tree is empty then return 0*/
    if (NULL == tree)
    {
        return 0;
    }

     /*Calculate size of the tree as following:tree_size  =  size(left-subtree) + size(right- subtree) + 1*/ 
     /*Return tree_size*/  
     return AVLSize(tree->m_root->m_kids[LEFT]) + 1 + AVLSize(tree->m_root->m_kids[RIGHT]); 
}

int AVLIsEmpty(const avl_tree_ty *tree)
{
    /*return 1 if tree->root->kids[LEFT] ==NULL*/
    return tree->m_root->m_kids[LEFT] == NULL;
}

static size_t MaxIMP(size_t num1, size_t num2)
{
    return num1 >= num2 ? num1 : num2;
}

void *FindIMP(const avl_tree_ty *tree ,avl_node_ty *node, void *key)
{
    int res = tree->m_cmp_func(tree->m_root->m_data, key, tree->m_param); /*-1, 0, 1*/ 
    /* If the node key matches the requested key - return it  */
    if ( 0 ==  res)
    {
        return tree->m_root->m_data;
    }
    /*call to find with the left or right chiled*/
    return AVLFind(tree->m_root->m_kids[(res > 0)], key); /*res > 0 it's 0 or 1 left or right*/
}