#define _GNU_SOURCE
#include  <signal.h>
#include  <stdio.h>
#include  <stdlib.h>
#include  <sys/types.h>
#include  <unistd.h>
  
volatile int signal_is_comming = 0;

void hendler(int sig);
void ChildIMP();
void ParentIMP(int child_pid);

int main()
{
    

    /* get child process */

    
    
    ParentIMP(child_pid);   
    

	return 0;
}

void ParentIMP(int child_pid)
{
    signal(SIGUSR2, hendler);
        
    while (1)
    {
        while (0 == signal_is_comming)
        {
            sleep(signal_is_comming);
            /*fputs("too mach time", stderr);*/
        }
        puts("pong");
        signal_is_comming = 0;
        if (-1 == kill(child_pid, SIGUSR1))
        {
            fputs("kill from parent fail", stderr);
        }
    }
}