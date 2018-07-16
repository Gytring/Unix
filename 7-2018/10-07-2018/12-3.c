 /*************************************************************************
	> File Name: 12-3.c
	> Author: free
	> Mail: fancanglang@foxmail.com 
	> Created Time: Tue 10 Jul 2018 10:43:34 AM CST
 ************************************************************************/

#include <stdio.h>
#include <fcntl.h>
#include "apue.h"

void set_fl(int fd, int flags)
{
	int val;

	if((val = fantl(fd, F_GETFL, 0)) < 0) 
		err_sys("fcntl F_GETFL error");

	val |= flags;

	if(fcntl(fd, F_SETFL, val) < 0)
		err_sys("fcntl F_SETFL error");
}
