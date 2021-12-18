#ifndef __VECTOR_H__
#define __VECTOR_H__

typedef struct vector vector_ty;

/*In source file:*/


/******************************************************************************
* Function Description: returns a pointer to an empty dynamic vector DS.   
* Arguments: size of vector elements (in bytes), capacity of vec (in elem).
* Return value: Pointer to vector.
* Notes: Return NULL in case of failure

* Time Complexity: O(1)
*******************************************************************************/
vector_ty *VectorCreate(size_t element_size, size_t capacity);

/******************************************************************************
* Function Description: destroys the vector	       
* Arguments: pointer to a dynamic vector structure
* Return value: none
* Notes:

* Time Complexity: O(1)
*******************************************************************************/
void VectorDestroy(vector_ty *vector);

/******************************************************************************
* Function Description: Points to element vector in specified idx.
* Arguments: Pointer to vector, idx.
* Return value: Pointer to element in idx
* Notes: 1. Undefined in case of index out of boundary.
*		 2. Repeat memory allocations may make the pointer redundant.
*		 	Must be used before each operation.
*  
* Time Complexity: O(1)
*******************************************************************************/
void *VectorGetElem(const vector_ty *vector, size_t idx);

/*****************************Super advanced ***********************************
* Function Description: Inserts	an element to the vector at specified index
* Arguments: Vector pointer, index, element to add
* Return value: int status
* Notes: Return error in case of failure.

* Time Complexity: O(n)
*******************************************************************************/
int VectorAddElem(vector_ty *vector, size_t idx, const void *elem);

/******************************************************************************
* Function Description: Inserts	an element to the end of the vector.
* Arguments: Vector pointer, element to add
* Return value: int status
* Notes: Return error in case of failure.

* Time Complexity: amortized O(1)
*******************************************************************************/
int VectorPushBack(vector_ty *vector, const void *elem);

/******************************************************************************
* Function Description: Deletes the last element of vector.
* Arguments: Pointer to vector.
* Return value:
* Notes:

* Time Complexity: O(1)
*******************************************************************************/
void VectorPopBack(vector_ty *vector);

/******************************************************************************
* Function Description: Returns the current capacity.
* Arguments: Pointer to vector.
* Return value: Current capacity.
* Notes:
* 
* Time Complexity: O(1)
*******************************************************************************/
size_t VectorCapacity(const vector_ty *vector);

/******************************************************************************
* Function Description: Returns the number of elements in vector.
* Arguments: Pointer to vector.
* Return value: Number of elements in vector.
* Notes:
* 
* Time Complexity: O(1)
*******************************************************************************/
size_t VectorSize(const vector_ty *vector);

/******************************************************************************
* Function Description: Expands memory (in terms of elements) to new capacity.
* Arguments: Pointer to vector, new capacity.
* Return value: int status
* Notes: 1. Return error in case of failure.
* 		 2. Only changes capacity if new_capacity is greater than capacity.
* 
* Time Complexity: O(1)
*******************************************************************************/
int VectorReserveSize(vector_ty *vector, size_t new_capacity);

/******************************************************************************
* Function Description: Diminish capacity to to size.
* Arguments: Pointer to vector.
* Return value:
* Notes:
* 
* Time Complexity: O(1)
*******************************************************************************/
void VectorShrinkToSize(vector_ty *vector);

#endif /*__VECTOR_H__*/

