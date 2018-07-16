 /*************************************************************************
	> File Name: x++.c
	> Author: free
	> Mail: fancanglang@foxmail.com 
	> Created Time: Thu 28 Jun 2018 02:13:34 PM CST
 ************************************************************************/

#include <stdio.h>

int main(void)
{
	int x = 5;
	printf("%d and ", sizeof(x++));
	printf("%d\n", x);
	return 0;
}
