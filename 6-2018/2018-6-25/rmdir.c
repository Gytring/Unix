 /*************************************************************************
	> File Name: rmdir.c
	> Author: free
	> Mail: fancanglang@foxmail.com 
	> Created Time: Mon 25 Jun 2018 03:54:49 PM CST
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

int main(int argc, char *argv[])
{
	int fd;

	if(argc < 2)
	{
		printf("./rmdir filename\n");
		exit(1);
	}
	fd = rmdir(argv[1]);

	if(fd < 0)
	{
		perror("rmdir");
		exit(1);
	}

	return 0;
}
