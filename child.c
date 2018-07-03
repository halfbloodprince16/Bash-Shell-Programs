#include"stdio.h"
#include"stdlib.h"
#include"sys/types.h"
#include"unistd.h"

int main(int argc, char *argv[])
{
	printf("hello");
	for (int i = 0; i < 3; ++i)
	{
		printf("%s",argv[i]);
	}
		
	return 0;
}