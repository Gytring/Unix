 /*************************************************************************
	> File Name: openfile.c
	> Author: free
	> Mail: fancanglang@foxmail.com 
	> Created Time: Wed 20 Jun 2018 06:17:59 PM CST
 ************************************************************************/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>

int main(void)
{
	int fd;

	fd = open("itcast.txt", O_APPEND);

	if(fd < 0)
	{
		perror("open iscast.txt:");
		exit(1);
	}

	printf("Open itcast append SUCEED!!!\n");
	return 0;
}

