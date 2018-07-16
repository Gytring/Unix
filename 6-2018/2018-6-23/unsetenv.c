 /*************************************************************************
	> File Name: unsetenv.c
	> Author: free
	> Mail: fancanglang@foxmail.com 
	> Created Time: Sat 23 Jun 2018 05:59:53 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	printf("PATH=%s\n", getenv("PATH"));
	setenv("PATH", "hello", 1);
	printf("PATH=%s\n", getenv("PATH"));
	return 0;
}
