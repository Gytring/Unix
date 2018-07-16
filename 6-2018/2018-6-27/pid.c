 /*************************************************************************
	> File Name: pid.c
	> Author: free
	> Mail: fancanglang@foxmail.com 
	> Created Time: Wed 27 Jun 2018 02:55:58 PM CST
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>

int main(void)
{
	pid_t ptd, ppid;

	printf("The pid is %d\n", getpid());
	printf("The ppid is %d\n", getppid());

	uid_t real_uid, effective_uid;
	printf("The real uid is %d\n", getuid());
	printf("The effective is %d\n", geteuid());
	printf("The gid is %d\n", getgid());

	return 0;
}
