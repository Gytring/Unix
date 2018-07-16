 /*************************************************************************
	> File Name: pipe.c
	> Author: free
	> Mail: fancanglang@foxmail.com 
	> Created Time: Sat 30 Jun 2018 03:07:58 PM CST
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#define  SIZE 4096

int main(void)
{
	int fd[2];
	pid_t pid;
	char str[SIZE] = "hello wrold!";
	char buf[SIZE];

	//fd[0]读端
	//fd[1]写端
	if(pipe(fd) < 0)
	{
		perror("pipe");
		exit(1);
	}

	pid = fork();
	//父写子读
	if(pid > 0)
	{
		//父进程里，关闭父读，关闭子写
		close(fd[0]);
		sleep(2);
		write(fd[1], str, strlen(str));
		wait(NULL);
	}
	else if(pid == 0)
	{
		int len;
		//子进程里，关闭子写
		close(fd[1]);
		len = read(fd[0], buf, sizeof(buf));
		sprintf(str, "child %s",buf);
		write(STDOUT_FILENO, buf, len);
	}
	else
	{
		perror("fork");
		exit(1);
	}

	return 0;
}
