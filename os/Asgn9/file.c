// assignment 9
#include<stdio.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

int main()
{
	char buf[1024] , fname[10] ;
	int fd ,fd1;
	system("rm test1.txt");
	system("touch test1.txt");
	fd = open("test1.txt",O_WRONLY);
	printf("\nEnter the message");
	gets(buf);
	write(fd,buf,strlen(buf));
	close(fd);
	
	printf("\nEnter the filename to read ::");
	scanf("%s",fname);
	fd1=open(fname,O_RDONLY);
	
	if(fd1!=3)
	{
		printf("file does not exist\n");
		exit(0);
	}
	
	read(fd1,buf,sizeof(buf));
	printf("\nFile Content are -- %s \n",buf);
	close(fd1);
	return 0;
}
