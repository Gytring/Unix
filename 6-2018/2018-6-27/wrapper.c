 /*************************************************************************
	> File Name: wrapper.c
	> Author: free
	> Mail: fancanglang@foxmail.com 
	> Created Time: Wed 27 Jun 2018 03:33:57 PM CST
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
	int fd;
	if(argc != 2)
	{
		fputs("usage: wrapper file\n", stderr);
		exit(1);
	}
	fd = open(argv[1], O_RDONLY);
	if(fd < 0)
	{
		perror("open");
		exit(1);
	}
	dup2(fd, STDIN_FILENO);
	close(fd);
	execl("./upper", "upper", NULL);
	perror("exec ./upper");
	exit(1);
}
