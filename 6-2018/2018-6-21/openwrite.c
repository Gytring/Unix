 /*************************************************************************
	> File Name: openwrite.c
	> Author: free
	> Mail: fancanglang@foxmail.com 
	> Created Time: Thu 21 Jun 2018 11:25:05 AM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

int main(int argc, char *argv[])
{
	int fd;

	if( argc < 2)
	{
		printf("./openwrite filename\n");
		exit(1);
	}

	fd = open("gcc", O_CREAT | O_WRONLY, 0777);

	if(fd < 0 )
	{
		perror("openwrite: ");
		exit(1);
	}

	close(fd);
	printf("SUCEED!!!\n");
	return 0;
}

