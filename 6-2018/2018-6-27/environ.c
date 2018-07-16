 /*************************************************************************
	> File Name: environ.c
	> Author: free
	> Mail: fancanglang@foxmail.com 
	> Created Time: Wed 27 Jun 2018 09:13:15 AM CST
 ************************************************************************/

#include <stdio.h>

int main(void)
{
	extern char **environ;
	int i;
	for(i = 0; environ[i] != NULL; i++)
	{
		printf("%s\n", environ[i]);
	}

	return 0;
}

