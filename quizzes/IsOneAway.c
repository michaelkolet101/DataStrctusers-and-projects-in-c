#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

int IsOneAway(char *str1, char *str2);

int main()
{
    char *str1 = "pale";
    char *str2 = "bale";
    
    int ans = IsOneAway(str1, str2);
    
    if (ans == 1)
    {
        puts("SUCCSES");
    }
    else
    {
        puts("FAIL");
    }
    
    return 0;
}


int IsOneAway(char *str1, char *str2)
{
    int distans = abs((int)strlen(str1) - (int)strlen(str2));
    int ret = 0;
    
    assert(str1);
    assert(str2);
    
    if (distans > 1)
    {
        return ret;
    }

    while ('\0' != *str1)
    {
        if(*str1 != *str2)
        {
            ++ret;
        }
        
        ++str1;
        ++str2;
    }
    
    return ret == 1;
}


