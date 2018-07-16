 /*************************************************************************
	> File Name: dir.c
	> Author: free
	> Mail: fancanglang@foxmail.com 
	> Created Time: Tue 26 Jun 2018 04:05:44 PM CST
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#define SIZE 4096

int main(void)
{
	char buf[SIZE];

	getcwd(buf, sizeof(buf));

	printf("The Diretory is %s\n", buf);

	chdir("/");
	getcwd(buf, sizeof(buf));
	printf("The Diretory is %s\n", buf);

	return 0;
}

