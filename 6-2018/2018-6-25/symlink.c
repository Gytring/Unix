 /*************************************************************************
	> File Name: symlink.c
	> Author: free
	> Mail: fancanglang@foxmail.com 
	> Created Time: Mon 25 Jun 2018 03:46:35 PM CST
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

int main(void)
{
	int fd;

	fd = symlink("freegcc", "brw");

	if(fd < 0)
	{
		perror("symlink");
		exit(1);
	}

	return 0;
}
