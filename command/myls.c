#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/fcntl.h>
#include <dirent.h>
#include <errno.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>

#define BUFSIZE 4096
//由uid转换为用户名
char *uid_to_name(uid_t uid)
{
	struct passwd *passwd;
	passwd = getpwuid(uid);
	return passwd->pw_name;
}

//由gid转换为用户组名
char *gid_to_name(gid_t gid)
{
	struct group *group;
	group = getgrgid(gid);
	return group->gr_name;
}

//获取文件类型及权限
void get_type(int mode, char *str)
{
	strcpy(str, "----------");
	//获取文件类型
	if(S_ISDIR(mode))
		str[0] = 'd';
	if(S_ISCHR(mode))
		str[0] = 'c';
	if(S_ISBLK(mode))
		str[0] = 'b';
	if(S_ISFIFO(mode))
		str[0] = 'p';
	if(S_ISLNK(mode))
		str[0] = 'l';
	if(S_ISSOCK(mode))
		str[0] = 's';

	//获取文件权限
	if(mode & S_IRUSR)	
		str[1] = 'r';

	if(mode & S_IWUSR)
		str[2] = 'w';
	if(mode & S_ISUID)
		str[3] = 's';
	else if(mode & S_IXUSR)
		str[3] = 'x';
	if(mode & S_IRGRP)
		str[4] = 'r';
	if(mode & S_IWGRP)
		str[5] = 'w';
	if(mode & S_ISGID)
		str[6] = 's';
	else if(mode & S_IXGRP)
		str[6] = 'x';
	if(mode & S_IROTH)
		str[7] = 'r';
	if(mode & S_IWOTH)
		str[8] = 'w';
	if(mode & S_ISVTX)
		str[9] = 't';
	else if(mode & S_IXOTH)
		str[9] = 'x';
}

//获取一个目录的所有文件信息
void get_files( const char *str)
{
	DIR *dp;
	struct dirent *dirp;
	struct stat stat_buf;
	int flag;
	char str_mode[11];
	char buf[BUFSIZE];

	getcwd(buf, BUFSIZE);
//	printf("%s\n",buf);
	chdir(str);
	getcwd(buf, BUFSIZE);
//	printf("%s\n",buf);
	dp = opendir(str);
	if(dp == NULL)
	{
		perror("open");
		exit(1);
	}

	while((dirp = readdir(dp)) != NULL)
	{
		flag = lstat(dirp->d_name, &stat_buf);
		if(flag < 0)
		{
			perror("lstat");
			exit(1);
		}

		//除去.和..
		if(S_ISDIR(stat_buf.st_mode))
		{
			if(strcmp(dirp->d_name, ".") == 0 || strcmp(dirp->d_name, "..") == 0)
				continue;
		}

		get_type(stat_buf.st_mode, str_mode);
		printf("%s", str_mode);
		printf("%4d ",(int)stat_buf.st_nlink);
		printf("%-8s%-8s", uid_to_name(stat_buf.st_uid), gid_to_name(stat_buf.st_gid));
		printf("%8ld ", stat_buf.st_size);
		printf("%.12s ", ctime((time_t *)&stat_buf.st_mtim) + 4);
		printf("%s\n", dirp->d_name);
	}
	closedir(dp);
}

int main(int argc, char *argv[])
{
	//实现ls .
	if(argc == 1)
	{
		get_files(".");
	}

	//实现ls -l
	if(argc == 2)
	{
		get_files(argv[1]);
	}

	if(argc > 2)
	{
		printf("Usage:./myls -l\n");
		exit(1);
	}

	return 0;
}
