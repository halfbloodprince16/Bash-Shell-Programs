#include <stdio.h>
#include<pthread.h>
#include<unistd.h>

int x[100][100],y[100][100],z[100][100];
int a,b,c,d,i,j,k;
int threads;
int steps=0;

void * mul(void * arg)
{
    int core = steps++;
    
    for(i=core*threads/a;i<(core+1)*threads/a;i++)
    {
        for(j=0;j<threads;j++)
        {
            for(k=0;k<threads;k++)
            {
                z[i][j] += x[i][k]*y[k][j];
            }
        }
    }
}


int main(int argc, char const *argv[])
{
    printf("\nEnter row col of Matrix A : ");
    scanf("%d %d",&a,&b);

    for(i=0;i<a;i++)
    {
        for(j=0;j<b;j++)
        {
            scanf("%d",&x[i][j]);
        }
    }

    printf("\nEnter row col of Matrix B : ");
    scanf("%d %d",&c,&d);

    for(i=0;i<c;i++)
    {
        for(j=0;j<d;j++)
        {
            scanf("%d",&y[i][j]);
        }
    }
    printf("\nMatrix A : \n");
    for(i=0;i<a;i++)
    {
        for(j=0;j<b;j++)
        {
            printf("%d ",x[i][j]);
        }
        printf("\n");
    }

    printf("\nMatrix B : \n");
    for(i=0;i<c;i++)
    {
        for(j=0;j<d;j++)
        {
            printf("%d ",y[i][j]);
        }
        printf("\n");
    }

    threads = a;

    pthread_t p[threads];

    for(i=0;i<threads;i++)
    {
        pthread_create(&p[i],NULL,mul,NULL);
    }

    for(i=0;i<threads;i++)
    {
        pthread_join(p[i],NULL);
    }

    printf("\nMatrix AxB : \n");
    for(i=0;i<a;i++)
    {
        for(j=0;j<d;j++)
        {
            printf("%d ",z[i][j]);
        }
        printf("\n");
    }

    return 0;
}

