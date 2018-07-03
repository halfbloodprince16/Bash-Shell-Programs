#include"stdio.h"
#include"stdlib.h"
#include"sys/types.h"
#include"unistd.h"

void sortt(int x[],int n)
{
	int temp,i,j;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(x[i] > x[j])
			{
				temp = x[i];
				x[i] = x[j];
				x[j] = temp;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		printf("%d",x[i]);
	}
	return ;
}

int main(int argc, char const *argv[])
{
	int val,n;
	char *str[20],*buff[20];
	printf("Enter no. of Elements");
	scanf("%d",&n);

	int *ar = (int *)malloc(n*sizeof(int));
	printf("\nEnter the Elements :");
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&ar[i]);
	}
	sortt(ar,n);

	for(int i=0;i<n;i++)
	{
		snprintf(buff,20,"%d",ar[i]);
		str[i+1] = strdup(buff);
	}
	printf("%s\n",str[20]);
}