/*
A process whose parent process no more exists i.e. either finished or terminated without waiting for its child process to terminate is called an orphan process.

However, the orphan process is soon adopted by init process, once its parent process dies.
*/
#include<stdio.h>
int main()
{
    // Create a child process      
    int pid = fork();
    if (pid > 0)
    {
	printf("\nin Parent process");
	printf("\n\t My process id is : %d" , getpid());
	printf("\n\t My parent process id is : %d" , getppid());
    
    // pid is 0 in child process
    // and negative if fork() fails
    }
 
    
    else if (pid == 0)
    {
    	sleep(2);  //child ko sleep kia taki parent terminate ho jayai !!!
       	printf("in child process");
    	printf("\n\tMy Process id is : %d",getpid());
	printf("\n\tMy Parent process id is : %d\n",getppid());
    }
        
 
    return 0;
}

