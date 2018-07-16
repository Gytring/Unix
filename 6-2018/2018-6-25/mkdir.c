 /*************************************************************************
	> File Name: mkdir.c
	> Author: free
	> Mail: fancanglang@foxmail.com 
	> Created Time: Mon 25 Jun 2018 03:51:28 PM CST
 ************************************************************************/

#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include <errno.h>

int main(void)
{
	int fd;

	umask(0);
	fd = mkdir("tesd", 0644);

	if(fd < 0)
	{
		perror("mkdir");
		exit(1);
	}

	return 0;
}
