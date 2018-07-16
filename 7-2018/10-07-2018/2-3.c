 /*************************************************************************
	> File Name: 2-3.c
	> Author: free
	> Mail: fancanglang@foxmail.com 
	> Created Time: Tue 10 Jul 2018 09:21:38 AM CST
 ************************************************************************/

#include <stdio.h>
#include "apue.h"
#include <fcntl.h>

char buf1[] = "abcdefgij";
char buf2[] = "ABCDEFGIJ";

int main(void)
{
	int fd;
	if((fd = creat("file.hole", FILE_MODE)) < 0)
		err_sys("creat error");
	
	if(write(fd, buf1, 10) != 10)
		err_sys("buf1 write error!");

	if(lseek(fd, 16384, SEEK_SET) == -1)
		err_sys("lseek error");

	if(write(fd, buf2, 10) != 10)
		err_sys("buf2 write error");

	exit(0);
}
