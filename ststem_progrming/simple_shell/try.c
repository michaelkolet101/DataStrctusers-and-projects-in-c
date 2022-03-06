#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int status = 0;
    sleep(5);
    status = system("exit");
    return 0;
}
