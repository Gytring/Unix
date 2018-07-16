 /*************************************************************************
	> File Name: imput.c
	> Author: free
	> Mail: fancanglang@foxmail.com 
	> Created Time: Mon 25 Jun 2018 10:35:32 AM CST
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int fd;

	if(argc < 2)
	{
		printf("./input filename\n");
		exit(1);
	}

	fd = open(argv[1], O_CREAT | O_RDONLY);

	if(fd < 0)
	{
		perror("open");
		exit(1);
	}

	
}

