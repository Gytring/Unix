#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int i;
	int n;
	double x;
	printf("%d\n", 0.1);
	printf("%g\n", 2);
	printf("%u\n", -37);
//	printf("%s\n", NULL);
//
	for(i = -3; i <= 3; i++)
		printf("% d\n", i);

	for(x = -3; x <= 3; x++)
		printf("% e, %+e, %e\n", x, x, x);

	printf("hello\n%n", &n);
	printf("%d\n", n);

	printf("%06d %06d\n", -37, 37);
	printf("%.6d %.6d\n", -37, 37);

	printf("%.0f %#.0f %g %#g\n", 3.0, 3.0, 3.0, 3.0);
	fprintf(stderr ,"error\n");
	return 0;
}
