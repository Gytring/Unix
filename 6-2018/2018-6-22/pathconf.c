 /*************************************************************************
	> File Name: pathconf.c
	> Author: free
	> Mail: fancanglang@foxmail.com 
	> Created Time: Fri 22 Jun 2018 09:19:21 AM CST
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>

int main(void)
{
	printf("The _PC_LINK_MAX is %ld\n", fpathconf(STDOUT_FILENO, _PC_LINK_MAX));
	printf("The _PC_MAX_CANON is %ld\n", fpathconf(STDOUT_FILENO, _PC_MAX_CANON));
	printf("The _PC_MAX_INPUT is %ld\n", fpathconf(STDOUT_FILENO, _PC_MAX_INPUT));
	printf("The _PC_NAME_MAX is %ld\n", fpathconf(STDOUT_FILENO, _PC_NAME_MAX));
	printf("The _PC_PATH_MAX is %ld\n", fpathconf(STDOUT_FILENO, _PC_PATH_MAX));
	printf("The _PC_PIPE_BUF is %ld\n", fpathconf(STDOUT_FILENO, _PC_PIPE_BUF));
	printf("The _PC_CHOWN_RESTRICTED is %ld\n", fpathconf(STDOUT_FILENO, _PC_CHOWN_RESTRICTED));
	printf("The _PC_NO_TRUNC is %ld\n", fpathconf(STDOUT_FILENO, _PC_NO_TRUNC));
	printf("The _PC_VDISABLE is %ld\n", fpathconf(STDOUT_FILENO, _PC_VDISABLE));

	printf("The _PC_NAME_MAX is %ld\n", pathconf("pwd.c", _PC_NAME_MAX));
	
	return 0;
}
