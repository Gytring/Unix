 /*************************************************************************
	> File Name: lseek.c
	> Author: free
	> Mail: fancanglang@foxmail.com 
	> Created Time: Thu 21 Jun 2018 03:08:39 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

int main(int argc, char *argv[])
{
	int fd, lsk, wr;

	if(argc < 2)
	{
		printf("./lseek filename\n");
		exit(1);
	}

	fd = open(argv[1], O_RDWR | O_CREAT, 0777);

	if(fd < 0)
	{
		perror("open");
		exit(1);
	}

	lsk = lseek(fd, 10*1024*1024 - 1, SEEK_SET);

	if(lsk < 0)
	{
		perror("lseek");
		exit(1);
	}

	wr = write(fd,"c", 1);

	if(wr < 0)
	{
		perror("write");
		exit(1);
	}

	close(fd);

	fd = open(argv[1], O_RDWR, 0777);
	if(fd < 0)
	{
		perror("open2");
		exit(1);
	}

	printf("%s size is %d\n", argv[1], lseek(fd,0, SEEK_END));
	close(fd);
	return 0;
}
