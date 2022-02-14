#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <stack.h>
struct node
{
	void *data;
	struct node *next;
} ;

typedef struct node node_ty;


int FibonaciiNotRec(int element)
{
    int curr = 1, prev = 1;
    

    while (0 <= element - 2)
    {
        curr = curr + prev;
        prev = curr - prev;

        --element;
    }
    
    return curr;
}

int FibonaciiWithRec(int element)
{
    if (element == 0 || element == 1)
    {
        return 1;
    }
    
return (FibonaciiWithRec(element - 1) + FibonaciiWithRec(element - 2));
}

size_t StrLen(char *string)
{
    static size_t count = 0;

    if (*string == '\0')
    {
        return count;
    }

    ++count; 
    return StrLen(++string);
}

int StrCmp(char *str1, char *str2)
{
    if ((*str1 != *str2) || (*str1 == '\0') )
    {
        return ((*str1) - (*str2));
    }
    
    StrCmp(++str1, ++str2);
}


char *StrCpy(char *dest, const char *src)
{
    assert(dest);
    assert(src);   
    
    *dest == *src;  

    if ('\0' == *src)
    {
        return dest;
    }
    

    return StrCpy((++dest), (++src));
}

char *StrCat(char *dest, const char *src)
{
    assert(dest);
    assert(src);

    /*We will proceed with the pointer to the end of the original string*/
    dest += StrLen(dest);

    /*We will copy to this place and beyond the string we want*/
    StrCpy(dest, src);
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
    int i = 0;

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











