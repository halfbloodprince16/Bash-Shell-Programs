#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>
#include<string.h>
#define FIFI_PIPE "xyz"

int main(int argc, char const *argv[])
{
	int fd;
	char s[100];
	fd = open(FIFI_PIPE,O_RDONLY);
	read(fd,s,sizeof(s));
	puts(s);
	return 0;
}
