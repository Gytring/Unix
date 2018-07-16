 /*************************************************************************
	> File Name: fork.c
	> Author: free
	> Mail: fancanglang@foxmail.com 
	> Created Time: Sat 23 Jun 2018 03:34:07 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
	pid_t pid;
	int n = 2018;
	pid = fork();

	if(pid > 0)
	{
		while(1)
		{
			printf("The parent process: %d\n", n++);
			printf("my id = %d\n", getpid());
			printf("my parent id = %d\n", getppid());
			sleep(1);
		}
	}
	else if(pid == 0)
	{
		while(1)
		{
			printf("The child process: %d\n", n++);
			printf("my id = %d\n", getpid());
			printf("my parent id = %d\n", getppid());
			sleep(3);
		}
	}
	else
	{
		perror("fork");
	}


	return 0;
}
