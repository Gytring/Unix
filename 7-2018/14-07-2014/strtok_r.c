#include <stdio.h>
#include <string.h>

int main(void)
{
	char buf[] = "hello world itcast gcc";
	char *save = buf, *p;

	while((p = strtok_r(save, " ", &save)) != NULL)
		printf("%s\n", p);

	return 0;
}
