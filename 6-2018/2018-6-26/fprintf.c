 /*************************************************************************
	> File Name: fprintf.c
	> Author: free
	> Mail: fancanglang@foxmail.com 
	> Created Time: Tue 26 Jun 2018 05:18:00 PM CST
 ************************************************************************/

#include <stdio.h>

FILE *stream;

int main(void)
{
	char s[] = "freegcc and hello world";
	char c = '\n';

	stream = fopen("freegcc", "w");
	fprintf(stream, "%s", s);
	fprintf(stdout, "hello world\n");

	return 0;
}
