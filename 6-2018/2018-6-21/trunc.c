 /*************************************************************************
	> File Name: trunc.c
	> Author: free
	> Mail: fancanglang@foxmail.com 
	> Created Time: Thu 21 Jun 2018 02:23:58 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
	int fd;

	if(argc < 2)
	{
		printf("./trunc filename\n");	
		exit(1);
	}

	fd = open(argv[1], O_CREAT | O_TRUNC, 0777);
	//fd = open(argv[1], O_CREAT, 0777);

	if(fd < 0)
	{
		perror("TRUNC:");
		exit(1);
	}

	close(fd);
	printf("SUCCEEDED!!!\n");
	return 0;
}

