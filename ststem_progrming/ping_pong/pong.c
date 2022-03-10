#include <unistd.h>
#include <signal.h>






void sigHandler( int signo, siginfo_t *siginfop, void *context);

      
int main( int argc, const char *argv[] )
{
   int ping_pid = atoi(argv[1]);
   
   /* this is for receiving signals */
   struct sigaction sa;
   sa.sa_sigaction = sigHandler;
   sigemptyset(&sa.sa_mask);
   sa.sa_flags = SA_NODEFER | SA_SIGINFO;
   
   /* you send SIGUSR1 from pong; you'll receive SIGUSR2 from ping */
   if( sigaction(SIGUSR2, &sa, NULL) == -1) perror("sigaction");
   

  /* this is for sending the first signal */
   union sigval sv;
   
   if( sigqueue( ping_pid, SIGUSR1, sv) == -1 ) perror("sigqueue");
    
    
    
   /*
    do something
    while u wait
   */
    return 0;
  }

void sigHandler( int signo, siginfo_t *siginfop, void *context)
{
   /* send another signal back to ping, you dont need the pid you read from cmd line */ 
   union sigval sv;
   if( siginfop != NULL )
       sigqueue( siginfop->si_pid, SIGUSR1, sv)
}