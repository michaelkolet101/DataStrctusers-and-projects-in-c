#include <stdio.h>
#include <string.h>


char Input(char ch)
{
    int input_chack = 0;

    while (0 == input_chack)
    {
        puts("Inter a binary char: ");
        scanf(" %c" ,&ch);
        if (ch == '1' || ch == '0')
        {
            input_chack = 1;
        }
        else
        {
            puts("WRONG");
        }
    }
    return ch;
}

void AccptorOfString()
{
    char ch = ' ';
    char string[100] = {'\0'};

    int states[2] = {0, 1};

/* infint loop */
    while ((string[0] != '1'))
    {
        int state = states[0];
        ch = Input(ch);
        strncat(string, &ch, 1);
        if (('0' == string[strlen(string) - 1]) && (strlen(string) > 1) && (string[0] == '0'))
        {
            state = states[1];
            puts("accepted");    
        }
        else
        {
            puts("NOT accepted");
        }

    }
    
}

int main()
{
    AccptorOfString();
    return 0;
}
