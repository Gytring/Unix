 /*************************************************************************
	> File Name: open.c
	> Author: free
	> Mail: fancanglang@foxmail.com 
	> Created Time: Sat 16 Jun 2018 10:17:15 AM CST
 ************************************************************************/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[])
{
	int fd;
	char buff[1024] = "gvvcc";
	if(argc < 2)
	{
		printf("./open filename\n");
		exit(1);
	}

	umask(0)
	//fd = open(argv[1], O_CREAT | O_RDWR, 0644);
	fd = open(argv[1], O_RDWR | O_APPEND);
	write(fd, buff, strlen(buff));
	printf("fd=%d\n", fd);
	close(fd);

	return 0;
}
