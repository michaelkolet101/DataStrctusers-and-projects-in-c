#ifndef __C_BUFFER_H__
#define __C_BUFFER_H__

#include <stddef.h> /* size_t */
#include <sys/types.h> /* ssize_t */



typedef struct cbuffer cbuffer_ty;

/******************************************************************************
* Function Description: creates new cbuffer data structure
* Arguments: capacity of buffer
* Return value: pointer to new cbuffer
* Notes: returns NULL if failure 

* Time Complexity: O(1)
*******************************************************************************/
cbuffer_ty *CBufferCreate(size_t bufsiz);

/******************************************************************************
* Function Description: destroys given cbuffer by freeing the memory allocated
* Arguments: - pointer to a cbuffer
* Return value: none
* Notes: if receives null - undefined behaviour.

* Time Complexity: O(1)
*******************************************************************************/
void CBufferDestroy(cbuffer_ty *cbuffer);

/******************************************************************************
* Function Description: return number of free bytes in the buffer
* Arguments: - pointer to the cbuffer_ty
* Return value: number of free bytes to write
* Notes: 

* Time Complexity: O(1)
*******************************************************************************/
size_t CBufferFreeSpace(const cbuffer_ty *cbuffer);

/***************************************************************************
* Function Description: return value of bufsiz	       
* Arguments: pointer to the cbuffer_ty
* Return value: return value of bufsiz (capacity)
* Notes: 

* Time Complexity: O(1)
*******************************************************************************/
size_t CBufferBufsiz(const cbuffer_ty *cbuffer);

/******************************************************************************
* Function Description: attempts to read up to count bytes from circular buffer
* into dest
* Arguments: pointer to a circular buffer, dest and number of bytes
* Return value: number of bytes read ,On error -1 is returned.
* Notes: if count is bigger than the buffer current size - reads up to current
          size.
          If there's not enough space in dest - undefined.

* Time Complexity: O(n)
*******************************************************************************/
ssize_t CBufferRead(cbuffer_ty *cbuffer, void *dest, size_t count);

/******************************************************************************
* Function Description: writes up to count bytes from src to the circular buffer
* Arguments: pointer to a circular buffer, buffer source and number of bytes to
* write
* Return value: number of written bytes, on error -1 is returned
* Notes: If count is bigger than the free space - writes up to bufsiz

* Time Complexity: O(n)
*******************************************************************************/
ssize_t CBufferWrite(cbuffer_ty *cbuffer, const void *src, size_t count);

/******************************************************************************
* Function Description: checks if the cbuffer is empty
* Arguments: - pointer to the cbuffer
* Return value: int (boolean) with value of either 0 (false) or 1 (true) 
* Notes: 

* Time Complexity: O(1)
*******************************************************************************/
int CBufferIsEmpty(const cbuffer_ty *cbuffer);


#endif /*__C_BUFFER_H__*/
