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
    int child_pid = 0;

    /* get child process */
    child_pid = fork();

    if (-1 == child_pid)
    {
        fputs("fork fail", stderr);
    }
    
    else if (0 == child_pid) /*child*/
    {                                    
        ChildIMP();         
    }
    else/* parent */
    {  
       ParentIMP(child_pid);   
    }

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

void ChildIMP()
{
    char *args[]={"/home/michael/michael-kolet/ststem_progrming/ping_pong/pro2", NULL};
 
    execv(args[0],args);
}

void hendler(int sig)
{
    signal_is_comming = 1;
}