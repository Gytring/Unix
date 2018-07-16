 /*************************************************************************
	> File Name: pwd.c
	> Author: free
	> Mail: fancanglang@foxmail.com 
	> Created Time: Fri 22 Jun 2018 09:11:41 AM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define SIZE 4096

int main(void)
{
	char buf[SIZE];

	chdir("/var/log");
	

	printf("The Diretory is %s\n", getcwd(buf, sizeof(buf)));
	return 0;

}
