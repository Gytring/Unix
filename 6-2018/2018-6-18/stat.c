 /*************************************************************************
	> File Name: stat.c
	> Author: free
	> Mail: fancanglang@foxmail.com 
	> Created Time: Mon 18 Jun 2018 02:40:19 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <time.h>
#define S_IURWX (S_IRUSR | S_IWUSR | S_IXUSR)  
#define S_IGRWX (S_IRGRP | S_IWGRP | S_IXGRP)  
#define S_IORWX (S_IROTH | S_IWOTH | S_IXOTH)  
  
#define S_IUGORWX (S_IURWX | S_IGRWX | S_IORWX)

void set_rwx(struct stat *buf, mode_t S_IXXXX);  
void clr_rwx(struct stat *buf, mode_t S_IXXXX);  
//void get_rwx(const struct stat *buf, char *rwx);
void get_rwx(struct stat *buf);


int main(int argc, char *argv[])
{
	struct stat s_buf;

	if(argc < 2)
	{
		printf("./stat filename\n ");
		exit(1);
	}

	if( stat(argv[1], &s_buf) < 0)
	{
		perror("stat");
		exit(1);
	}

	printf("%s\t%ld\t", argv[1], s_buf.st_size);
	get_rwx(&s_buf);
	return 0;


}


/*设置权限位*/  
void set_rwx(struct stat *buf, mode_t S_IXXXX)  
{  
    buf->st_mode = buf->st_mode | S_IXXXX;  
}  
  
/*清除权限位*/  
void clr_rwx(struct stat *buf, mode_t S_IXXXX)  
{  
    buf->st_mode = buf->st_mode & ~S_IXXXX;  
}  
  
/*模拟ls -l 命令打印权限位*/  
//void get_rwx(const struct stat *buf, char *rwx)  
void get_rwx(struct stat *buf)  
{  
  
/*rwx[0]留作文件类型标识，不在此例演示*/  
  
	if (S_ISSOCK(buf->st_mode))
		printf("s");

	if (S_ISLNK(buf->st_mode))
		printf("l");

	if (S_ISREG(buf->st_mode))
		printf("-");

	if (S_ISBLK(buf->st_mode))
		printf("b");

	if (S_ISDIR(buf->st_mode))
		printf("d");

	if (S_ISCHR(buf->st_mode))
		printf("c");

	if (S_ISFIFO(buf->st_mode))
		printf("f");
	
    if (buf->st_mode & S_IRUSR)  
  //      rwx[1] = 'r';  
		printf("r");
    else  
    //    rwx[1] = '-';  
		printf("-");
  
    if (buf->st_mode & S_IWUSR)  
      //  rwx[2] = 'w';  
		printf("w");
    else  
        //rwx[2] = '-';  
		printf("-");
  
	if (buf->st_mode & S_ISUID)
		printf("s");
	else if (buf->st_mode & S_IXUSR)  
       // rwx[3] = 'x';  
		printf("x");
	else  
       // rwx[3] = '-';  
		printf("-");
  
    if (buf->st_mode & S_IRGRP)  
        //rwx[4] = 'r';  
		printf("r");
    else  
       // rwx[4] = '-';  
		printf("-");
  
    if (buf->st_mode & S_IWGRP)  
        //rwx[5] = 'w';  
		printf("w");
    else  
        //rwx[5] = '-';  
		printf("-");
  
	if (buf->st_mode & S_ISGID)
		printf("s");
	else if (buf->st_mode & S_IXGRP)  
        //rwx[6] = 'x';  
		printf("x");
    else  
       // rwx[6] = '-';  
		printf("-");
  
    if (buf->st_mode & S_IROTH)  
        //rwx[7] = 'r';  
		printf("r");
    else  
        //rwx[7] = '-';  
		printf("-");
  
    if (buf->st_mode & S_IWOTH)  
        //rwx[8] = 'w';  
		printf("w");
    else  
        //rwx[8] = '-';  
		printf("-");
		
	if (buf->st_mode & S_ISVTX) 
		printf("t\n");
	else if (buf->st_mode & S_IXOTH)  
//        rwx[9] = 'x';  
		printf("x\n");
    else  
  //      rwx[9] = '-';  
		printf("-\n");
}  
