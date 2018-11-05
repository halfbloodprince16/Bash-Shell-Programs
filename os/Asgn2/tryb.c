#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>
#include<semaphore.h>
#include<sys/wait.h>

int main(int argc,char * argv[],char * envp[])
{
	int i,j,k,n=0;
	int x[20];

	for(i=0;argv[i+1]!=NULL;i++)
	{
		x[i] = atoi(argv[i+1]);
		n++;
	}
	printf("\narray : ");
	for (int i = 0; i < n; ++i)
	{
		printf("%d ",x[i]);
	}

}