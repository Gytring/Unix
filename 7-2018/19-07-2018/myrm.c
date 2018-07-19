#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/fcntl.h>
#include <sys/stat.h>

//获取文件类型，主要是目录和其他文件,目录返回1，其他文件返回
int get_type(int mode)
{
	if(S_ISDIR(mode))
		return 1;
	else
		return 0;
}

//删除文件
void rm_file(const char *pathname)
{
	unlink(pathname);
}

//删除目录
void rm_dir(const char *pathname)
{
		rmdir(pathname);
}

//获取目录的文件并删除
void dir_pathname(const char *pathname)
{
	DIR *dp;
	struct dirent *dirp;
	struct stat dir_buf;
	int dir_flag;

	dp = opendir(pathname);
	chdir(pathname);
	if(dp == NULL)
	{
		perror("open");
		exit(1);
	}
	while((dirp = readdir(dp)) != NULL)
	{
		dir_flag = lstat(dirp->d_name, &dir_buf) ;
		if(dir_flag < 0)
		{
			perror("lstat");
			exit(1);
		}
		if(S_ISDIR(dir_buf.st_mode))
		{
			if(0 == strcmp(dirp->d_name, ".") || 0 == strcmp(dirp->d_name, ".."))
				continue;
			else
				dir_pathname(dirp->d_name);
		}
		if(0 == get_type(dir_buf.st_mode))
		{
			unlink(dirp->d_name);
		}
	}
	closedir(dp);
	chdir("..");
	rm_dir(pathname);
}
//判断文件是否存在
void is_exist(const char *pathname)
{
	if(access(pathname, F_OK) < 0)
	{
		printf("%s is not exist\n", pathname);
		exit(1);
	}
}

int main(int argc, char *argv[])
{
	struct stat argv_buf;
	if(1 == argc)
	{
		printf("Usage:./myrm filename OR ./myrm -rf diretory\n");
		exit(1);
	}
	if(2 == argc)
	{
		is_exist(argv[1]);
		if(lstat(argv[1], &argv_buf) < 0)
		{
			perror("lstat");
			exit(1);
		}
		if(get_type(argv_buf.st_mode))
		{
			printf("rm: cannot remove ‘%s’: Is a directory\n", argv[1]);
		}
		rm_file(argv[1]);
	}
	if(3 == argc)
	{
		if(strcmp(argv[1], "-rf") != 0)
		{
			printf("Option Error!\n");
			exit(1);
		}
		if(lstat(argv[2], &argv_buf) < 0)
		{
			perror("lstat");
			exit(1);
		}
		if(get_type(argv_buf.st_mode))
		{
			dir_pathname(argv[2]);
		}
		else
		{
			rm_file(argv[2]);
		}
	}
	if(argc > 3)
	{
		printf("Usage:./myrm filename OR ./myrm -rf diretory\n");
		exit(1);
	}

	return 0;
}
