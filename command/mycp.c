#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/fcntl.h>
#include <unistd.h>
#include <fcntl.h>

//缓冲区的大小
#define BUFFSZIE 4096
//创建文件权限
#define FILEMODE 0664
//创建目录权限
#define DIRMODE	 0775
//创建目录的最大长度
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
	//获取命令行参数的属性
	struct stat st_buf, src_buf, des_buf;
	char re_dir[PATHSIZE];
	int i;
	//获取当前目录
	getcwd(re_dir, PATHSIZE);

	if(argc < 3)
	{
		fprintf(stderr, "usage: %s source ... destination\n", *argv);
	}

	//两个参数，四种情况
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
	//复制多个文件和目录
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
			chdir(re_dir);
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
		printf("ERROR: %s\n", pathname);
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
	
	if(!access(des_str, F_OK) )
	{
		st_buf = get_stat(des_str);
		if(S_ISDIR(st_buf.st_mode))
		{
			dir_str = src_str;	
			chdir(des_str);
		}
		else
		{
			dir_str = des_str;
		}
	}
	else
	{
		dir_str = des_str;
	}

	if((out_fd = creat(dir_str, FILEMODE)) == -1)
	{
		oops("Cannot creat ", des_str);
	}

	while((n_chars = read(in_fd, buf, BUFFSZIE)) > 0)
	{
		if((write(out_fd, buf, n_chars)) != n_chars)
			oops("Write error to ", dir_str);
	}
	if(n_chars == -1)
		oops("Read error from ", src_str);

	if(close(in_fd)== -1 || close(out_fd) == -1)
		oops("Closing files error ", "");
	//返回原目录
	chdir(re_buf);
}

void copy_dir(char *src_str, char *des_str)
{
	DIR *dp;
	char des_dir_buf[PATHSIZE];
	char src_dir_buf[PATHSIZE];
	char src_dir_buf_i[PATHSIZE];
	struct dirent *dirp;
	struct stat src_buf;

	src_buf = get_stat(src_str);
	if(S_ISDIR(src_buf.st_mode))
	{
		//目录的跳转及记录
		getcwd(src_dir_buf, PATHSIZE);
		chdir(des_str);
		mkdir(src_str, DIRMODE);
		chdir(src_str);
		getcwd(des_dir_buf, PATHSIZE);
		chdir(src_dir_buf);
		dp = opendir(src_str);
		chdir(src_str);
		getcwd(src_dir_buf_i, PATHSIZE);
		if(dp == NULL)
		{
			perror("opendir");
			exit(1);
		}
		//循环获取目录信息
		while((dirp = readdir(dp)) != NULL)
		{
			src_buf = get_stat(dirp->d_name);
			if(0 == strcmp(dirp->d_name, ".") || 0 == strcmp(dirp->d_name, ".."))
				continue;
			else if(S_ISDIR(src_buf.st_mode))
			{
				//进行递归调用
				copy_dir(dirp->d_name, des_dir_buf);
			}
			else
			{
				//复制文件，进入目的目录
				chdir(src_dir_buf_i);
				copy_file(dirp->d_name, des_dir_buf);
			}
		}
		closedir(dp);
	}
	else
	{
		copy_file(src_str, des_str);
	}
	//返回之前的目录
	chdir(src_dir_buf);
}
