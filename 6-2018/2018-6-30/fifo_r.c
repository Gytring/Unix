 /*************************************************************************
	> File Name: fifo_r.c
	> Author: free
	> Mail: fancanglang@foxmail.com 
	> Created Time: Sat 30 Jun 2018 05:12:49 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define SIZE 4096
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

void sys_err(char *str, int exitno)
{
	perror(str);
	exit(exitno);
}

int main(int argc, char *argv[])
{
	int fd, len;
	char buf[SIZE];
	if(argc < 2)
	{
		printf("./a.out fifoname\n");
		exit(1);
	}

	fd = open(argv[1], O_RDONLY);
	if(fd < 0)
	{
		sys_err("open", 1);
	}
	len = read(fd, buf, sizeof(buf));

	write(STDOUT_FILENO, buf, len);
	close(fd);
	return 0;
}

