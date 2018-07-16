 /*************************************************************************
	> File Name: excl.c
	> Author: free
	> Mail: fancanglang@foxmail.com 
	> Created Time: Thu 21 Jun 2018 02:40:09 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	int fd;

	if(argc < 2)
	{
		printf("./EXCL filename\n");
		exit(1);
	}

	fd = open(argv[1], O_WRONLY | O_CREAT | O_EXCL, 0777);

	if(fd < 0)
	{
		perror("EXEC");
		exit(1);
	}

	close(fd);

	printf("SUCCEEDED\n");
	return 0;
}

