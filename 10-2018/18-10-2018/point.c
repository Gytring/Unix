#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int a[4] = {2, 4, 5, 9};
	int *p;
	p = a;
	*p = *p++;
	printf("%d %d %d\n", *p, *p + 6, *(p + 1));
	return 0;
}
