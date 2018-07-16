 /*************************************************************************
	> File Name: chmod.c
	> Author: free
	> Mail: fancanglang@foxmail.com 
	> Created Time: Mon 25 Jun 2018 01:44:29 PM CST
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <errno.h>

int main(void)
{
	umask(0);

	chmod("freegcc", 0777);
	return 0;
}
