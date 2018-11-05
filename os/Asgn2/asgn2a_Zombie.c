
#include<stdio.h>
#include<stdlib.h>
int main()
{
    pid_t cpid;
    cpid = fork();
    
    if(cpid == 0)
    {
    	printf("\n\tThis is child process");
    	printf("\n\tMy Process id is : %d" , getpid());
    	printf("\n\tMy Parent id is : %d" , getppid());
    }
    
    else
    {
    	sleep(5); // parent ko sleep kia coz child terminate ho jaye !!!
    	printf("\n\tMy Process id is : %d",getpid());
    	printf("\n\tMy Parent id is : %d",getppid());
    }
    
    return 0;
}
