#include <stdio.h>
#include <signal.h>

void do_sig(int num)
{
	printf("I an do_sig\n");
	printf("num = %d\n", num);
}

int main(void)
{
	struct sigaction act;
//act.sa_handler = do_sig;
//	act.sa_handler = SIG_DFL;
	act.sa_handler = SIG_IGN;
	sigemptyset(&act.sa_mask);
	act.sa_flags = 0;

	sigaction(SIGINT, &act, NULL);

	while(1)
	{
		printf("**********\n");
		sleep(1);
	}
	return 0;
}
