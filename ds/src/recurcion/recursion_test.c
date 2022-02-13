#include <stdio.h>
#include <string.h>
#include "recursion.h"

int main()
{
    int res = FibonaciiNotRec(7);
    int res2 = FibonaciiWithRec(7);
    
    char *string = "michael";
    char *str = "michdel";
    size_t res3 =  StrLen(string);
    int res4 = StrCmp(string, str);
    int res5 = strcmp(string, str);




    
    printf("my %d\n" ,res5);
    printf(" %d\n" ,res4);
    return 0;
}
