 /*************************************************************************
	> File Name: nl.c
	> Author: free
	> Mail: fancanglang@foxmail.com 
	> Created Time: Fri 29 Jun 2018 09:51:28 AM CST
 ************************************************************************/

#include <stdio.h>

int main(void)
{
	long nl, c;

	nl = 0;
	while((c = getchar()) != EOF)
	{
		if(c == '\n')
			nl++;
	}

	printf("%d\n", nl);
	return 0;
}
