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
	int r= 1;
	void *sm = (void *)0;
	struct memory *shared_stuff;
	char buffer[BUFSIZ];
	int shmid;
	shmid = shmget((key_t)1234, sizeof(struct memory), 0666 | IPC_CREAT);
	sm = shmat(shmid, (void *)0, 0);
	printf("Memory attached at %X\n", (int)sm);
	shared_stuff = (struct memory *)sm;
	while(r)  // r= 1 
	{
		while(shared_stuff->ret == 1) 
		{
			sleep(1);
			printf("waiting for client...\n");
		}
		printf("Enter some text: ");
		fgets(buffer, BUFSIZ, stdin);
		strncpy(shared_stuff->some_text, buffer, TEXT_SZ);
		shared_stuff->ret = 1;
		if (strncmp(buffer, "end", 3) == 0)  // "end" found in memory segment
		{
			r= 0;
		}
	}
	exit(EXIT_SUCCESS);
}