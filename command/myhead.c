#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/fcntl.h>

#define BUFSIZE 4096
#define MAXSIZE 65536
#define LEN 10

//打印文件
void print_file(const char *pathname, int len);
//获取文件长度
int get_lines(const char *pathname);
//判断文件是否为目录，为目录返回1，不为目录返回0
int get_type(const char *pathname);

int main(int argc, char *argv[])
{
	int len;

	if(argc == 1)
	{
		fprintf(stderr, "\e[36mUsage: %s filename or %s number filename.\e[0m\n", argv[0], argv[0]);
		fprintf(stderr, "\e[33mAnd you have no file to head!\e[0m\n");
		exit(1);
	}
	if(argc == 2)
	{
		len = LEN;
		print_file(argv[1], len);
	}

	if(argc == 3)
	{
		len = atoi(argv[1]);
		print_file(argv[2], len);	
	}

	if(argc > 3)
	{
		fprintf(stderr, "\e[35mUsage: %s filename OR %s number filename\e[0m\n", argv[0], argv[0]);
		exit(1);
	}

	exit(1);
}

void print_file(const char *pathname, int len)
{
	int i = 0, n;
	FILE *fp;
	char buf[BUFSIZE];

	n = get_lines(pathname);
	if(len < 0)
	{
		len = -len;
		if(len > n)
		{
			exit(1);
		}
		len =  n - len;
	}
	fp = fopen(pathname, "r");
	if(fp == NULL)
	{
		perror(pathname);
		exit(1);
	}

	while(!feof(fp))
	{
		if(i <= len)
		{
			printf("%s", buf);
			fgets(buf, BUFSIZE, fp);
			i++;
		}
		else
		{
			exit(1);
		}
	}
	fclose(fp);
}

int get_lines(const char *pathname)
{
	int n = 0, flag;
	FILE *fp;
	char buf[BUFSIZE];

	if(access(pathname, F_OK))
	{
		perror(pathname);
		exit(1);
	}

	flag = get_type(pathname);
	if(flag)
	{
		fprintf(stderr,"Error: %s is a diretory!\n", pathname);
		exit(1);
	}
	fp = fopen(pathname, "r");
	if(fp == NULL)
	{
		perror(pathname);
		exit(1);
	}

	fgets(buf, BUFSIZE, fp);
	while(!feof(fp))
	{
		n++;		
		fgets(buf, BUFSIZE, fp);
	}
	fclose(fp);
	return n;
}

int get_type(const char *pathname)
{
	struct stat st_buf;

	if(lstat(pathname, &st_buf) < 0)
	{
		perror(pathname);
		exit(1);
	}
	if(S_ISDIR(st_buf.st_mode))
	{
		return 1;
	}
	else
		return 0;
}
