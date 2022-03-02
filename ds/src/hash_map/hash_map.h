#include <stdlib.h>
#include "dlist.h"

#ifndef __HASH_MAP_H__
#define __HASH_MAP_H__


typedef struct hash hash_ty; 

typedef int(*hash_is_same_func_ty)(const void *key1, const void *key2);

typedef size_t (*hash_func_ty)(const void *elem, const void *param);

typedef int (*hash_op_func_ty)(void *elem, void *op_param);

typedef struct stats
{
    int m_longest_list;
    int m_b;
    int m_c;
}hash_stats_ty;






/* Recommended that max_size is a prime number 1!*/
hash_ty *HashCreate(size_t max_size,
                    hash_func_ty hash_func,
                    hash_is_same_func_ty is_same_func,
                    const void *param);

/*  null is allowed 4! */
void HashDestroy(hash_ty *hash_set);

/*   if fails to find elem returns 1, else returns 0    8!*/
/*   int(*is_same)(const void *key1, const void *key2) */
int HashRemove(hash_ty *hash_set, const void *elem_key_rmv);

/*   assert that not same with int(*is_same)(const void *key1, const void *key2) 2! */
int HashInsert(hash_ty *hash_set, void *elem);

/* 6! */
size_t HashSize(const hash_ty *hash_set);

/*  returns ptr to data, NULL if fails 3! */
void *HashFind(const hash_ty *hash_set, const void *key_);

/*  1 on failure */
/*  if fails all of the elements post failure point remain untouched. 5! */
int HashForEach(hash_ty *hash_set, hash_op_func_ty op_func, void *param);

/*  contains stats of average list, max list, etc.. 7!*/
/*  ATM returns 7 */
hash_stats_ty HashStats(const hash_ty *hash_set);


#endif /*__HASH_MAP_H__*/