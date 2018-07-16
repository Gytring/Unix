 /*************************************************************************
	> File Name: comments.c
	> Author: free
	> Mail: fancanglang@foxmail.com 
	> Created Time: Tue 26 Jun 2018 03:39:06 PM CST
 ************************************************************************/

#include <stdio.h>
#define A /*/*/0*/**/1

int main(void)
{
	if(A == 1)
	{
		printf("C 支持嵌套注释！\n");
	}

	if(A == 0)
	{
		printf("C 不支持嵌套注释\n");
	}

	return 0;
}
