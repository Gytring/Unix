 /*************************************************************************
	> File Name: pipe2.c
	> Author: free
	> Mail: fancanglang@foxmail.com 
	> Created Time: Sat 30 Jun 2018 04:41:42 PM CST
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#define	SIZE	4096

int main(void)
{
	int n;
	int fd[2];
	pid_t pid;
	char line[SIZE];
	
	if(pipe(fd) < 0)
	{
		perror("pipe");
		exit(1);
	}

	if((pid = fork()) < 0)
	{
		perror("fork");
		exit(1);
	}
	if(pid > 0)
	{
		close(fd[0]);
		write(fd[1], "hello world\n", 12);
		close(fd[1]);
		wait(NULL);
	}
	else
	{
		close(fd[1]);
		n = read(fd[0], line, SIZE);
		write(STDOUT_FILENO, line, n);
		close(fd[0]);
	}

	return 0;
}
