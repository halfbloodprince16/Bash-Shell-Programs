#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>
#define FIFO_PIPE "xyz"

int main()
{
	int fd, i=0;
	char str[200],ch;

	mkfifo(FIFO_PIPE, 0644);	//path , mode

	printf("\n Enter Your message (press @ to terminate) \n");
	gets(str);

	fd=open(FIFO_PIPE,O_WRONLY);
	write(fd, str, strlen(str));

	close(fd);
	return 0;
}