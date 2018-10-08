#include"stdio.h"
#include"stdlib.h"
#include"pthread.h"

int size = 0;
int x[4][4],y[4][4],z[4][4];
#define t 4

void* multi(void* arg) 
{ 
    int core = size++; 
  
    // Each thread computes 1/4th of matrix multiplication 
    for (int i = core * t / 4; i < (core + 1) * t / 4; i++)  
        for (int j = 0; j < t; j++)  
            for (int k = 0; k < t; k++)  
                z[i][j] += x[i][k] * y[k][j]; 
}

int main(int argc, char const *argv[])
{
	int i,j;

	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			scanf("%d",&x[i][j]);
		}
	}

	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			scanf("%d",&y[i][j]);
		}
	}

	pthread_t thread[4];

	for(i=0;i<4;i++)
	{
		pthread_create(&thread[i],NULL,multi,NULL);
	}
	for(i=0;i<4;i++)
	{
		pthread_join(thread[i],NULL);
	}

	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			printf("%d",z[i][j]);
		}
		printf("\n");
	}
	return 0;
}