 /*************************************************************************
	> File Name: access.c
	> Author: free
	> Mail: fancanglang@foxmail.com 
	> Created Time: Mon 18 Jun 2018 03:11:06 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>

int main(void)
{
	if(access("abc", F_OK) < 0)
	{
		perror("abc");
		exit(1);
	}

	printf("abc is ok\n");
	return 0;
}
