#ifndef __WS9_H__
#define __WS9_H__

/*programmer name: Michael Kolet
reviewer's name: Daniel Zafrir */

/******************************    macros function   ***********************/





/***************************   functions   ********************************/

/* copy n characters from the source object to the destination object.*/
void* MemCpy(void* dest, const void* src, size_t n);

/*fills the first n bytes of the memory area pointed to by s with the 
constant byte c
returns a pointer to the memory area s*/
void *MemSet(void *source, int ch, size_t n);

/*copies n bytes from memory area src to memory area dest
returns a pointer to dest*/
void* MemMove(void *dest, const void *src, size_t n);



#endif /*__WS8_H__*/






