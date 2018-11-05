#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(int argc,char* argv[],char *envp[])
{
	int i=0,value,n=0,arr[20];
	for(i=0;argv[i+1] != NULL;i++)
	{
		arr[i] = atoi(argv[i+1]);
		n++;
	}

	for(i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
	return 0;
}