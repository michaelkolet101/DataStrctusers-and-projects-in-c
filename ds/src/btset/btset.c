
#include <stdlib.h>/*malloc free*/
#include "btset.h"



struct binary_tree_set
{
    bt_node_ty *root;
    bts_cmp_fnc_ty cmp_func;
    void *param;
};

struct binary_tree_node
{
    bt_node_ty *right;
    bt_node_ty *left;
    bt_node_ty *perrent;
    void *data; 
};


/****************************************************/
static bt_node_ty *MoveToPerntIMP(bt_node_ty *child);
static bt_node_ty *LeftChildIMP(bt_node_ty *perrent);
static bt_node_ty *RightChildIMP(bt_node_ty *perrent);

static bt_node_ty *NextIsDownIMP(bt_node_ty *runner);
static bt_node_ty *NextIsUpIMP(bt_node_ty *runner);

static bt_node_ty *CreatNodeIMP();
static bt_node_ty *InsertNodeIMP(bt_node_ty *perent, void *data);

static void *GetDataIMP(bt_node_ty *node);
static bt_node_ty *FindIMP(btset_ty *set, void *elem);
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

    if ((NULL == new_set) || (NULL == dummy))
    {
        free(new_set);
        free(dummy);
        return NULL;
    }
    
    dummy->data = NULL;

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

    /*We will allocate space for a new node*/
    bt_node_ty *new_node = CreatNodeIMP();
    new_node->data = element;

    /*if is the first node in set*/
    if (1 == BTSetIsEmpty(set) && NULL != new_node)
    {
        set->root->left = new_node;
        new_node->perrent = set->root;
        itr_ret_val.node = new_node;

        /*printf("src 108 %d\n", *(int*)runner->data);*/
        return itr_ret_val;
    }

    /*Loop that ran until is_add equals 1*/
    while (0 == is_add)
    {

        if ((set->cmp_func(GetDataIMP(runner) , element, set->param)) > 0)
        {
            runner = LeftChildIMP(runner);
            runner->perrent = save_place;
             /*We will check if the place is available */
            if (NULL == runner)
            {
                /*If yes: 
                    we will insert the new node and status equals 1 */
                /*Values ​​are given to the various pointers at the node*/
                is_add = 1;
                runner->data = element;
                new_node = runner;
                 
            }    
        }

        /*if not: 
        We will check if the value at the inserted node is
        greater than the value at the current node*/
         /*We will progress to the next child accordingly*/

        if ((set->cmp_func(GetDataIMP(runner) , element, set->param)) < 0)
        {
            runner = RightChildIMP(runner);
            runner->perrent = save_place;
             /*We will check if the place is available */
             if (NULL == runner)
            {
                /*If yes: 
                    we will insert the new node and status equals 1 */
                /*Values ​​are given to the various pointers at the node*/
                is_add = 1;
                runner->data = element;
                new_node = runner; 
            }    
            
        }
        
        if ((set->cmp_func(GetDataIMP(runner) , element, set->param)) == 0)
        {
            itr_ret_val.node = NULL;
        }
    }
    itr_ret_val.node = new_node;

/*return iterator*/
    return itr_ret_val;
}

size_t BTSetSize(const btset_ty *set)
{
    btset_iter_ty runner = {NULL};
    size_t count = 0;

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
    ret_itr.node = set->root->left;
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

    ret_itr.node = set->root->left;

    while (LeftChildIMP(ret_itr.node) != NULL)
    {
      
        ret_itr.node = LeftChildIMP(ret_itr.node);
    }

    return ret_itr;    
}


btset_iter_ty BTSetNext(btset_iter_ty iterator_to_inc)
{
    bt_node_ty *runner = iterator_to_inc.node;
    
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
    /* We will check if the iterators are equal and we will 
                            return 1 otherwise we will return 0 */
    return (first.node->left == second.node->left) && (first.node->right == second.node->right);
}

void *BTSetGetData(btset_iter_ty where)
{
/* We will return the information through the iterator */
    return GetDataIMP(where.node);
}

int BTSetIsIterBad(btset_iter_ty check)
{
    
    return MoveToPerntIMP(check.node) == NULL;
}

int BTSetIsEmpty(const btset_ty *set)
{
/* If the value of SET NULL it is dummy and 
                    we return 1 otherwise we return 0 */
    return set->root->left == NULL; 
}

/**********************************************************************************/

static bt_node_ty *CreatNodeIMP()
{
    bt_node_ty *Node = (bt_node_ty *)malloc(sizeof(bt_node_ty));
    if (NULL == Node)
    {
        return NULL;
    }
    
    Node->perrent = NULL;
    Node->right = NULL;
    Node->left = NULL;
    Node->data = NULL;

    return Node;
} 

static bt_node_ty *MoveToPerntIMP(bt_node_ty *child)
{
    return child->perrent;
}

static bt_node_ty *LeftChildIMP(bt_node_ty *perrent)
{
    return perrent->left;
}

static bt_node_ty *RightChildIMP(bt_node_ty *perrent)
{
    return perrent->right;
}

static void *GetDataIMP(bt_node_ty *node)
{
    return node->data;
}

static bt_node_ty *NextIsUpIMP(bt_node_ty *runner)
{
    bt_node_ty *perent = runner->perrent;
    bt_node_ty *child = runner;

    while (perent->right = child)
    {
       child = perent;
       perent = child->perrent;
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
    bt_node_ty *perent = runner->perrent;
    bt_node_ty *child = runner;

    while (perent->left = child)
    {
       child = perent;
       perent = child->perrent;
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
    new_node->perrent = perent;

    /*new node data equal to data*/
    new_node->data = data;

    /*return new node*/
    return new_node;
}

static bt_node_ty *FindIMP(btset_ty *set, void *elem)
{
    /*def node to return equal to the root - not dummy*/
    bt_node_ty *ret_node = set->root->left;

    /*As long as the node is not equal to NULL*/
    while (NULL != ret_node)
    {
        /*def ret_from_cmp_func the parmetes are root->data, elem, NULL*/
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