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


struct avl_node 
{
	avl_node_ty *m_kids[CHILDEREN];	
	void *m_data;
    size_t m_height;
};


struct avl_tree 
{
    avl_node_ty *m_root;
    avl_cmp_fnc_ty m_cmp_func;
    const void *m_param;
};


static size_t MaxIMP(size_t num1, size_t num2);
static avl_node_ty *MakeNewNodeIMP();
static int GetBalansedIMP(avl_node_ty *node);
static void *GetData(avl_node_ty *node);

size_t AVLHeightIMP(const avl_node_ty *node);
avl_node_ty *FindIMP(const avl_tree_ty *tree ,avl_node_ty *node, void *key);
avl_node_ty *RotetLeft(avl_node_ty* node_);
avl_node_ty *RotetRight(avl_node_ty* node_);


avl_tree_ty *AVLCreate(avl_cmp_fnc_ty cmp_fnc, const void *cmp_param)
{        
    /*alloc a avl tree*/
    avl_tree_ty *new_tree = (avl_tree_ty *) malloc(sizeof(avl_node_ty));

    /*check allocations*/
    if (NULL == new_tree)
    {
        free(new_tree);
        return NULL;
    }
    
    /*init members is structs*/
    
    new_tree->m_root = NULL;
    new_tree->m_cmp_func = cmp_fnc;
    new_tree->m_param = cmp_param;
    

    /*return the new tree pointer*/
    return new_tree;
}

int AVLRemove(avl_tree_ty *tree, const void *key_to_remove)
{
    avl_node_ty *node_to_delet = NULL;

    /* Find the node that needs to be removed funcIMP*/
    node_to_delet = FindIMP(tree, tree->m_root, key_to_remove);

    if (NULL == node_to_delet->m_kids[LEFT] && NULL == node_to_delet->m_kids[RIGHT])
    {
    /*Removal of the node */
        free(node_to_delet);
        return 0;
    } 

    node_to_delet->m_data = node_to_delet->m_kids[(NULL != node_to_delet->m_kids[RIGHT])]->m_data;
    free(node_to_delet->m_kids[(NULL != node_to_delet->m_kids[RIGHT])]);      

    /*Balance the tree funcIMP*/
    return 0;
}


int AVLInsert(avl_tree_ty *tree_,  void *element_to_insert_)
{

    int side = 0;
    
    avl_node_ty *new_node = MakeNewNodeIMP(element_to_insert_);
    
    if (NULL == new_node)
    {
        return 1;
    }
    
    side = tree_->m_cmp_func(element_to_insert_, new_node->m_data, tree_->m_param) > 0;

    AVLInsertIMP(tree_, &new_node->m_kids[side], element_to_insert_ );

    /*Balance the tree if needed*/
    balansed = GetBalansedIMP(new_node)
    /*Left Left Case*/
    
    
    
    

    return 0;              
}

static int GetBalansedIMP(avl_node_ty *node)
{
    return (AVLHeightIMP(node->m_kids[LEFT]) - AVLHeightIMP(node->m_kids[RIGHT]));
}

void *AVLFind(const avl_tree_ty *tree, const void *key)
{
    return FindIMP(tree, tree->m_root, key);
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



static int AVLInsertIMP(avl_tree_ty *tree_, avl_node_ty **sub_tree_, void *elem_to_insert_ )
{
    int balansed = 0;
    int side = 0;

    /*assert sub tree and tree*/
    assert(tree_);
    assert(sub_tree_);


    /*if *sub tree == NULL*/
    if (NULL == *sub_tree_)
    {
    /* assert not equal to this one */
        /*insert here*/
        (*sub_tree_)= MakeNewNodeIMP(elem_to_insert_);

        if (NULL == *sub_tree_)
        {
            return 1; /*fail*/
        }
    }

    side = tree_->m_cmp_func(elem_to_insert_, (*sub_tree_)->m_data, tree_->m_param) > 0;

    /*AVLInsertIMP()*/     
    AVLInsertIMP(tree_, (*sub_tree_)->m_kids[side], elem_to_insert_);

    /* Update height of this ancestor node */
    (*sub_tree_)->m_height = AVLHeightIMP(*sub_tree_);

     /*Get the balance factor of this ancestor node to check 
                                whether this node became unbalanced */
    balansed = GetBalansedIMP(*sub_tree_);

     /*LL case*/
    if ( (balansed > 1) && (side > 0) )
    {
        return RotetRight((*sub_tree_));
    }

     /*Right Right Case*/
    if (( (balansed < -1) && (side < 0) ))
    {
        return RotetLeft((*sub_tree_));
    }

     /*Left Right Case*/
    if (( (balansed > 1) && (side < 0) ))
    {
        return RotetLeft((*sub_tree_));
    }

     /*Right Left Case*/
    if (( (balansed < -1) && (side < 0) ))
    {
        return RotetLeft((*sub_tree_));
    }

}

size_t AVLHeight(const avl_tree_ty *tree)
{
    assert(tree);

    /* base case: empty tree has a height of 0*/
    if (AVLIsEmpty(tree))
    {
        return 0;
    }
    /*recur for the left and right subtree and consider maximum depth*/
    AVLHeightIMP(tree->m_root);
}

size_t AVLHeightIMP(const avl_node_ty *node)
{  
    return 1 + MaxIMP(AVLHeight(node->m_kids[LEFT]), AVLHeight(node->m_kids[RIGHT]));    
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

void AVLDestroy(avl_tree_ty *avl_tree)
{
    if (NULL != avl_tree->m_root->m_kids[LEFT])
    {
        AVLDestroy(avl_tree->m_root->m_kids[LEFT]);
        AVLDestroy(avl_tree->m_root->m_kids[RIGHT]);
        free(avl_tree->m_root->m_kids[LEFT]);
    }
}


avl_node_ty *FindIMP(const avl_tree_ty *tree ,avl_node_ty *node, void *key)
{
    int res = tree->m_cmp_func(tree->m_root->m_kids[LEFT]->m_data, key, tree->m_param); /*-1, 0, 1*/ 
    /* If the node key matches the requested key - return it  */
    if ( 0 ==  res)
    {
        return tree->m_root->m_kids[LEFT];
    }
    /*call to find with the left or right chiled*/
    return AVLFind(tree->m_root->m_kids[(res > 0)], key); /*res > 0 it's 0 or 1 left or right*/
}

static avl_node_ty *MakeNewNodeIMP(void *elem)
{
    avl_node_ty *new_node = (avl_node_ty *)malloc(sizeof(avl_node_ty));

    new_node->m_kids[RIGHT] = NULL;
    new_node->m_kids[LEFT] = NULL;
    new_node->m_data = elem;
    new_node->m_height = 0;

    return new_node;
}

static void *GetData(avl_node_ty *node)
{
    return node->m_data;
}

avl_node_ty *RotetLeft(avl_node_ty* node_)
{
    avl_node_ty *chile_1 = node_->m_kids[RIGHT];
    avl_node_ty *chile_2 = node_->m_kids[LEFT];

    /*Perform rotation*/
    chile_1->m_kids[LEFT] = node_;
    node_->m_kids[RIGHT] = chile_2;

    /*Update heights*/
    node_->m_height = AVLHeightIMP(node_);
    chile_1->m_height = AVLHeightIMP(chile_1);

    return chile_1;
}

avl_node_ty *RotetRight(avl_node_ty* node_)
{
    avl_node_ty *chile_1 = node_->m_kids[LEFT];
    avl_node_ty *chile_2 = node_->m_kids[RIGHT];

    /*Perform rotation*/
    chile_1->m_kids[RIGHT] = node_;
    node_->m_kids[LEFT] = chile_2;

    /*Update heights*/
    node_->m_height = AVLHeightIMP(node_);
    chile_1->m_height = AVLHeightIMP(chile_1);

    return chile_1;
}