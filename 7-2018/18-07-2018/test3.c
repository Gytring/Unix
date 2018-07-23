#include <stdio.h>
int main(void)
{
	char c;

	char *p;
	p = NULL;
	printf("Location 0 contains %d\n", *p);
	printf("%s\t%d", __FILE__, __LINE__);
	while((c = getchar()) != EOF)
		putchar(c);

	return 0;
}
