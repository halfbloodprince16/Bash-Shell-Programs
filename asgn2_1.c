#include"stdio.h"
#include"stdlib.h"
#include"sys/types.h"
#include"unistd.h"
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
 
int partition (int arr[], int low, int high)
{
    int pivot = arr[high]; 
    int i = (low - 1);  
    for (int j = low; j <= high- 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;    
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
    
        int pi = partition(arr, low, high);
 
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main(int argc, char const *argv[])
{
	int i,j,pid,ppid,n;
	int *ar;
	
	printf("Enter no. of elements");
	scanf("%d",&n);
	ar = (int *)malloc(n*sizeof(int));
	printf("Enter elements\n");

	for(i=0;i<n;i++)
	{
		scanf("%d",&ar[i]);
	}
	pid = wait(NULL);
	pid_t child_pid = fork();
	if(child_pid > 0)
	{
		printf("\nParent Process pid%d\n",getpid());
		sleep(3);//zombie
		printf("%d Parent is terminated", getpid());
		printf("\nSorted array is ");
		quickSort(ar,0,n-1);
		for (int i = 0; i < n; ++i)
		{
			printf("%d\t", ar[i]);
		}
		printf("\n");
	}
	else
	{
		printf("\nChild Process id %d and parent id is %d\n",getpid(),getppid());
		//sleep(3);//orphan
		printf("\nSorted array");
		quickSort(ar,0,n-1);
		for (int i = 0; i < n; ++i)
		{
			printf("%d\t", ar[i]);
		}
		printf("\n");
		
	}
	system("ps -l");
	return 0;
}