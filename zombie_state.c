//zombie state
#include"stdio.h"
#include"stdlib.h"
#include"sys/types.h"
#include"unistd.h"

int main(int argc, char const *argv[])
{
	pid_t child_pid = fork();
 
    // Parent process 
    if (child_pid > 0)
    {
    	printf("\nhi parent");
        sleep(5);//zombie state
    }
 
    // Child process
    else     
    {
    	printf("\nhi child");  //orphan state
        exit(0);
    }
 	system("ps -l");
    return 0;
}