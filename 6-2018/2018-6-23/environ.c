 /*************************************************************************
	> File Name: environ.c
	> Author: free
	> Mail: fancanglang@foxmail.com 
	> Created Time: Sat 23 Jun 2018 02:42:35 PM CST
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
