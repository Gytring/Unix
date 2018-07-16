#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

void error_sys(char *str)
{
	perror(str);
	exit(1);
}

void do_sig_child(int signo)
{
	/*
	while(!(waitpid(0, NULL, WNOHANG) == -1))
		;
		*/
	int status;
	pid_t pid;

	while(pid =(waitpid(0, &status, WNOHANG) > 0))
	{
		if(WIFEXITED(status))
			printf("child %d exit %d\n", pid, WEXITSTATUS(status));
		else if(WIFSIGNALED(status))
			printf("child %d cancle signal %d\n", pid, WTERMSIG(status));
	}
}
int main(void)
{
	int i ;
	pid_t pid;
	//阻塞SIGCHILD
	for(i = 0; i < 10; i++)
	{
		if((pid = fork()) == 0)
			break;
		else if(pid < 0)
			error_sys("fork");
	}

	if(pid == 0)
	{
		int n = 18;
		while(n--)
		{
			printf("Child ID %d\n", getpid());
			sleep(1);
		}
		return i;
	}
	else if(pid > 0)
	{
		//先设置捕捉
		//再解除对SIGCHILD的阻塞
		struct sigaction act;

		act.sa_handler = do_sig_child;
		sigemptyset(&act.sa_mask);
		act.sa_flags = 0;
		sigaction(SIGCHLD, &act, NULL);
		while(1)
		{
			printf("Parent ID %d\n", getpid());
			sleep(1);
		}
	}

	return 0;

}
