#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>

int rc=0;
sem_t rr,ww;

void *writer(void *arg)
{
	int i=(int)arg;
	printf("\nWriter created %d",i);
	sleep(1);
	sem_wait(&ww);
	printf("\nWriter started writing %d",i);
	sleep(1);
	sem_post(&ww);
	printf("\nWriter done writing %d",i);
	sleep(1);
}

void *reader(void *arg)
{
	int i=(int)arg;
	printf("\nReader created %d",i);
	sleep(1);
	sem_wait(&rr);
	rc++;
	if(rc==1)
	{
		sem_wait(&ww);
	}
	sem_post(&rr);

	printf("\nReader started reading %d",i);
	sleep(1);

	sem_wait(&rr);
	rc--;
	if(rc==0)
	{
		sem_post(&ww);
	}
	printf("\nReader done reading %d",i);
	sleep(1);
}

int main(int argc, char const *argv[])
{
	pthread_t r[5],w[5];
	sem_init(&rr,0,1);
	sem_init(&ww,0,1);
	int i;

	for(i=0;i<3;i++)
	{
		pthread_create(&w[i],NULL,writer,(void*)i);
		sleep(5);
		pthread_create(&r[i],NULL,reader,(void*)i);
		sleep(5);
	}
	for(i=0;i<3;i++)
	{
		pthread_join(w[i],NULL);
		pthread_join(r[i],NULL);
	}
	return 0;
}