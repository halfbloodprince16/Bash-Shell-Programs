/*
Thread synchronization and mutual exclusion using mutex. Application to demonstrate:
Reader-Writer problem with reader priority.
*/
#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<stdlib.h>
#include<unistd.h> 



int rc=0;
sem_t m,wrt;

void *reader(void *arg)
{
	int i=(int)arg;
	printf("\n%d reader is created\n",i); // 0 
	sleep(1);
	sem_wait(&m);     // m=0
	rc++;
	if(rc==1) // only one reader is given permision to read at a time
		sem_wait(&wrt);   // wrt =0 since wrtiter is not writing
	
	sem_post(&m);    // m=1
	printf("\n%d reader is reading\n",i);
	sleep(1);
	
	sem_wait(&m);    // m=0
	rc--;			//rc =0
	
	if(rc==0)  // so that only others readers can also read 
		sem_post(&wrt);   //wrt = 1
	printf("\n%d reader is completed\n",i);
}

void *writer(void *arg)
{
	int i=(int)arg;
	printf("\n%d writer is created\n",i); // 0
	sleep(1);
	sem_wait(&wrt);     // wrt =0 
	printf("\n%d writer is writing\n",i);
	sleep(1); 
	sem_post(&wrt);    // wrt =1
	printf("\n%d writer is completed\n",i); 
}

main()
{
	pthread_t r[5],w[5];  // 
	sem_init(&m,0,1);  		// intialisation of semaphore 
	sem_init(&wrt,0,1);		// intialise flag with 1  so that only onbe writer can write at once
	int i;
	
	for(i=0;i<3;i++)
	{
		pthread_create(&w[i] , NULL , writer,(void *)i);
		sleep(5);
		pthread_create(&r[i] , NULL , reader,(void *)i);
		sleep(5);	
	}

	for(i=0;i<3;i++)	// so as main do not end before all the threads 
	{
		pthread_join(&w[i] , NULL);
		pthread_join(&r[i] , NULL);
	}
}

