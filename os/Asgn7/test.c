#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    FILE *fp;
    int fd[2],fd1[2];  // fd[0], fd[1]    fd1[0], fd1[1]
    char ch,ch2, str[100],str2[100]; 
    char buf[100];
    pid_t pid;
    if(pipe(fd) == -1)          printf("\n fd is not created\n");
    if(pipe(fd1) == -1)         printf("\n fd1 is not created\n");
    pid = fork();  
    if(pid)        
    {
        printf("Enter file Name");
        gets(str);
        write(fd[1], str, strlen(str)+1); // fd[1]=filename
        //sleep(1);
        wait(NULL);
        read(fd1[0],buf,sizeof(buf));
        printf("%s\n",buf);
        close(fd1);
    }
    else
    {    
        //sleep(1);
        read(fd[0], str2, sizeof(str2));         //      fd[0]=filename
        fp =fopen(str2, "r");
        while(!feof(fp))
        {
            ch2 = fgetc(fp);
            //printf("%d here ",(int)ch2);
            if((int)ch2!=-1 )
                write(fd1[1], &ch2, 1);
        }
        fclose(fp);
    }
    return 0;
}