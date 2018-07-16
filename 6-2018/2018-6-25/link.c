 /*************************************************************************
	> File Name: link.c
	> Author: free
	> Mail: fancanglang@foxmail.com 
	> Created Time: Mon 25 Jun 2018 03:42:03 PM CST
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>

int main(void)
{
	int fd;

	fd = link("freegcc", "spurs");

	if(fd < 0)
	{
		perror("link");
		exit(1);
	}

	return 0;
}
