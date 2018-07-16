 /*************************************************************************
	> File Name: lseek.c
	> Author: free
	> Mail: fancanglang@foxmail.com 
	> Created Time: Sun 17 Jun 2018 02:58:55 PM CST
 ************************************************************************/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>

int main(void)
{
	int fd = open("abc", O_RDWR);
	if(fd < 0)
	{
		perror("open abc ");
		exit(1);
	}

	//拓展文件一定要有一次写操作
	lseek(fd, 0x1000, SEEK_SET);

	write(fd, "a", 1 );
	close(fd);

	//获取文件大小
	fd = open("hello", O_RDWR);
	if(fd < 0)
	{
		perror("open hello");
		exit(1);
	}

	printf("hello size = %d\n", lseek(fd, 0, SEEK_END));
	close(fd);
	return 0;
}
