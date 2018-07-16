 /*************************************************************************
	> File Name: chmod.c
	> Author: free
	> Mail: fancanglang@foxmail.com 
	> Created Time: Mon 18 Jun 2018 03:18:08 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
	int mode;
	if( argc < 3)
	{
		printf("./mychmod mode filename]\n");
		exit(1);
	}

	mode = atoi(argv[1]);
	chmod(argv[2], mode);

	return 0;
}
