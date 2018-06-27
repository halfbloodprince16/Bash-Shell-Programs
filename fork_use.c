#include"stdio.h"
#include"unistd.h"

int main(int argc, char const *argv[])
{
	int val = fork();
	int x = 1;
	if(val == 0)
	{
		printf("Child x = %d",++x);
	}
	else
	{
		printf("Parent x = %d",--x);		
	}
	printf("Exiting with x = %d",x );
	return 0;
}