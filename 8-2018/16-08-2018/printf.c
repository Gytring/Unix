#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int c = 11;
	int d;
	d = c + --c;
	printf("%d\n", d);
	int i = 10;
	i = i-- - --i *(i = -3) * i++ + ++i;
	printf("i = %d\n", i);
	printf("%f\n", (float)(25 / 10));
	exit(0);
}
