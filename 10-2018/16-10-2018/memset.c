#include <stdio.h>
#include <string.h>

int main(void)
{
	//char *p = "old solder never die!!";
	char *p;
	p = (char *)malloc(10 * sizeof(char));
	memset(p, 'y', 10);
	printf("%s\n", p);
	return 0;
}
