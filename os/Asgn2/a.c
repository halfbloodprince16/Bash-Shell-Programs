#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/wait.h>

void sort(int x[],int n)
{
	int i,j,t;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;i++)
		{
			if(x[i]>x[j])
			{
				t = x[i];
				x[i] = x[j];
				x[j] = t;
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	int n,i,j;
	scanf("%d",&n);
	int x[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&x[i]);
	}
	char *s[n],buff[n];
	for(i=0;i<n;i++)
	{
		snprintf(buff,n,"%d",x[i]);
		s[i+1] = strdup(buff);
	}
	s[0] = malloc(9);
	strcpy(s[0],"child");
	s[n+1] = NULL;
	pid_t pid = fork();

	if(pid > 0)
	{
		//parent
		sort(x,n);
		for(i=0;i<n;i++)
		{
			printf("%d hi",x[i]);
		}
	}
	else
	{
		execve("child",s,NULL);
		perror("execve");
	}
	return 0;
}