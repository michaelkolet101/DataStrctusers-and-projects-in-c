#include<stdio.h>
#include<string.h>


int Atoi(char *string);
int ChToNum(char ch);


int main()
{
    char str[] = "5454";
    int num = 0;

    num = Atoi(str);
    printf("%d\n", num);
    
    return 0;
}

int Atoi(char *string)
{
    int len = strlen(string);
    int num = 0;

    while (0 != len)
    {
        num = num * 10 + ChToNum(*string);
        --len;
        ++string;
    }
     
    return num;
}

int ChToNum(char ch)
{
    return ch - '0';
}
















