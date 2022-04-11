
#include <stdlib.h>/*malloc free*/
#include <assert.h>
#include "btset.h"





/*
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
*/

struct binary_tree_set
{
    bt_node_ty *root;
    bts_cmp_fnc_ty cmp_func;
    void *param;
};

struct binary_tree_node
{
    bt_node_ty *family[3]; /*family[0]=LEFT ,family[1]=RIGHT ,family[2]=PARENT*/
    void *m_data;
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


/****************************************************/
static bt_node_ty *CreateChildNodeIMP(bt_node_ty *parent_,void *data_);


static bt_node_ty *MoveToPerntIMP(bt_node_ty *child);
static bt_node_ty *LeftChildIMP(bt_node_ty *perrent);
static bt_node_ty *RightChildIMP(bt_node_ty *perrent);

static bt_node_ty *NextIsDownIMP(bt_node_ty *runner);
static bt_node_ty *NextIsUpIMP(bt_node_ty *runner);

static bt_node_ty *CreatNodeIMP();
static bt_node_ty *InsertNodeIMP(bt_node_ty *perent, void *data);

static void *GetDataIMP(bt_node_ty *node);
static bt_node_ty *FindIMP(btset_ty *set, void *elem);
static void ConcatIMP(bt_node_ty *node, bt_node_ty *parent, int side);
/**************************************************/

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
    btset_ty *new_set = (btset_ty *)malloc(sizeof(btset_ty)); 
    bt_node_ty* dummy = CreatNodeIMP();

    assert(cmp_param);

    if ((NULL == new_set) || (NULL == dummy))
    {
        free(new_set);
        free(dummy);
        return NULL;
    }
    
    dummy->m_data = NULL;

    /*We will initialize the members of the struct*/
    new_set->root = dummy;
    new_set->cmp_func = cmp_fnc;
    new_set->param = (void *)cmp_param;

    /*We will return the pointer to the root    */
    return new_set;
}

btset_iter_ty BTSetInsert(btset_ty *set, void *element)
{
    /* is_add equal to 0*/
    int is_add = 0;
    btset_iter_ty itr_ret_val;
    bt_node_ty *runner = set->root;
    bt_node_ty *save_place = runner;

    assert(set);
    assert(element);
    
    /*Loop that ran until is_add equals 1*/
    while (0 == is_add)
    {
    
        /*if is the first node in set*/
        if (1 == BTSetIsEmpty(set) )
        {
            runner = InsertNodeIMP(set->root->family[0], element);
            is_add = 1;
        }

        else if ((set->cmp_func(runner->m_data , element, set->param)) > 0)
        {
             /*We will check if the place is available */
            if (NULL == LeftChildIMP(runner))
            {
                /*If yes: 
                we will insert the new node and status equals 1 */
                /*Values ​​are given to the various pointers at the node*/

                runner = InsertNodeIMP(runner, element);
                is_add = 1;
            }    
            else
            {
              save_place = runner; 
              runner = RightChildIMP(runner);
            }
        }

        /*if not: 
        We will check if the value at the inserted node is
        greater than the value at the current node*/
         /*We will progress to the next child accordingly*/

        else if ((set->cmp_func(GetDataIMP(runner) , element, set->param)) < 0)
        {
    
             /*We will check if the place is available */
             if (NULL == RightChildIMP(runner))
            {
                /*If yes: 
                    we will insert the new node and status equals 1 */
                /*Values ​​are given to the various pointers at the node*/
                is_add = 1;
                runner = InsertNodeIMP(runner, element);
            }     
            else
            {
                save_place = runner;
                runner = RightChildIMP(runner);
            }
        }
        
        if ((set->cmp_func(GetDataIMP(runner) , element, set->param)) == 0)
        {
            itr_ret_val.node = NULL;
        }
    }
    
    itr_ret_val.node = runner;

    /*return iterator*/
    return itr_ret_val;
}


static void ConcatIMP(bt_node_ty *node, bt_node_ty *parent, int side)
{
    parent->family[side] = node;
    node->family[2] = parent;
}


size_t BTSetSize(const btset_ty *set)
{
    btset_iter_ty runner = {NULL};
    size_t count = 0;

    assert(set);

    if (!BTSetIsEmpty(set))
    {
        count = 1;
    }
    
    runner = BTSetBegin((btset_ty *)set);
    
    while ((NULL != LeftChildIMP(runner.node)) && (NULL != RightChildIMP(runner.node)))
    {
        ++count;
        runner = BTSetNext(runner);    
    }
    
    return count;
}


btset_iter_ty BTSetFind(btset_ty *set, const void *key_element)
{
    btset_iter_ty ret_itr;

    assert(set);
    assert(key_element);

    ret_itr.node = FindIMP(set, (void *)key_element);

    return ret_itr;
}

/* Return value: iterator to the next element */
btset_iter_ty BTSetRemove(btset_ty *set, btset_iter_ty where)
{
    /*if Node to be deleted is the leaf  or without chiled: 
        Simply remove from the tree. */

    /*if Node to be deleted has only one child: 
    Copy the child to the node and delete the child */

 ;   /*if Node to be deleted has two children:*/
    /* Find the next of the node. */
    /* Copy contents of the next to the node*/
    /* delete the next.*/
    
}

btset_iter_ty BTSetEnd(btset_ty *set)
{
    /* We will set an iterator for SET */
    btset_iter_ty ret_itr = {NULL};

    assert(set);

    ret_itr.node = set->root->family[0];
    /* As long as the next step to the right is not NULL we will go right */
    
    while (NULL == RightChildIMP(ret_itr.node))
    {
        ret_itr.node = RightChildIMP(ret_itr.node);
    }
    
    /* We return the iterator and up to one step to the right */
    return ret_itr;
}


btset_iter_ty BTSetBegin(btset_ty *set)
{
    btset_iter_ty ret_itr;

    assert(set);

    ret_itr.node = set->root->family[0];

    while (LeftChildIMP(ret_itr.node) != NULL)
    {
      
        ret_itr.node = LeftChildIMP(ret_itr.node);
    }

    return ret_itr;    
}


btset_iter_ty BTSetNext(btset_iter_ty iterator_to_inc)
{
    bt_node_ty *runner = iterator_to_inc.node;
    
    assert(iterator_to_inc.node);

    /* We will go right one step */
    if (NULL != RightChildIMP(runner))
    {
        runner = NextIsDownIMP(runner);
    }
    else
    {    
        runner = NextIsUpIMP(runner);
    }

    iterator_to_inc.node = runner;

   /* We will exit the loop and return an iterator */
   return iterator_to_inc;
}

btset_iter_ty BTSetPrev(btset_iter_ty iterator_to_dec)
{
    /* We will take one step left */
    bt_node_ty *runner = iterator_to_dec.node;

    assert(iterator_to_dec.node);

/* We will check if there is a right value */
    if (NULL != RightChildIMP(runner))
    {
        runner = NextIsDownIMP(runner);
    }
    else
    {    
        runner = NextIsUpIMP(runner);
    }
}

int BTSetIsSameIter(btset_iter_ty first, btset_iter_ty second)
{
    assert(first.node);
    assert(second.node);
    /* We will check if the iterators are equal and we will 
                            return 1 otherwise we will return 0 */
    return (first.node->family[0] == second.node->family[0]) && (first.node->family[1] == second.node->family[1]);
}

void *BTSetGetData(btset_iter_ty where)
{
    assert(where.node);
/* We will return the information through the iterator */
    return GetDataIMP(where.node);
}

int BTSetIsIterBad(btset_iter_ty check)
{
    
    return MoveToPerntIMP(check.node) == NULL;
}

int BTSetIsEmpty(const btset_ty *set)
{
    assert(set);
/* If the value of SET NULL it is dummy and 
                    we return 1 otherwise we return 0 */
    return set->root->family[0] == NULL; 
}

/**********************************************************************************/

static bt_node_ty *CreatNodeIMP()
{
    bt_node_ty *Node = (bt_node_ty *)malloc(sizeof(bt_node_ty));
    if (NULL == Node)
    {
        return NULL;
    }
    
    Node->family[2] = NULL;
    Node->family[1] = NULL;
    Node->family[0] = NULL;
    Node->m_data = NULL;

    return Node;
} 

static bt_node_ty *MoveToPerntIMP(bt_node_ty *child)
{
    return child->family[2];
}

static bt_node_ty *LeftChildIMP(bt_node_ty *perrent)
{
    return perrent->family[0];
}

static bt_node_ty *RightChildIMP(bt_node_ty *perrent)
{
    return perrent->family[1];
}

static void *GetDataIMP(bt_node_ty *node)
{
    return node->m_data;
}

static bt_node_ty *NextIsUpIMP(bt_node_ty *runner)
{
    bt_node_ty *perent = runner->family[2];
    bt_node_ty *child = runner;

    while (perent->family[1] = child)
    {
       child = perent;
       perent = child->family[2];
    }
    
    return perent;
}  
 
static bt_node_ty *NextIsDownIMP(bt_node_ty *runner)
{
     runner = RightChildIMP(runner);

    /* We will check if there is a left value */   
    /* If yes, then loop as long as the value is not NULL */
    /* We will step left IN LOOP */
    while (NULL != LeftChildIMP(runner))
    {
         /* We will step left */
        runner = LeftChildIMP(runner);
    }

    return runner;
}

static bt_node_ty *PrevIsUpIMP(bt_node_ty *runner)
{
    bt_node_ty *perent = runner->family[2];
    bt_node_ty *child = runner;

    while (perent->family[0] = child)
    {
       child = perent;
       perent = child->family[2];
    }
    
    return perent;
}  
 
static bt_node_ty *PrevIsDownIMP(bt_node_ty *runner)
{
     
     if (NULL != LeftChildIMP(runner))
     {
         runner = LeftChildIMP(runner);
     }
     
    /* We will check if there is a right value */   
    /* If yes, then loop as long as the value is not NULL */
    /* We will step right IN LOOP */
    while (NULL != RightChildIMP(runner))
    {
         /* We will step right */
        runner = RightChildIMP(runner);
    }

    return runner;
}

static bt_node_ty *InsertNodeIMP(bt_node_ty *perent, void *data)
{
    /*creat a new node*/
    bt_node_ty *new_node = CreatNodeIMP();

    /*new node perent equal to perent*/
    new_node->family[2] = perent;

    /*new node data equal to data*/
    new_node->m_data = data;

    /*return new node*/
    return new_node;
}

static bt_node_ty *FindIMP(btset_ty *set, void *elem)
{
    /*def node to return equal to the root - not dummy*/
    bt_node_ty *ret_node = set->root->family[0];

    /*As long as the node is not equal to NULL*/
    while (NULL != ret_node)
    {
        /*def ret_from_cmp_func the parmetes are root->m_data, elem, NULL*/
        int ret_from_cmp_func = set->cmp_func(set->param, elem, NULL);

        /*if ret_from_cmp_func equal to 0 then return*/
        if (0 == ret_from_cmp_func)
        {
            return ret_node;
        }

        /*if big from 0 move to right child*/
        if (0 < ret_from_cmp_func)
        {
            ret_node = RightChildIMP(ret_node);
        }

        /*if small from 0 move to left child*/
        if (0 > ret_from_cmp_func)
        {
            ret_node = LeftChildIMP(ret_node);
        }
                
        /*return the node to return*/   
        return ret_node;
    }
}
