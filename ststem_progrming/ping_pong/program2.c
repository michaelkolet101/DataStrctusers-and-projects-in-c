#define _GNU_SOURCE
#include  <signal.h>
#include  <stdio.h>
#include  <stdlib.h>
#include  <sys/types.h>
#include  <unistd.h>

volatile int signal_is_comming = 0;

void hendler(int sig);


int main()
{
     signal(SIGUSR1, hendler);
     
    if (-1 == kill(getppid(), SIGUSR2))
    {
        fputs("kill from child fail", stderr);
    }
    while (1)
    {
        while (0 == signal_is_comming)
        {
            sleep(signal_is_comming);
        }

        puts("ping");
        signal_is_comming = 0;
        if (-1 == kill(getppid(), SIGUSR2))
        {
            fputs("kill from child fail", stderr);
        }  
    }
    return 0;
}

void hendler(int sig)
{
    signal_is_comming = 1;
}