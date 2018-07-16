 /*************************************************************************
	> File Name: sizeof.c
	> Author: free
	> Mail: fancanglang@foxmail.com 
	> Created Time: Thu 28 Jun 2018 11:05:08 AM CST
 ************************************************************************/

#include <stdio.h>
#include <string.h>

int main(void)
{
	int i;
	int *p;
	char *q;
	float j;
	char a[] = "hello world!";

	printf("the size of int %d\n", sizeof(i));
	printf("the size of point %d\n", sizeof(p));
	printf("the size of float %d\n", sizeof(j));
	printf("the size of string a %d\n", sizeof(a));
	printf("the strlen of string a %d\n", strlen(a));

	q = a;
	printf("the size of q %d\n", sizeof(q));
	printf("the size of *q %d\n", sizeof(*q));
	printf("the strlen of q %d\n", strlen(q));

	return 0;
}

