 /*************************************************************************
	> File Name: test.c
	> Author: free
	> Mail: fancanglang@foxmail.com 
	> Created Time: Sun 01 Jul 2018 10:53:12 AM CST
 ************************************************************************/

#include <stdio.h>

int main(void)
{
	char *str = "hello";
	printf("%s\n", str);
	*str = 'H';
	printf("%s\n", str);
	return 8;
}
