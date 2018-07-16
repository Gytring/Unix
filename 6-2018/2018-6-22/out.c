/*************************************************************************
  > File Name: out.c
  > Author: free
  > Mail: fancanglang@foxmail.com 
  > Created Time: Fri 22 Jun 2018 02:24:16 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h> 
#include <stdio.h> 
#include <unistd.h> 

int main()
{
	fflush(stdout);
	setvbuf(stdout,NULL,_IONBF,0);
	printf("test stdout\n");
	freopen("test1.txt","w",stdout); //注: 不要使用这类的代码 stdout = fopen("test1.txt","w");   这样的话输出很诡异的. 最好使用  freopen 这类的函数来替换它.
	printf("test file\n");
	freopen("/dev/tty","w",stdout);
	printf("test tty\n");
}
