#include <assert.h> /* assert       */
#include <stddef.h> /*	size_t      */ 
#include <stdlib.h> /* malloc, free */

/* Private libraries */
#include "utils.h"

#include "dlist.h"
#include "hash_map.h"

/* Enum */




/* Structs */
struct hash_set
{
    dlist_ty **m_buckets;
    hash_func_ty m_hash_func;
    hash_is_same_func_ty m_match_func;
    const void *m_hash_param;
    size_t m_num_buckets;
};

/**************************** Service functions *******************************/

/* Init hash_set_ struct, handle alloc of dlists. Return 1 if failed, else 0 */
static int HashStructInitIMP(   hash_ty *hash_set_, 
                                const size_t max_size_, 
                                const hash_func_ty hash_func_, 
                                const hash_is_same_func_ty is_same_func_, 
                                const void *param_);

/* Tries to allocate memory for max_size_ buckets. Return 1 if failed, else 0 */
static int FillListWithBucketsIMP(  dlist_ty **bucket_list, 
                                    const size_t max_size_);

/* Free all buckets in m_buckets[] and free m_buckets[] itself */
static void DestroyAllBucketsIMP(hash_ty *hash_set_);

/* Try to find element in bucket- if found, remove. Return 1 if failed, else 0 */
static int FindAndRemoveIMP(dlist_ty *bucket_, 
                            hash_is_same_func_ty match_func_, 
                            const void *elem_key_rmv_);

/* Get correct bucket for elem_ in hash_map */
static dlist_ty *GetBucketIMP(const hash_ty *hash_set_, const void *elem_);

/* Try to put elem_ in bucket. Return 0 if succeeded, 1 if failed */
static int PutInBucketIMP(dlist_ty *bucket_, const void *elem_);

/* Return total number of elements in all buckets */
static size_t GetCombinedSizeOfBuckets( dlist_ty **bucket_list, 
                                        const size_t max_size_);

/* Try to find param in bucket. Return pointer to elem if found, NULL if not */
static void *FindInBucketIMP(   const dlist_ty *bucket_, 
                                hash_is_same_func_ty match_func_, 
                                const void *key_);

/* Call DlistForEach for each mem in bucket. Return 0 for success, 1 for fail */
static int ForEachInBucketIMP(  dlist_ty *bucket_, 
                                hash_op_func_ty op_func_, 
                                void *param_);



hash_ty *HashCreate(size_t max_size_, 
                    hash_func_ty hash_func_, 
                    hash_is_same_func_ty is_same_func_,
                    const void *param_)
{
    hash_ty *hash_set_ = NULL;

    /* Assert */
    assert(0 < max_size_);
    assert(NULL != hash_func_);
    assert(NULL != is_same_func_);

    /* Allocate memory for hash struct */
    hash_set_ = (hash_ty *)malloc(sizeof(hash_ty *));

    /* If alloc failed */
    if (NULL == hash_set_)
    {
        return NULL;
    }
    
    /* If HashStructInitIMP failed */
    if (FUNC_FAILURE == HashStructInitIMP(  hash_set_, 
                                            max_size_, 
                                            hash_func_, 
                                            is_same_func_, 
                                            param_))
    {   
        free(hash_set);
        return NULL;
    }

    /* Return pointer to hash struct */
    return hash_set_;
}

void HashDestroy(hash_ty *hash_set_)
{
    if (NULL == hash_set_)
    {
        return;
    }

    /* Free all buckets */
    DestroyAllBucketsIMP(hash_set_);

    /* Handle dangling pointers in hash_struct */ /* TODO move to side func */
    hash_set_->m_buckets = (dlist_ty **)DEAD_MEM;
    hash_set_->m_hash_func = (hash_func_ty)DEAD_MEM;
    hash_set_->m_match_func = (hash_is_same_func_ty)DEAD_MEM;
    hash_set_->m_hash_param = (const void *)DEAD_MEM;
    hash_set_->m_num_buckets = 0;

    /* Free hash struct */
    free(hash_set_);
}

int HashRemove(hash_ty *hash_set_, const void *elem_key_rmv_)
{   
    dlist_ty *bucket = NULL;

    /* Assert */
    assert(NULL != hash_set_);
    assert(NULL != elem_key_rmv_);

    /* Get correct bucket for elem_ */
    bucket = GetBucketIMP(hash_set_, elem_key_rmv_);

    /* Try to find and remove element (may fail to find) */
    return FindAndRemoveIMP(bucket, hash_set_->m_match_func, elem_key_rmv_);
}

int HashInsert(hash_ty *hash_set_, void *elem_) /* TODO add protection agains repeating elements */
{   
    dlist_ty *bucket = NULL;

    /* Assert */
    assert(NULL != hash_set_);
    assert(NULL != elem_);

    /* Get correct bucket for elem_ */
    bucket = GetBucketIMP(hash_set_, elem_);
    
    /* Return status of PutInBucketIMP */
    return PutInBucketIMP(bucket, elem_);
}

size_t HashSize(const hash_ty *hash_set_)
{   
    /* Assert */
    assert(NULL != hash_set_);
    assert(NULL != hash_set_->m_buckets);

    /* Combined size of buckets */
    return GetCombinedSizeOfBuckets(hash_set_->m_buckets, hash_set_->m_num_buckets);
}

void *HashFind(const hash_ty *hash_set_, const void *key_)
{
    dlist_ty *bucket = NULL;

    /* Assert */
    assert(NULL != hash_set_);
    assert(NULL != key_);

    /* Get correct bucket in hash table */
    bucket = GetBucketIMP(hash_set_, key_);

    /* Try to find param in bucket */
    return FindInBucketIMP(bucket, hash_set_->m_match_func, key_);
}

int HashForEach(hash_ty *hash_set_, hash_op_func_ty op_func_, void *param_)
{
    dlist_ty **curr_bucket = NULL;
    dlist_ty **bucket_list_end = NULL;

    int ret = 0;

    /* Assert */
    assert(NULL != hash_set_);
    assert(NULL != op_func_);

    /* Assign pointers */
    curr_bucket = hash_set_->m_buckets;
    bucket_list_end = curr_bucket + (hash_set_->m_num_buckets);
    while (curr_bucket < bucket_list_end)
    {   
        ret = ForEachInBucketIMP(*curr_bucket, op_func_, param_);
        if (ret != 0) 
        {
            return ret;
        }

        /* Advance curr_bucket */
        ++curr_bucket;
    }
    
    return ret;
}

hash_stats_ty HashStats(const hash_ty *hash_set_)
{
    hash_stats_ty silly_ = {7, 7, 7};

    return silly_;
}

/**************************** Service functions *******************************/

static int HashStructInitIMP(   hash_ty *hash_set_, 
                                const size_t max_size_, 
                                const hash_func_ty hash_func_, 
                                const hash_is_same_func_ty is_same_func_, 
                                const void *param_)
{
    dlist_ty **bucket_list = NULL;

    /* Asserts */
    assert(NULL != hash_set_);
    assert(NULL != hash_func_);
    assert(NULL != is_same_func_);
    assert(0 < max_size_);

    /* Allocate memory */
    bucket_list = (dlist_ty **)malloc(sizeof(dlist_ty *) * max_size_);

    /* If allocation failed */
    if (NULL == bucket_list)
    {
        return FUNC_FAILURE;
    }

    /* Create buckets */
    if (FUNC_FAILURE == FillListWithBucketsIMP(bucket_list, max_size_))
    {
        return FUNC_FAILURE;
    } 

    /* Initialize hash_set_ */
    hash_set_->m_buckets = bucket_list;
    hash_set_->m_hash_func = hash_func_;
    hash_set_->m_match_func = is_same_func_;
    hash_set_->m_hash_param = param_;
    hash_set_->m_num_buckets = max_size_;

    /* If haven't failed yet - success */
    return FUNC_SUCCESS;
}

static int FillListWithBucketsIMP(dlist_ty **bucket, const size_t max_size_)
{   
    dlist_ty **end_of_list = NULL;
    dlist_ty **current_bucket = NULL;

    /* Assert */
    assert(NULL != bucket);
    assert(0 < max_size_);

    /* Define end of list */
    current_bucket = bucket;
    end_of_list = bucket + max_size_;

    while (current_bucket != end_of_list)
    {   
        /* Allocate bucket (doubly linked list) */
        *current_bucket = DlistCreate();

        /* If bucket allocation failed */
        if (NULL == *current_bucket)
        {
            return FUNC_FAILURE;
        }
        
        ++current_bucket;
    }
    
    /* If haven't failed yet - success */
    return FUNC_SUCCESS;
}

static void DestroyAllBucketsIMP(hash_ty *hash_set_)
{   
    dlist_ty **end_bucket_list = NULL;
    dlist_ty **current_bucket = NULL; 

    /* Assert */
    assert(NULL != hash_set_);
    assert(NULL != hash_set_->m_buckets);
    assert(NULL != *hash_set_->m_buckets);

    /* Init bucket list pointers */
    current_bucket = hash_set_->m_buckets;
    end_bucket_list = current_bucket + hash_set_->m_num_buckets;

    while (current_bucket != end_bucket_list)
    {
        DlistDestroy(*current_bucket);
    }
}

static int FindAndRemoveIMP(dlist_ty *bucket_, 
                            hash_is_same_func_ty match_func_, 
                            const void *elem_key_rmv_)
{
    /* Bucket (dlist) iterator */
    iterator_ty found_member = {NULL};

    /* Assert */
    assert(NULL != bucket_);
    assert(NULL != elem_key_rmv_);

    /* Try to find elem in bucket */
    found_member = DlistFind(   DlistBegin(bucket_),
                                DlistEnd(bucket_), 
                                (match_func_ty)match_func_, 
                                (void *)elem_key_rmv_);

    /* If failed - CHECK ITERATOR AND COMPARE TO DUMMY ITERATOR */
    if (IS_TRUE == DlistIsSameIter(found_member, DlistEnd(bucket_)))
    {
        return FUNC_FAILURE;
    }
    
    /* Remove */
    DlistRemove(found_member);

    /* Return 0 */
    return FUNC_SUCCESS;
}

static dlist_ty *GetBucketIMP(const hash_ty *hash_set_, const void *elem_)
{   
    size_t hash_key = 0;

    /* Asserts */
    assert(NULL != hash_set_);
    assert(NULL != hash_set_->m_hash_func);
    assert(NULL != hash_set_->m_buckets);

    /* Pass elem_ through hash_func to get hash_key */
    hash_key = hash_set_->m_hash_func(elem_, hash_set_->m_hash_param);

    /* Normalize hash_key in case user degenerated hash function output */
    hash_key %= hash_set_->m_num_buckets;

    /* Return correct bucket */
    return hash_set_->m_buckets[hash_key];
}

static int PutInBucketIMP(dlist_ty *bucket_, const void *elem_)
{   
    /* Bucket (dlist) iterator */
    iterator_ty member_in_bucket = {NULL};

    /* Assert */
    assert(NULL != bucket_);
    assert(NULL != elem_);

    /* Push back to bucket (dlist) */
    member_in_bucket = DlistPushBack(bucket_, elem_);

    /* Pushback may fail, indecated by member iterator == dummy iterator */
    return (IS_TRUE == DlistIsSameIter(member_in_bucket, DlistEnd(bucket_)));
}

static size_t GetCombinedSizeOfBuckets( dlist_ty **bucket_list_, 
                                        const size_t max_size_)
{
    dlist_ty **end_of_list = NULL;
    dlist_ty **current_bucket = NULL;

    size_t combined_size_ = 0;

    /* Assert */
    assert(NULL != bucket_list_);
    assert(0 < max_size_);

    /* Define end of list */
    current_bucket = bucket_list_;
    end_of_list = bucket_list_ + max_size_;

    while (current_bucket != end_of_list)
    {   
        combined_size_ += DlistSize(*current_bucket);
        
        ++current_bucket;
    }
    
    return combined_size_;   
}

static void *FindInBucketIMP(   const dlist_ty *bucket_, 
                                hash_is_same_func_ty match_func_, 
                                const void *key_)
{
    /* Bucket (dlist) iterator */
    iterator_ty found_member = {NULL};

    /* Assert */
    assert(NULL != bucket_);
    assert(NULL != match_func_);
    assert(NULL != key_);

    /* Try to find in bucket (dlist) */
    found_member = DlistFind(   DlistBegin(bucket_),
                                DlistEnd(bucket_), 
                                (match_func_ty)match_func_, 
                                (void *)key_);
    
    /* If failed to find */
    if (IS_TRUE == DlistIsSameIter(found_member, DlistEnd(bucket_)))
    {
        return NULL;
    }

    return DlistGetData(found_member);
}

static int ForEachInBucketIMP(  dlist_ty *bucket_, 
                                hash_op_func_ty op_func_, 
                                void *param_)
{
    /* Assert */
    assert(NULL != bucket_);
    assert(NULL != op_func_);
    assert(NULL != param_);

    /* Perform for each in bucket, return stat */
    return DlistForEach(DlistBegin(bucket_), 
                        DlistEnd(bucket_), 
                        op_func_, 
                        param_);
}