/*******************************************************************************
Data Structures WorkSheet 3: vector.

Written by: Michael Kolet
Reviewd by: daniel

Functions for WS
*******************************************************************************/

#include <stdio.h>	/* size_t */
#include <assert.h> /* assert */
#include <stdlib.h>	/* malloc */
#include <string.h>	/* memcpy */

#include "vector.h"

#define GROWTH_FACTOR 2
#define HALF 0.5
#define QUARTER 0.25
#define SUCCESS 0
#define FAIL 1


/***************************Macros Functions *********************************/
#define ALLOC_CHK(a,b)		 \
do 							 \
{						 	 \
	if(NULL == a) 			 \
	{						 \
		return b;		 	 \
	} 						 \
} 							 \
while(0)

#define ARRAY_CHK(a,b,c)	 \
do 							 \
{						 	 \
	if(NULL == a) 			 \
	{						 \
		free(b);			 \
		return c;		 	 \
	} 						 \
} 							 \
while(0)
  
/* Structs: */
struct vector 
{
	char *vector_start; 	/* char type for convinience only; 
							 * vector can hold any type			*/	
	size_t element_size;
	size_t vector_size;		/* in elements 						*/
	size_t capacity;
	size_t init_capacity;
};


/******************************************************************************/

/*creat vector*/
vector_ty *VectorCreate(size_t element_size, size_t capacity)
{
    vector_ty *new_vector = NULL;
    
    assert(capacity > 0);
    
    new_vector = (vector_ty *)malloc(sizeof(vector_ty));
    
    /*check if malloc fail*/
    ALLOC_CHK(new_vector, NULL);
    
    /*malloc for the array of the vector*/
    new_vector->vector_start = (char *)malloc(capacity * element_size);
    
    /*check if malloc fail*/
    ARRAY_CHK(new_vector->vector_start, new_vector, NULL);
    
    /*initializtion of the vector struct members*/
    new_vector->element_size = element_size;
    new_vector->vector_size = 0;
    new_vector->init_capacity = capacity;
    new_vector->capacity = capacity;
   
    /*return the pointer to thr vector*/
    return new_vector;
}

/*free the pointer of the vector*/
void VectorDestroy(vector_ty *vector)
{	
	assert(vector);
	
	free(vector->vector_start);
	vector->vector_start = NULL;
	
	free(vector);
}

/*get the last element in the vector*/
void *VectorGetElem(const vector_ty *vector, size_t idx)
{
	assert(vector);
		
	return (vector->vector_start+ (idx * vector->element_size));
}

/*push element to the last idx of thr vectoe */
int VectorPushBack(vector_ty *vector, const void *elem)
{
    char *tmp_ptr = NULL;
    
    assert(vector);
    assert(vector->vector_start);
    
    
    if (vector->capacity == vector->vector_size)
    {
        tmp_ptr = (char *)realloc
        (vector->vector_start, vector->capacity * GROWTH_FACTOR * vector->element_size);
        /* TODO free */
        if (NULL == tmp_ptr)
        {
            return 1;
        }
        
        vector->vector_start = tmp_ptr;
        vector->capacity *= GROWTH_FACTOR;
    }
    
    memcpy(vector->vector_start + vector->vector_size * vector->element_size,
          elem, vector->element_size);

    ++vector->vector_size;
    
    return 0;
}

void VectorPopBack(vector_ty *vector)
{
	
	assert(vector);
	--(vector->vector_size);
	
	if (vector->vector_size == QUARTER * vector->capacity && (vector->capacity * HALF) >= vector->init_capacity)
	{
		vector->vector_start = (char *)realloc(vector->vector_start, (vector->capacity) * HALF * vector->element_size);
		
		if (vector->vector_start == NULL)
		{
			return;
		}
	}
	vector -> capacity /= GROWTH_FACTOR;
	
}


size_t VectorSize(const vector_ty *vector)
{
	return vector->vector_size;
}

size_t VectorCapacity(const vector_ty *vector)
{
	return vector->capacity;
}

/* ther is a probleme with the realoc!!!*/
int VectorReserveSize(vector_ty *vector, size_t new_capacity)
{
	if (new_capacity > vector->capacity)
	{
		vector->capacity = new_capacity;
		
		vector = (vector_ty*)realloc(vector, (vector->capacity) * vector->element_size);
		
		/*realloccan fail  add tmp pointer*/
		if (vector == NULL)
		{
			return FAIL;
		}
	}
	
	return SUCCESS;	
}

void VectorShrinkToSize(vector_ty *vector)
{
	if ((vector->vector_size) <= vector->init_capacity) 
	{
		vector->capacity = vector->vector_size;
		
		vector->vector_start = (char *)realloc(vector->vector_start , 
		(vector->capacity) * vector->element_size);
	
		if (NULL == vector)
		{
			return;
		}
	}
}











