 /*************************************************************************
	> File Name: alrm.c
	> Author: free
	> Mail: fancanglang@foxmail.com 
	> Created Time: Sat 07 Jul 2018 05:27:54 PM CST
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>

int main(void)
{
	int counter;
	alarm(1);
	for(counter=0; 1; counter++)
		printf("counter=%d\t", counter);

	return 0;
}
