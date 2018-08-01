#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/fcntl.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFSZIE 4096
#define FILEMODE 0664
#define DIRMODE	 0775
#define PATHSIZE 255

//错误提示输出
void oops(char *, char *);
//获取文件的stat结构体信息
struct stat get_stat(const char *pathname);
//复制文件
void copy_file(char *des_str, char *src_str);
//复制一个目录
void copy_dir(char *des_str, char *src_str);

int main(int argc, char *argv[])
{
	struct stat st_buf, src_buf, des_buf;
	int i;

	if(argc < 3)
	{
		fprintf(stderr, "usage: %s source ... destination\n", *argv);
	}

	if(argc ==3 )
	{
		src_buf = get_stat(argv[1]);
		des_buf = get_stat(argv[2]);
		if(S_ISDIR(src_buf.st_mode) && S_ISDIR(src_buf.st_mode))
			copy_dir(argv[1], argv[2]);
		else
			copy_file(argv[1], argv[2]);
	}

	st_buf = get_stat(argv[argc - 1]);
	if(argc > 3)
	{
		if(!S_ISDIR(st_buf.st_mode))
		{
			fprintf(stderr, "%s:%s is not diretory!\n", argv[0], argv[argc-1]);
			exit(0);
		}
		for(i = 1; i < argc - 1; i++)
		{
			if(access(argv[i], F_OK))
			{
				fprintf(stderr, "Error: %s is not exist!", argv[i]);
				exit(1);
			}
			copy_dir(argv[i], argv[argc-1]);
		}

	}
	exit(0);
}

void oops(char *str1, char *str2)
{
	fprintf(stderr, "Error: %s", str1);
	perror(str2);
	exit(1);
}

struct stat get_stat(const char *pathname)
{
	struct stat st_buf;
	if(lstat(pathname, &st_buf) < 0)
	{
		perror("lstat");
		exit(1);
	}
	return st_buf;
}

void copy_file(char *src_str, char *des_str)
{
	int in_fd, out_fd, n_chars;
	struct stat st_buf;
	char *dir_str;
	char buf[BUFFSZIE];
	char re_buf[PATHSIZE];
	getcwd(re_buf, PATHSIZE);

	if((in_fd = open(src_str, O_RDONLY)) == -1)
	{
		oops("Cannot open ", src_str);
	}
	
	if(access(des_str, F_OK) )
	{
		printf("%s\n", re_buf);
		st_buf = get_stat(des_str);
		if(S_ISDIR(st_buf.st_mode))
		{
			dir_str = src_str;	
			chdir(des_str);
		}
		else
		{
			printf("1\n");
			dir_str = des_str;
		}
	}
	else
	{
		dir_str = des_str;
		printf("2\n");
	}

	printf("%s", dir_str);
	if((out_fd = creat(dir_str, FILEMODE)) == -1)
	{
		oops("Cannot creat ", des_str);
	}
	chdir(re_buf);

	while((n_chars = read(in_fd, buf, BUFFSZIE)) > 0)
	{
		if((write(out_fd, buf, n_chars)) != n_chars)
			oops("Write error to ", dir_str);
	}
	if(n_chars == -1)
		oops("Read error from ", src_str);

	if(close(in_fd)== -1 || close(out_fd) == -1)
		oops("Closing files error ", "");
}

void copy_dir(char *src_str, char *des_str)
{
	DIR *dp;
	char des_dir_buf[PATHSIZE];
	char src_dir_buf[PATHSIZE];
	struct dirent *dirp;
	struct stat src_buf;

	src_buf = get_stat(src_str);
	if(S_ISDIR(src_buf.st_mode))
	{
		getcwd(src_dir_buf, PATHSIZE);
		chdir(des_str);
		mkdir(src_str, DIRMODE);
		chdir(src_dir_buf);
		dp = opendir(src_str);
		chdir(src_str);
		if(dp == NULL)
		{
			perror("opendir");
			exit(1);
		}
		while((dirp = readdir(dp)) != NULL)
		{
			src_buf = get_stat(dirp->d_name);
			if(0 == strcmp(dirp->d_name, ".") || 0 == strcmp(dirp->d_name, ".."))
				continue;
			else if(S_ISDIR(src_buf.st_mode))
			{
				chdir(des_str);
				mkdir(dirp->d_name, DIRMODE);
				chdir(dirp->d_name);
				getcwd(des_dir_buf, PATHSIZE);
				chdir(src_dir_buf);
				copy_dir(dirp->d_name, des_dir_buf);
				chdir(src_dir_buf);
			}
			else
			{
				copy_file(dirp->d_name, des_str);
			}
		}
		closedir(dp);
	}
	else
		copy_file(src_str, des_str);
}
