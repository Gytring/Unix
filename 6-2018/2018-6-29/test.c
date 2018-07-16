 /*************************************************************************
	> File Name: test.c
	> Author: free
	> Mail: fancanglang@foxmail.com 
	> Created Time: Fri 29 Jun 2018 11:21:46 AM CST
 ************************************************************************/

#include <stdio.h>
#include <string.h>

int main(void)
{
	char str[10] = "gccreegnu";
	char buf[15] = "UNIX PROGRAMER";

	printf("sizeof(str) is %d\n", sizeof(str));
	printf("strlen(str) is %d\n", strlen(str));
	printf("sizeof(buf) is %d\n", sizeof(buf));
	printf("strlen(buf) is %d\n", strlen(buf));

	return 0;
}
