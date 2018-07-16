 /*************************************************************************
	> File Name: nc.c
	> Author: free
	> Mail: fancanglang@foxmail.com 
	> Created Time: Fri 29 Jun 2018 09:47:24 AM CST
 ************************************************************************/

#include <stdio.h>

int main(void)
{
	long nc;

	while(getchar() != EOF)
	{
		nc++;
	}

	printf("%d\n", nc);
	return 0;
}
