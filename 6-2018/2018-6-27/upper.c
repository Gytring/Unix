 /*************************************************************************
	> File Name: upper.c
	> Author: free
	> Mail: fancanglang@foxmail.com 
	> Created Time: Wed 27 Jun 2018 03:20:56 PM CST
 ************************************************************************/

#include <stdio.h>

int main(void)
{
	int ch;

	while((ch = getchar()) != EOF)
	{
		putchar(toupper(ch));
		//putchar('\n');
	}
	return 0;
}
