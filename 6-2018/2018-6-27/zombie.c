 /*************************************************************************
	> File Name: zombie.c
	> Author: free
	> Mail: fancanglang@foxmail.com 
	> Created Time: Wed 27 Jun 2018 03:55:48 PM CST
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
	pid_t pid = fork();
	if(pid<0)
	{
		perror("fork");
		exit(1);
	}

	if(pid > 0)
	{
		while(1);
	}
	return 0;
}
