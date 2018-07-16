 /*************************************************************************
	> File Name: print.c
	> Author: free
	> Mail: fancanglang@foxmail.com 
	> Created Time: Mon 25 Jun 2018 09:50:53 AM CST
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#define  SIZE 4096

int main(int argc, char *argv[])
{
	int fd, fd_save;

	if(argc < 2)
	{
		printf("./print filename!\n");
		exit(1);
	}

	umask(0);
	fd = open(argv[1], O_WRONLY | O_CREAT, 0644);
	if(fd < 0)
	{
		perror("open");
		exit(1);
	}

	dup2(fd, STDOUT_FILENO);//复制文件描述符，STDOUT_FILENO指向了argv[1]
	close(fd);
	printf("This is a suprise of Hello World!\n");//输入到STDOUT_FILENO，重定向到argv[1]

	return 0;
}
