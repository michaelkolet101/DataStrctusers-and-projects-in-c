#include <assert.h>
#include <stdlib.h> /*malloc free size t mmemset*/
#include <string.h>/*mmemset*/

#include "priorityq.h"
#include "vector.h"

#include "utils.h"

#define DEFALT 50

#define ARRANGED 0
#define NOT_ARRANGED 1

typedef int (*cmp_func_ty)(const void *data1, const void *data2);




struct priorityq
{
    vector_ty *vector;
    cmp_func_ty cmp_func;
};


static void SwapIMP(void **data1, void **data2);
static size_t GetPerentIMP(size_t idx);
static size_t GetLeftChiledIMP(size_t idx);
static size_t GetRightChiledIMP(size_t idx);
static size_t GetMaxIdxIMP(pq_ty *pq);
static size_t GetLastIdxIMP(pq_ty *pq);
static void InsertDummy(pq_ty *pq);

void HeapifyDownIMP(pq_ty *pq, size_t idx);
void HeapifyUPIMP(pq_ty *pq, size_t idx);
void *GetBiggestChiled(pq_ty *pq, void *left, void *right);



pq_ty *PQCreate(int(*cmp_func)(const void *data1, const void *data2))

{
    pq_ty *new_queu = NULL;

    
    
    /*asserts*/
    assert(cmp_func);

    new_queu = (pq_ty *)malloc(sizeof(pq_ty));

    ALLOC_CHK(new_queu, NULL, NULL);
    
    new_queu->vector = VectorCreate(sizeof(void *), DEFALT);
    
    ALLOC_CHK(new_queu->vector, new_queu, NULL);
    
    new_queu->cmp_func = cmp_func;

    /*insert the dummy*/
    InsertDummy(new_queu);

    /*return new_queu*/
    return new_queu;

}

static void InsertDummy(pq_ty *pq)
{
    size_t  n= 5;
    void *p = &n; 
    VectorPushBack(pq->vector , p);
}

void PQDestroy(pq_ty *pq)
{
    VectorDestroy(pq->vector);
    free(pq);
}

int PQEnqueue(pq_ty *pq, const void *data)
{
    size_t idx = 0;

    /*asserts*/
    assert(pq);

    /*We will enter the information at the end of the queue*/
    if (FAIL == VectorPushBack(pq->vector, data))
    {
        return FAIL;
    }

    idx = GetLastIdxIMP(pq);
    
    HeapifyUPIMP(pq, idx);

    return SUCCSES;
}

void *PQDequeue(pq_ty *pq)
{    
    size_t idx = 1;
    void *ret = VectorGetElem(pq->vector, 0);

    /*We will replace the first and last  val */
    SwapIMP(VectorGetElem(pq->vector ,GetLastIdxIMP(pq)), VectorGetElem(pq->vector ,GetMaxIdxIMP(pq)));
    
    /*We will delete the last organ val*/
    VectorPopBack(pq->vector);
    
    HeapifyDownIMP(pq, idx);

    return ret;
}

void HeapifyDownIMP(pq_ty *pq, size_t idx)
{
    size_t status = NOT_ARRANGED;
    size_t max_loops = (VectorSize(pq->vector) - 1) / 2;

    /*We will arrange the val in the right place for it*/
    /* while (node.data is smaller than one of its children)*/
    while ( (NOT_ARRANGED == status) && (idx != max_loops) )
    {
        void *left_child = VectorGetElem(pq->vector, GetLeftChiledIMP(idx));
        void *right_chile = VectorGetElem(pq->vector, GetRightChiledIMP(idx));
        void *curr = VectorGetElem(pq->vector, idx);
        void *biggest_chiled = GetBiggestChiled(pq, left_child, right_chile);
        
        
        /*if the curr is smaller than the biggest chiled*/
        if (0 > pq->cmp_func(biggest_chiled, curr))
        {
            /*swap perent and child*/
            SwapIMP(curr, biggest_chiled);

            /*if the left is big*/
            if ( 0 == pq->cmp_func(left_child, biggest_chiled) )
            {
                idx = GetLeftChiledIMP(idx);
            }
            /*if the right is big*/
            else
            {
                idx = GetRightChiledIMP(idx);    
            }   
        }
        else
        {
            status = ARRANGED;
        }
    }
}

void HeapifyUPIMP(pq_ty *pq, size_t idx)
{
    size_t status = NOT_ARRANGED;

    while ( (NOT_ARRANGED == status) && (idx != 1) )
    {
        void *perent = VectorGetElem(pq->vector,  GetPerentIMP(idx));
        void *curr = VectorGetElem(pq->vector,  idx);

            /*if curr is bigger from perent*/
         if (0 > pq->cmp_func(curr, perent))
         {
             /*swap curr and perent*/
             SwapIMP(&curr , &perent);
             idx = GetPerentIMP(idx);
         }
         else
         {
             status = ARRANGED;
         }
    }
}

void *PQPeek(const pq_ty *pq)
{
    /*asserts*/
    assert(pq->vector);
    assert(!PQIsEmpty(pq));

    return VectorGetElem(pq->vector, 1);
}

int PQIsEmpty(const pq_ty *pq)
{   
    /*asserts*/
    assert(pq->vector);

    return 1 == PQSize(pq); 
}

size_t PQSize(const pq_ty *pq)
{
    /*asserts*/
    assert(pq->vector);

    return VectorSize(pq->vector) - 1;
}

void PQClear(pq_ty *pq)
{
    /*asserts*/
    assert(pq->vector);

    while (!PQIsEmpty(pq))
    {
        VectorPopBack(pq->vector);   
    }
}

void *PQErase(pq_ty *pq, int(*match_func)(const void *data1, void *param), void *param)
{
    size_t i = 1;
    void *ret_val = NULL;
    size_t left_element_to_check = VectorSize(pq->vector);

    void *last = VectorGetElem(pq->vector, GetLastIdxIMP(pq));
    /*asserts*/
    assert(pq);

    while ( (i < left_element_to_check) )
    {
        void **the_end = &last;
        void **to_delete = NULL;

        /*if it's match*/
        if (SUCCSES == match_func(VectorGetElem(pq->vector, i), param))
        {
            /*keep to return*/
            ret_val = VectorGetElem(pq->vector, i);
            to_delete = &ret_val;
            
            /*swap with the last val*/
            SwapIMP(to_delete, the_end);

            /*delete the value*/
            VectorPopBack(pq->vector);
            
            HeapifyDownIMP(pq, i);
        }

        ++i;
    }

    return ret_val;
}

void HeapSort(pq_ty *pq)
{
    /*Remove the root from the pile, and place it in the largest free position in the array*/
    /*The last organ in the structure is removed and placed in place of the removed root*/
    /*Performs a Heapify operation*/

}



void *GetBiggestChiled(pq_ty *pq, void *left, void *right)
{
    if (0 > pq->cmp_func(left, right))
    {
        return left;
    }
    return right;
    
}

static void SwapIMP(void **data1, void **data2)
{
    void *tmp = *data1;
    *data1 = *data2;
    *data2 = tmp;
}

static size_t GetMaxIdxIMP(pq_ty *pq)
{
    return 1;
}

static size_t GetLastIdxIMP(pq_ty *pq)
{
    return (PQSize(pq) - 1);
}  

static size_t GetPerentIMP(size_t idx)
{
    return idx / 2;
}

static size_t GetLeftChiledIMP(size_t idx)
{
    return (2 * idx);
}

static size_t GetRightChiledIMP(size_t idx)
{
    return (2 * idx + 1);
}

