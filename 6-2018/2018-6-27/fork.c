 /*************************************************************************
	> File Name: fork.c
	> Author: free
	> Mail: fancanglang@foxmail.com 
	> Created Time: Wed 27 Jun 2018 09:32:54 AM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

int main(void)
{
	pid_t pid;

	char *message;
	int n;
	pid = fork();
	if(pid < 0)
	{
		perror("fork failed");
		exit(1);
	}

	if(pid == 0)
	{
		message = "This is the child\n";
		n = 6;
	}
	else
	{
		message = "This is the parent\n";
		n = 3;
	}
	for(;n>0; n--)
	{
		printf("%s",message);
		sleep(1);
	}

	return 0;
}
