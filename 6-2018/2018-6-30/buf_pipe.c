 /*************************************************************************
	> File Name: buf_pipe.c
	> Author: free
	> Mail: fancanglang@foxmail.com 
	> Created Time: Sat 30 Jun 2018 04:54:03 PM CST
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>

int main(void)
{
	int fd[2];
	pipe(fd);
	printf("pipe buf %ld\n", fpathconf(fd[0], _PC_PIPE_BUF));

	return 0;
}
