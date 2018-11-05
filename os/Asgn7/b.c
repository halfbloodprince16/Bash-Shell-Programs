#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>
#include<string.h>
#define FIFO_PIPE "xyz"

int main(int argc, char const *argv[])
{
	int fd;
	char s[100];
	mkfifo(FIFO_PIPE,0644);
	printf("\nEnter Message");
	gets(s);
	fd = open(FIFO_PIPE,O_WRONLY);
	write(fd,s,strlen(s));
	close(fd);
	return 0;
}
