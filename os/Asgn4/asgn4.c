#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>

int buff[5];
sem_t empty;
sem_t full;
pthread_mutex_t m;

void *producer(void *arg){

	printf("\nProducer thread is created\n");
	sleep(1);

	int item;
	int i = 0;

	while(1)
	{
		sem_wait(&empty);//Before producing decrement empty
		pthread_mutex_lock(&m);
		item = random()%10;
		buff[i++] = item;
		printf("\nitem %d is added in the buffer at %d", item, i-1);
		if(i==5)
			i=0;
		sleep(1);
		pthread_mutex_unlock(&m);
		sem_post(&full);
	}

}

void *consumer(void *arg){

	printf("\nConsumer thread is created\n");
	sleep(1);

	int key;
	int i =0;

	while(1){

		sem_wait(&full);
		pthread_mutex_lock(&m);
		key = buff[i++];
		printf("\nkey %d is consumed from the bufferat %d", key, i-1);
		if(i==5)
		  i=0;
		sleep(1);
		pthread_mutex_unlock(&m);
		sem_post(&empty);//After consuming increment empty

	}

}

int main(){

pthread_mutex_init(&m,NULL);
sem_init(&empty,0,5);
sem_init(&full,0,0);
pthread_t pid, cid;

pthread_create(&pid,NULL,producer,NULL);
sleep(1);
pthread_create(&cid,NULL,consumer,NULL);
sleep(1);

pthread_join(pid,NULL);
pthread_join(cid,NULL);

return 0;

}
