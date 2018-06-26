#include"stdio.h"
#include"stdlib.h"
#include"sys/types.h"
#include"unistd.h"

void sortt(int x[],int s,int e)
{
	int temp,i,j;
	for(i=0;i<e-1;i++)
	{
		for(j=i+1;j<e;j++)
		{
			if(x[i] > x[j])
			{
				temp = x[i];
				x[i] = x[j];
				x[j] = temp;
			}
		}
	}
	for(i=0;i<e;i++)
	{
		printf("%d",x[i]);
	}
	return ;
}

int main(int argc, char const *argv[])
{
	int i,j,pid,ppid,n;
	int *ar,chd_id;;
	printf("Enter no. of elements");
	scanf("%d",&n);
	ar = (int *)malloc(n*sizeof(int));
	printf("Enter elements\n");

	for(i=0;i<n;i++)
	{
		scanf("%d",&ar[i]);
	}
	chd_id = fork();
	pid = wait(NULL);

	if(chd_id == 0)
	{
		sleep(1);
		printf("\nSelf Process id %d ans parent is is %d",getpid(),getppid());
		printf("\nSorted array");
		sortt(ar,ar,n);
		
	}
	else
	{
		sleep(1);
		printf("\nSelf Process id %d ans parent is is %d",getpid(),getppid());
		printf("\nSorted array is ");
		sortt(ar,ar,n);
		
	}
	return 0;
}