 /*************************************************************************
	> File Name: sigprocmask.c
	> Author: free
	> Mail: fancanglang@foxmail.com 
	> Created Time: Sun 08 Jul 2018 06:06:08 PM CST
 ************************************************************************/

#include <stdio.h>
#include <signal.h>

void printsigset(const sigset_t *set)
{
	int i;
	for(i = 1; i < 32; i++)
	{
		if(sigismember(set, i) == 1)
			putchar('1');
		else
			putchar('0');
	}
	puts("");
}

int main(void)
{
	sigset_t s, p;
	sigemptyset(&s);
	sigaddset(&s, SIGINT);
	//sigaddset(&s, SIGQUIT);
	printf("%d\n", sizeof(s));
	sigprocmask(SIG_BLOCK, &s,NULL);
	while(1)
	{
		sigpending(&p);
		printsigset(&p);
		sleep(1);
	}

	return 0;
}
