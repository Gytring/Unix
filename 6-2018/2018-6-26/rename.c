 /*************************************************************************
	> File Name: rename.c
	> Author: free
	> Mail: fancanglang@foxmail.com 
	> Created Time: Tue 26 Jun 2018 03:53:35 PM CST
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int fd;

	if(argc < 2)
	{
		printf("./rename newname\n");
		exit(1);
	}

	fd = rename("trap", argv[1]);

	if(fd < 0)
	{
		perror("raname");
		exit(1);
	}
	else
	{
		printf("rename SUCCEEED!\n");
	}
	return 0;
}
