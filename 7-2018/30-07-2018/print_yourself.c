#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
	pid_t pid;
	printf("WELCOME!!");

	if((pid = fork()) < 0)
	{
		perror("fork");
		exit(-1);
	}
	else if(pid == 0)
	{
		printf("My pid is %d, And my parent pid is %d\n", getpid(), getppid());
	}
	else
	{
		printf("My pid is %d, And my parent pid is %d\n", getpid(), getppid());
		printf("My child pid is %d\n", pid);
	}
	
	wait();
	exit(0);
}
