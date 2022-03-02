#include <stdlib.h> /*size_t malloc free*/

#include "hash_map.h"




struct hash
{
    dlist_ty **m_lists;
    size_t m_num_lists;
    hash_func_ty *m_hash_func;
    hash_is_same_func_ty m_is_same_func;
    const void *m_hash_param;
};

hash_ty *HashCreate(size_t max_size,
                    hash_func_ty hash_func,
                    hash_is_same_func_ty is_same_func,
                    const void *param)
{
    /*asserts*/
    
    /*maloc size hash ty*/
    hash_ty *new_hash = (hash_ty *)malloc(sizeof(hash_ty));

    /*check allocation*/
    if (NULL == new_hash)
    {
        return NULL;
    }
    
    /*init members*/
    new_hash->m_hash_func = hash_func;
    new_hash->m_hash_param = param;
    new_hash->m_is_same_func = is_same_func;
    new_hash->m_num_lists = max_size;
    new_hash->m_lists = (dlist_ty* )malloc(sizeof(max_size));

    if (new_hash->m_lists == NULL)
    {
        free(new_hash);
        return NULL;
    }
    
    /*return hash*/
    return new_hash;
}

int HMInsert(int *hash_map, void *elem)
{

    /*call to hash func and get idx*/
    
    /*asserts*/

    /*DlistCreate int the idx*/

    /*return DlistPushBack()*/
}

void HashDestroy(hash_ty *hash_set)
{
    /*move over the arry with loop*/
    /*save the pointer curr*/
    /*jamp to next*/
    /*destroy the linked list in curr*/
    /*free the curr*/

    /*free the hash*/
}

int HMRemove(hash_ty *hash, const void *key_elem)
{
    /*asserts*/
    
    /*send find_param to hash_func, get the hash val*/
    /*in the idx in array use DlistFind 
    with is_same_finc and find param*/

/*if its fail*/
    /*return Fail*/
    
    /*return succses*/
}

size_t HMSize(hash_ty *hash)
{
    /*det count*/
    /*loop over the arr*/
    /*if idx not null*/
    /*count += DlistSize*/
    /*return count*/
}

void *HMFind(hash_ty *hash, void *to_find)
{
    /*asserts*/
    /*send find_param to hash_func, get the hash val*/
    /*in the idx in array use DlistFind with is_same_finc and find param*/
    /*return DlistGetData*/
}

int ForEach(hash_ty *hash, int(*op_func)(void*, void*))
{
   /*asserts*/
   /*for each element in hash array */
    /*status = dlistforeach()*/ 
    /*return status*/
}

hash_stats_ty HashStats(const hash_ty *hash_set)
{
    hash_stats_ty nonsense = {7,7,7};

    return nonsense;
}