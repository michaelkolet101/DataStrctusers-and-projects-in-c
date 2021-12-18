/*******************************************************************************
Data Structures WorkSheet 2: Stack.

Written by: Michael Kolet
Reviewd by: Gabriel Poshumenski

Functions for WS
*******************************************************************************/

#include <stdio.h>	/* size_t */
#include <assert.h> /* assert */
#include <stdlib.h>	/* malloc */
#include <string.h>	/* memcpy */

#include "../includ/vector.h"

#define growth_factor 2
 
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

vector_ty *VectorCreate(size_t element_size, size_t capacity)
{
    vector_ty *new_vector = (vector_ty *)malloc(sizeof(vector_ty));
    
    if (NULL == new_vector)
    {
    	return NULL;
    }
    
    new_vector->vector_start = (char *)malloc(capacity * element_size * sizeof(char));
    
    if (NULL == new_vector->vector_start)
    {
    	free(new_vector);
    	return NULL;
    }
    
    new_vector->capacity = capacity;
    new_vector->element_size = element_size;
    new_vector->vector_size = 0;
    
    return new_vector;
}

void VectorDestroy(vector_ty *vector)
{	
	assert(vector);

	free(vector->vector_start);
}

void *VectorGetElem(const vector_ty *vector, size_t idx)
{
	assert(vector);
	
	return (void *)&vector->vector_start[idx];
}

int VectorPushBack(vector_ty *vector, const void *elem)
{
	assert(vector);
	
	++(vector->vector_size);
	
	if ((vector->vector_size) < (VectorCapacity(vector)))
	{
		vector->vector_start[vector->vector_size] = *((char*)elem);
	}
	else
	{
		vector = (vector_ty*)realloc(vector, (vector->capacity) * growth_factor * sizeof(size_t));
		
		if (vector == NULL)
		{
			return 1;
		}
		
		vector->capacity = vector->capacity * growth_factor;
		vector->vector_start[vector->vector_size] = *((char*)elem);
	}
	
	
		
	return 0; 
}

void VectorPopBack(vector_ty *vector)
{
	assert(vector);
	
	--(vector->vector_size);
	
}


size_t VectorSize(const vector_ty *vector)
{
	return vector->vector_size;
}

size_t VectorCapacity(const vector_ty *vector)
{
	return vector->capacity;
}

int VectorReserveSize(vector_ty *vector, size_t new_capacity)
{
	vector->init_capacity = new_capacity;
	vector->capacity = vector->init_capacity;
	vector = (vector_ty*)realloc(vector, (vector->capacity) * sizeof(size_t));
		
	if (vector == NULL)
	{
		return 1;
	}
	
	return 0;	
}

void VectorShrinkToSize(vector_ty *vector)
{
	vector = (vector_ty*)realloc(vector, (vector->vector_size) * sizeof(size_t));
	
	if (NULL == vector)
	{
		return;
	}
	
	vector->capacity = vector->vector_size;	
}











