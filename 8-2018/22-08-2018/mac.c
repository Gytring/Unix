#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE*	netinfo = popen("/sbin/ifconfig", "r");

	if(!netinfo)
	{
		puts("error while open pip");
		exit(1);
	}

	char str[200];

	while(fgets(str, 199, netinfo) != NULL)
	{
		printf("%s", str);
	}
	pclose(netinfo);

	system("/sbin/ifconfig");
	exit(0);
}
