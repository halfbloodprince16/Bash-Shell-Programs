#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include "shm_com.h"
int main()
{
	int r = 1;
	void *sm = (void *)0;
	struct memory *shared_stuff;
	int shmid;
	srand((unsigned int)getpid());
	shmid = shmget((key_t)1234, sizeof(struct memory), 0666 | IPC_CREAT);
	sm = shmat(shmid, (void *)0, 0);
	printf("Memory attached at %X\n", (int)sm);
	shared_stuff = (struct memory *)sm;
	shared_stuff->ret = 0;
	while(r)
	{
		if (shared_stuff->ret) // flag = 1
		{
			printf("You wrote: %s", shared_stuff->some_text);
			sleep( rand() % 4 ); /* make the other process wait for us ! */
			shared_stuff->ret = 0;
			if (strncmp(shared_stuff->some_text, "end", 3) == 0) 
			{
				r = 0;
			}
		}
	}
	exit(EXIT_SUCCESS);
}