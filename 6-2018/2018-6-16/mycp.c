 /*************************************************************************
	> File Name: mycp.c
	> Author: free
	> Mail: fancanglang@foxmail.com 
	> Created Time: Sat 16 Jun 2018 12:03:01 PM CST
 ************************************************************************/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#define SIZE 8192

int main(int argc, char *argv[])
{
	char buff[SIZE];
	int fd_src, fd_dest;
	int len;

	if(argc < 3)
	{
		printf("./mycp src dest\n");
		exit(1);
	}

	fd_src = open(argv[1], O_RDONLY);
	fd_dest = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0644);

	/*
	 *成功读到字节数
	 *读到文件末尾返回0
	 *读失败返回-1
	 */
	while((len = read(fd_src, buff, sizeof(buff))) > 0)
	{
		write(fd_dest, buff, len);
	}

	close(fd_src);
	close(fd_dest);

	return 0;
}

