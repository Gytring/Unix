#include <stdio.h>
#include <string.h>

int main(void)
{
	char buf[] = "asdf@gccfree@spelld";
	char *p = strtok(buf, "@");
	while(p)
	{
		printf("%s\n", p);
		p = strtok(NULL, "@");
	}

	return(0);
}
