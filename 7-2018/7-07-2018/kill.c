 /*************************************************************************
	> File Name: kill.c
	> Author: free
	> Mail: fancanglang@foxmail.com 
	> Created Time: Sat 07 Jul 2018 05:32:04 PM CST
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>

int main(int argc, char *argv[])
{
	if(argc < 3)
	{
		printf("./mykill signal pid\n");
		exit(1);
	}

	if(kill((pid_t)atoi(argv[2]), atoi(argv[1])) < 0)
	{
		perror("kill");
		exit(1);
	}

	return 0;
}


