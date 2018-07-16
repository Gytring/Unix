 /*************************************************************************
	> File Name: out.c
	> Author: free
	> Mail: fancanglang@foxmail.com 
	> Created Time: Sun 24 Jun 2018 11:44:32 AM CST
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	int fd, save_fd;
	char msg[] = "This is a test\n";

	if(argc < 2)
	{
		printf("./out filename\n");
		exit(1);
	}

	fd = open(argv[1], O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
	if(fd < 0)
	{
		perror("open");
		exit(1);
	}

	save_fd = dup(STDOUT_FILENO);
	dup2(fd, STDOUT_FILENO);
	close(fd);
	write(STDOUT_FILENO, msg, strlen(msg));
	close(save_fd);
	return 0;
}
