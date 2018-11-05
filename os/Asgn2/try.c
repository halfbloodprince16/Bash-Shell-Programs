#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>
#include<semaphore.h>
#include<sys/wait.h>
#include<string.h>
#include<fcntl.h>

int main(int argc, char const *argv[])
{
	int str[100],buf[100],fname[10];
	int fd,fd1;
	system("rm at.txt");
	system("touch at.txt");
	fd = open("at.txt",O_WRONLY);
	printf("\nEnter file content");
	gets(buf);
	write(fd,buf,strlen(buf));
	close(fd);

	printf("\nEnter file name : ");
	gets(fname);
	fd1 = open(fname,O_RDONLY);
	read(fd1,str,sizeof(str));
	puts(str);
	close(fd1);
	return 0;
}