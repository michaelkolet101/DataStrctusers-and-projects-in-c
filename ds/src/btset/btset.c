#include <stdlib.h> /*malloc , free*/
#include <assert.h> /* assert */

#include "btset.h"
#include "utils.h"

/* psudocode */

struct binary_tree_node
{
    bt_node_ty *family[3]; /*family[0]=LEFT ,family[1]=RIGHT ,family[2]=PARENT*/
    void *m_data;
};

struct binary_tree_set
{
    bt_node_ty *m_root;
    bts_cmp_fnc_ty m_cmp_dunc;
    void *m_cmp_param;
};

enum
{
    EQUAL = -1,
    LEFT = 0,
    RIGHT = 1,
    PARENT = 2
};

typedef struct return_place_and_side
{
    bt_node_ty *m_parent;
    int m_left_or_right;       
}r_p_side_ty;


/**************************************************************************/
/* service functions */
static bt_node_ty *CreateChildNodeIMP(bt_node_ty *parent_,void *data_);

static void ClearTreeIMP(btset_ty *set_);

/* return as a struct */
static r_p_side_ty FindIMP(btset_ty *set_, const void *key_element_);

static int ThereIsChildIMP(bt_node_ty *parent_, int left_or_right_);

static bt_node_ty *GetChildIMP(bt_node_ty *where_ , int left_or_right_);

static bt_node_ty *GetParentsIMP(bt_node_ty *child_node_);

static bt_node_ty *GetChildIMP(bt_node_ty *where_ , int left_or_right_);

static bt_node_ty *GetChildUntilEndIMP(bt_node_ty *where_, int left_or_right_);

static bt_node_ty *AttachChildIMP(bt_node_ty *where_, bt_node_ty *parent_);

static bt_node_ty *AttachParentIMP(bt_node_ty *parent_,bt_node_ty *child_ ,int left_or_right_);

static int IsChildFromSideIMP(bt_node_ty *child_, 
                              bt_node_ty *parent_
                             ,int left_or_right_);

static int HasNoChildrenIMP(bt_node_ty *where_);

static int HasTwoChildrenIMP(bt_node_ty *where_);

static int WhatSideIsValidIMP(bt_node_ty *where_);


/**************************************************************************/

btset_ty *BTSetCreate(bts_cmp_fnc_ty cmp_fnc, const void *cmp_param)
{
    /* create the metadata and the dummy */
    btset_ty *ret = (btset_ty *)malloc(sizeof(btset_ty));
	ret->m_root = CreateChildNodeIMP(NULL, NULL);
	
    /* check alloctions if fail */
   if ((ret == NULL ||& ret->m_root == NULL))
   {
		free(ret);
		free(ret->m_root);
		
		return NULL;
   }

    /* init struct members */
   
    /* Spacial case which ill be using the AttachParentIMP func to dummy */
    AttachParentIMP((bt_node_ty *)ret, ret->m_root, RIGHT);

    ret->m_cmp_dunc = cmp_fnc;
    ret->m_cmp_param = (void *)cmp_param;

    /* return ret */
    return ret;
}

void BTSetDestroy(btset_ty *set)
{
    /* assert user input */
    assert(set);

    /* ClearTree(set) */

    /* free(metadata) */
    free(set);        
}

btset_iter_ty BTSetInsert(btset_ty *set, void *element)
{
    btset_iter_ty ret = {NULL};

    r_p_side_ty get_info = {NULL};
    
    assert(set);
    
    get_info = FindIMP(set, element);

    if(EQUAL == get_info.m_left_or_right)
    {
        return BTSetEnd(set);
    }

    /* create child node and attach parent */
    ret.node = CreateChildNodeIMP(get_info.m_parent, element); 

    /* attach parent to child */          
    AttachParentIMP(get_info.m_parent, ret.node, get_info.m_left_or_right);

    return ret;    
}

btset_iter_ty BTSetRemove(btset_ty *set, btset_iter_ty where)
{
    bt_node_ty *parent = NULL;

    assert(set);
    assert(where.node);

    /* no child at any side */
    if(HasNoChildrenIMP(where.node))
    {
        parent = GetParentsIMP(where.node);

        free(where.node);

        where.node = parent;
    }
    
    if(!HasTwoChildrenIMP(where.node) && !HasNoChildrenIMP(where.node))
    { 
        /* save the node */
        parent = where.node;

        /* copy the child data to the node and remove the child */
        where.node = GetChildIMP(where.node, WhatSideIsValidIMP(where.node));
        parent->m_data = where.node->m_data;


        /*remove the child */
        free(where.node);

        /* return the same node */ 
        where.node = parent;       
    }
    if(HasTwoChildrenIMP(where.node))
    {
        /* save the node */
        parent = where.node;

        /* copy the child data from the left most right child*/
        where.node = GetChildIMP(where.node, RIGHT);
        where.node = GetChildUntilEndIMP(where.node, LEFT);

        parent->m_data = where.node->m_data;


        /*remove the child */
        free(where.node);

        /* return the same node */ 
        where.node = parent;

    }

    return where;              
}

btset_iter_ty BTSetFind(btset_ty *set, const void *key_element)
{
    btset_iter_ty ret = {NULL};
    r_p_side_ty get_info = {NULL};

    assert(set);

    get_info = FindIMP(set, key_element);     

    if(EQUAL == get_info.m_left_or_right)
    {
        ret.node = get_info.m_parent;

        return ret;
    }

    /*RETURN DUMMY IF FAIL*/
    return BTSetEnd(set); 
}

size_t BTSetSize(const btset_ty *set)
{
    btset_iter_ty curr_iter = BTSetBegin((btset_ty *)set);
    size_t counter = 0;

    /* assert user input */
    assert(set);

    while(BTSetIsSameIter(curr_iter, BTSetEnd((btset_ty *)set)))
    {
        ++counter;
        curr_iter = BTSetNext(curr_iter);        
    }
    
    /* return counter */
    return counter;
}

btset_iter_ty BTSetBegin(btset_ty *set)
{
    btset_iter_ty ret = {NULL};

    /* assert user input */
    assert(set);
    assert(!BTSetIsEmpty(set));
    
    ret.node = set->m_root;

    while(ThereIsChildIMP(ret.node, LEFT))
    {
        ret.node = GetChildIMP(ret.node, LEFT);
    }

    return ret;
}

btset_iter_ty BTSetEnd(btset_ty *set)
{
    btset_iter_ty ret = {NULL};

    /* assert user input */
    assert(set);

    ret.node = set->m_root;

    return ret;
}

btset_iter_ty BTSetNext(btset_iter_ty iterator_to_inc)
{
    if(ThereIsChildIMP(iterator_to_inc.node, RIGHT))
    {
        iterator_to_inc.node = GetChildIMP(iterator_to_inc.node, RIGHT);
        iterator_to_inc.node = GetChildUntilEndIMP(iterator_to_inc.node, LEFT);

        return iterator_to_inc;          
    }
    /* go until child is no longer the right son of parent */
    while(IsChildFromSideIMP(iterator_to_inc.node, 
                                    GetParentsIMP(iterator_to_inc.node), RIGHT))
    {
        iterator_to_inc.node = GetParentsIMP(iterator_to_inc.node);        
    }

    return iterator_to_inc;

}

btset_iter_ty BTSetPrev(btset_iter_ty iterator_to_dec)
{
    if(ThereIsChildIMP(iterator_to_dec.node, LEFT))
    {
        iterator_to_dec.node = GetChildIMP(iterator_to_dec.node, LEFT);
        iterator_to_dec.node = GetChildUntilEndIMP(iterator_to_dec.node, RIGHT);

        return iterator_to_dec;          
    }
    /* go until child is no longer the left son of parent */
    while(IsChildFromSideIMP(iterator_to_dec.node, 
                                    GetParentsIMP(iterator_to_dec.node), LEFT))
    {
        iterator_to_dec.node = GetParentsIMP(iterator_to_dec.node);        
    }

    return iterator_to_dec;
}


int BTSetIsSameIter(btset_iter_ty first, btset_iter_ty second)
{
    return first.node == second.node;
}

int BTSetIsIterBad(btset_iter_ty check)
{
    return GetParentsIMP(check.node) == NULL; 
}

void *BTSetGetData(btset_iter_ty where)
{
    return where.node->m_data;
}

int BTSetIsEmpty(const btset_ty *set)
{
    return !ThereIsChildIMP(set->m_root, LEFT);
}

/* check every time you call this func if alloc fail */
static bt_node_ty *CreateChildNodeIMP(bt_node_ty *parent_,void *data_)
{
    bt_node_ty *ret = (bt_node_ty *)malloc(sizeof(bt_node_ty));
	
	if (ret == NULL)
	{
		return NULL;
	}
	
    ret->m_data = data_;
    ret->family[PARENT] = parent_;

    ret->family[LEFT] = NULL;       
    ret->family[RIGHT] = NULL;        

    return ret;
}

static void ClearTreeIMP(btset_ty *set_)
{
  
}

static r_p_side_ty FindIMP(btset_ty *set_, const void *key_element_)
{
    btset_iter_ty curr = {NULL};
    
    /* to save the parent of the child and the side  */
    r_p_side_ty ret = {NULL};   

    /* curr.node start in root */
    curr.node = set_->m_root->family[LEFT];

    /* start in root */
    ret.m_parent = set_->m_root;
    ret.m_left_or_right = LEFT;

    while(NULL != curr.node)
    {
         ret.m_parent = curr.node;
         
        if(0 == set_->m_cmp_dunc(curr.node->m_data, key_element_, set_->m_cmp_param))
        {
            ret.m_left_or_right = EQUAL;

            return ret;       
        } 

        ret.m_left_or_right = (set_->m_cmp_dunc(curr.node->m_data, key_element_, set_->m_cmp_param) > 0);
        curr.node = GetChildIMP(curr.node, ret.m_left_or_right);        
    }

    return ret;        
}

static int ThereIsChildIMP(bt_node_ty *parent_, int left_or_right_)
{
    return parent_->family[left_or_right_] != NULL;       
}

static bt_node_ty *GetChildIMP(bt_node_ty *where_ , int left_or_right_)
{
    return where_->family[left_or_right_];
}

static bt_node_ty *GetParentsIMP(bt_node_ty *child_node_)
{
    return child_node_->family[2];    
}

static bt_node_ty *GetChildUntilEndIMP(bt_node_ty *where_, int left_or_right_)
{
    bt_node_ty *curr = where_;

    while(ThereIsChildIMP(where_, left_or_right_))
    {
        curr = GetChildIMP(curr, left_or_right_);
    }

    return curr;
}

static int IsChildFromSideIMP(bt_node_ty *child_, 
                              bt_node_ty *parent_
                             ,int left_or_right_)
{
    return (parent_ + left_or_right_ == child_ ); 
}

static int HasNoChildrenIMP(bt_node_ty *where_)
{
    return !ThereIsChildIMP(where_, RIGHT) && 
           !ThereIsChildIMP(where_, LEFT); 
}

static int HasTwoChildrenIMP(bt_node_ty *where_)
{
    return ThereIsChildIMP(where_, RIGHT) && 
           ThereIsChildIMP(where_, LEFT); 
}

static int WhatSideIsValidIMP(bt_node_ty *where_)
{
    if(ThereIsChildIMP(where_, RIGHT))
    {
        return RIGHT;
    }  

    return LEFT;
}

static bt_node_ty *AttachChildIMP(bt_node_ty *where_, bt_node_ty *parent_)
{
    where_->family[PARENT] = parent_;

    return where_;     
}

static bt_node_ty *AttachParentIMP(bt_node_ty *parent_,bt_node_ty *child_ , int left_or_right_)
{
    parent_->family[left_or_right_] = child_;

    return parent_;    
}
