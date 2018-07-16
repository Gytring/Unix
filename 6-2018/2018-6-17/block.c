 /*************************************************************************
	> File Name: block.c
	> Author: free
	> Mail: fancanglang@foxmail.com 
	> Created Time: Sun 17 Jun 2018 10:52:52 AM CST
 ************************************************************************/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main(void)
{
	char buff[1024];
	int len;

	len = read(STDIN_FILENO, buff, sizeof(buff));
	write(STDOUT_FILENO, buff, len);

	return 0;
}
