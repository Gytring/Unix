 /*************************************************************************
	> File Name: exec.c
	> Author: free
	> Mail: fancanglang@foxmail.com 
	> Created Time: Wed 27 Jun 2018 03:10:01 PM CST
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
	execlp("ps", "ps", "-o", "user,pid,%cpu,%mem,vsz,rss,tty,stat,start,time,command", NULL);
	perror("exec ps");
	exit(1);
}
