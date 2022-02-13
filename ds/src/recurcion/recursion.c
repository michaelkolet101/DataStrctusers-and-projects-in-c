#include <stdlib.h>
#include <stdio.h>

/*
struct node
{
    node_ty *next;
    void *data;
};*/

int FibonaciiNotRec(int element)
{
    int curr = 1, prev = 0;
    

    while (0 != element - 2)
    {
        curr = curr + prev;
        prev = curr - prev;

        --element;
    }
    
    return curr;
}

int FibonaciiWithRec(int element)
{
    if (element <= 1)
    {
        return element;
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
    StrLen(++string);
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
    char *runner = dest;  

    if ('\0' == *src)
    {
        *runner == *src;
        return dest;
    }
    *runner == *src;

    return StrCpy(++runner, ++src);
}