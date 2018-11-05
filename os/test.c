#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>
#include<stdlib.h>

sem_t ch[5];

void * philosopher(void * arg)
{
	int i=(int)arg;
	int l,r;
	printf("\nphilo created %d",arg);
	sleep(5);
	l = i;
	r = (i+1)%5;
	sem_wait(&ch[l]);
	sem_wait(&ch[r]);
	printf("\nphilo %d eating",arg);
	sleep(5);
	sem_post(&ch[l]);
	sem_post(&ch[r]);
	printf("\nphilo %d done",arg);
	sleep(1);
}

int main(int argc, char const *argv[])
{
	pthread_t p[5];
	int i;
	for(i=0;i<5;i++)
	{
		sem_init(&ch[i],0,1);
	}
	for(i=0;i<5;i++)
	{
		pthread_create(&p[i],NULL,philosopher,(void *)i);
		sleep(1);
	}

	for(i=0;i<5;i++)
	{
		pthread_join(p[i],NULL);
	}
	return 0;
}