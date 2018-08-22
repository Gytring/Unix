#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <math.h>

int main()
{
	char str[80];
	char *gl;
	int cx = 9999;

	sprintf(str, "Pi 的值 = %f", M_PI);
	puts(str);
	sprintf(gl, "hello world %d", cx);
	puts(gl);
   
   return(0);
}
