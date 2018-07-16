 /*************************************************************************
	> File Name: stdout.c
	> Author: free
	> Mail: fancanglang@foxmail.com 
	> Created Time: Fri 22 Jun 2018 11:30:17 AM CST
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>
#define SIZE 4096

int main(int argc, char *argv[])
{
	int fd, fdtty;
	int len;
	char buf[SIZE];

	if(argc < 2)
	{
		printf("./stdout filename\n");
		exit(1);
	}
	
	umask(0);

	fd = open(argv[1], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if(fd < 0 )
	{
		perror("open");
		exit(1);
	}

	fdtty = open("/dev/tty", O_RDONLY | O_NONBLOCK);
	if(fdtty < 0)
	{
		perror("open /dev/tty");
	}

	//printf("hellod world");
	printf("%d\n", STDOUT_FILENO);
	if((len = read(fdtty, buf, sizeof(buf))) > 0)
	{
		write(fd, buf, len);
		printf("exit\n");
		exit(1);
	}

	close(fd);
	close(fdtty);

	return 0;
}
