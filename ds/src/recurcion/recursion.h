#include <stdlib.h>


#ifndef __RECURSION_H__
#define __RECURSION_H__

struct node
{
	void *data;
	struct node *next;
} ;


typedef struct node node_ty;



int FibonaciiNotRec(int element);
int FibonaciiWithRec(int element);

/*node_ty *FlipList(node_ty *node);*/

size_t StrLen(char *string);

int StrCmp(char *str1, char *str2);

char *strcpy(char *dest, const char *src);

char *StrCat(char *dest, const char *src);

/*char *StrCat2(char *dest, const char *src);*/


char *StrStr( char *haystack,  char *needle);

#endif /*__RECURSION_H__*/

