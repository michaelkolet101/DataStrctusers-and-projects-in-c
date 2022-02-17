#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "stack.h"

#include "recursion.h"










int FibonaciiNotRec(int element_)
{
    int curr = 1, prev = 1;
    

    while (0 <= element_ - 2)
    {
        curr = curr + prev;
        prev = curr - prev;

        --element_;
    }
    
    return curr;
}

int FibonaciiWithRec(int element_)
{
    if (element_ == 0 || element_ == 1)
    {
        return 1;
    }
    
return (FibonaciiWithRec(element_ - 1) + FibonaciiWithRec(element_ - 2));
}

size_t StrLen(char *string)
{
    

    if (*string == '\0')
    {
        return 0;
    }

     
    return 1 + StrLen(++string);
}

int StrCmp(char *str1_, char *str2_)
{
    if ((*str1_ != *str2_) || (*str1_ == '\0') )
    {
        return ((*str1_) - (*str2_));
    }
    
    StrCmp(++str1_, ++str2_);
}


char *StrCpy(char *dest_, const char *src_)
{
    assert(dest);
    assert(src);   
    
    *dest_ = *src_;  

    if ('\0' == *src_)
    {
        return dest_;
    }

    StrCpy((dest_ + 1), (src_ + 1));
    
    return dest_;
}


char *StrCat(char *dest_, const char *src_)
{
    char *dest_end = NULL;
    
    assert(dest_);
    assert(src_);

    /*We will proceed with the pointer to the end of the original string*/
    dest_end = dest_ + StrLen(dest_) - 1;

    /*We will copy to this place and beyond the string we want*/
    StrCpy(dest_end, src_);

    return dest_;
}


/*need to do for it test */
/*char *StrCat2(char *dest, const char *src)
{
    if (*dest != '\0')
    {
        StrCat2(++dest, src);
    }
    else if (*(++dest) == *(++src))
    {
        StrCat(dest, src);
    }
    
    return dest;
}*/

char* StrCat2(char *dest,char *src)
{
	size_t i = 0, j = StrLen(dest);
    if(*src )
    {
    	*(src + i) = '\0';
	}  
	else
	{
		 *(dest + i + j) = *(src + i);
		 ++i;
         StrCat2(dest, src);
    }
}

char *StrStr( char *haystack,  char *needle)
{
    size_t i = 0;

    if ('\0' == *needle  )
    {
        return haystack;
    }

    for ( i = 0; i < StrLen(haystack); ++i)
    {
        if (*(haystack + i) == *needle)
        {
            char *res = StrStr(haystack + i + 1, needle + 1);
            
            if (res != NULL)
            {
                return res - 1;
            }
            else
            {
                return NULL;
            }            
        }
    }
    return NULL;    
}

node_ty *FlipList(node_ty *node)
{
    node_ty *curr = node;
    node_ty *next = node->next;
    node_ty *haed = node;

    assert(node);

    if (NULL == next)
    {
        return curr;
    }

    haed = FlipList(next);
    next->next = curr;
    curr->next = NULL;

    return haed;
}
/*
void SortedInsert( stack_ty *stack, void *data )
{
    void *tmp = NULL;

    if ( (1 == StackIsEmpty(stack)) || (*(int *)data > (*(int *)StackPeek(stack))))
    {
        StackPush(stack, data);
        return ;
    }
    
    tmp = StackPeek(stack);
    StackPop(stack);

    SortedInsert(stack, data);

    StackPush(stack, tmp);
}

void SortStack(stack)
{
    static void *ret = NULL;

    if ( !StackIsEmpty(stack) )
    {
        void *ret = StackPeek(stack);
        StackPop(stack);
    }
    
    SortStack(stack);

    SortedInsert(stack, ret)
}










*/
