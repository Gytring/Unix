#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	pid_t		pid;
	int			status;
	pid = fork();
	if(pid < 0)
	{
		perror("fork failed");
		exit(1);
	}
	if(pid == 0)
	{
		int i;
		for(i = 3; i > 0; i--)
		{
			printf("The parent of pid is  %d\n", getppid());
			printf("Child the value of i is %d\n", i);
		}
	}
	else
	{
		waitpid(pid, &status, 0);
		printf("status %d\n", status);
//		wait(NULL);
		fprintf(stderr, "PARENT:The value of child pid is %d\n", pid);
	}

	exit(0);
}
