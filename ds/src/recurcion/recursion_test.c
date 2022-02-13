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

    if (res4 == res5)
    {
        puts("SUCSSES");
    }
    
    printf("my %d\n" ,res5);
    printf("lib %d\n" ,res4);
    return 0;
}
