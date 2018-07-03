#include"stdio.h"
#include"stdlib.h"
#include"sys/types.h"
#include"unistd.h"
#include"string.h"


int main(int argc, char *argv[])
{
	char *c[3];
	c[0] = malloc(9);
	printf("\nEnter a char\n");
	gets(c);
	c[3]=NULL;
	execv("./child",c);
	return 0;
}