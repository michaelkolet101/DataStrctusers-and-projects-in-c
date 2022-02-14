#include <stdio.h>
#include <string.h>
#include "recursion.h"

int main()
{
    int n = 5;
    int res = FibonaciiNotRec(n);
    int res2 = FibonaciiWithRec(n);
    
    char *string = "michael";
    char *str = "michdel";
    size_t res3 =  StrLen(string);
    int res4 = StrCmp(string, str);
    int res5 = strcmp(string, str);

    char *X = "ddddddddddddgggddddddd";
    char *Y = "ggg";
 
    char a[50] = "michael";
    char b[50] = " kolet";

    printf("%s\n", StrStr(X, Y));

    printf("TEST TO STRCAT: %s\n", StrCat(a, b));

    
   /* printf("my %d\n" ,res);*/
        
    printf("no recu %d\n" ,res);
    printf("with recu %d\n" ,res2);
    
    return 0;
}
