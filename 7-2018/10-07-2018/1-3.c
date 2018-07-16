 /*************************************************************************
	> File Name: 1-3.c
	> Author: free
	> Mail: fancanglang@foxmail.com 
	> Created Time: Tue 10 Jul 2018 09:17:19 AM CST
 ************************************************************************/

#include <stdio.h>
#include "apue.h"

int main(void)
{
	if(lseek(STDIN_FILENO, 0, SEEK_CUR) == -1)
		printf("can't set seek\n");
	else
		printf("seek OK\n");

	exit(0);
}
