#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	char s[] = "hello world";
//	char s[] = "hello\0 world";
//	char p[2];
//	char q[9];
//	strcpy(p, s);
//	strncpy(q, s, 9);
//	printf("%s\n", p);
//	printf("%s\n", q);
//	printf("strlen: %d\n", strlen(q));
	char *p;
//	p = strchr(s, 'r');
	p = strstr(s, "wo");
	printf("p: %s\n", p);
	return(0);
}
