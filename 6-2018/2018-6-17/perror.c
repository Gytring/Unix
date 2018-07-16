 /*************************************************************************
	> File Name: perror.c
	> Author: free
	> Mail: fancanglang@foxmail.com 
	> Created Time: Sun 17 Jun 2018 11:30:10 AM CST
 ************************************************************************/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

int main(void)
{
	int fd = open("abc", O_WRONLY);

	if(fd < 0)
	{
		printf("erron = %d\n", errno);
		printf("freegcc: %s\n", strerror(errno));
		//perror("freegcc: ");
	}

	printf("%d\n", fd);
	return 0;
}

