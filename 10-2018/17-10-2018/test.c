#include <stdio.h>
#include <string.h>

int main(void)
{
//	char *a;
	char *c;

	c = (char *)malloc(10 * sizeof(char));
//	printf("Please input a: ");
//	scanf("%s", a);
	printf("Please input c: ");
	fgets(c, sizeof(c), stdin);
	printf("sizeof(c)%d", sizeof(c));
	
//	printf("a-->%p\n", &a);
	printf("c-->%c\n", &c);
//	printf("a: %s\n", a);
	printf("c: %s\n", c);

	return 0;
}
