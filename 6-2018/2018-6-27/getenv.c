 /*************************************************************************
	> File Name: getenv.c
	> Author: free
	> Mail: fancanglang@foxmail.com 
	> Created Time: Wed 27 Jun 2018 09:19:45 AM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	printf("The PWD is %s\n", getenv("PWD"));
	printf("The USER is %s\n", getenv("USER"));
	return 0;
}
