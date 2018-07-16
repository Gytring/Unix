 /*************************************************************************
	> File Name: setenv.c
	> Author: free
	> Mail: fancanglang@foxmail.com 
	> Created Time: Wed 27 Jun 2018 09:27:00 AM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	printf("The USER=%s\n", getenv("USER"));
	setenv("USER", "kuai", 1);
	printf("The USER=%s\n", getenv("USER"));
	return 0;
}
