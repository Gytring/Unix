 /*************************************************************************
	> File Name: access.c
	> Author: free
	> Mail: fancanglang@foxmail.com 
	> Created Time: Mon 25 Jun 2018 01:29:18 PM CST
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

int main(int argc, char *argv[])
{
	if(argc < 2)
	{
		printf("./access filename!\n");
		exit(1);
	}

	int flag_r, flag_w, flag_x, flag_ok;

	flag_r = access(argv[1], R_OK);
	flag_w = access(argv[1], W_OK);
	flag_x = access(argv[1], X_OK);
	flag_ok = access(argv[1],F_OK);

	if(flag_ok < 0)
	{
		perror("access FOK");
		exit(1);
	}
	else
	{
		printf("F_OK\n");
	}


	if(flag_r < 0)
	{
		perror("access ROK");
		exit(1);
	}
	else
	{
		printf("R_OK\n");
	}

	if(flag_w < 0)
	{
		perror("access WOK");
		exit(1);
	}
	else
	{
		printf("W_OK\n");
	}

	
	if(flag_x < 0)
	{
		perror("access XOK");
		exit(1);
	}
	else
	{
		printf("X_OK\n");
	}

	return 0;
}
