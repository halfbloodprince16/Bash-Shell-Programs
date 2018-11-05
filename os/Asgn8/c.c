#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include"shm_com.h"

int main()
{
	int shmid;
	void *sm = (void *)0;
	struct memory *obj;
	char buf[BUFSIZ];
	shmid = shmget((key_t)1234,sizeof(struct memory),0666|IPC_CREAT);
	sm = shmat(shmid,(void *)0,0);
	printf("\nMemory allocated at %X",(int)sm);
	obj = (struct memory *)sm;
	int r = 1;
	while(r)
	{
		if(obj->ret == 1)
		{
			printf("\nYou wrote : %s",obj->msg);
			obj->ret = 0;
			if(strncmp(obj->msg,"end",3)==0)
			{
				r=0;
			}
		}
		
	}
}