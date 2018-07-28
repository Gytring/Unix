#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int line = 0;
	int at_begin = 1;
	int ch;

	while((ch = getchar()) != EOF)
	{
		if(at_begin == 1)
		{
			line = line + 1;
			at_begin = 0;
			printf("%d:", line);
		}
		putchar(ch);

		if(ch == '\n')
			at_begin = 1;
	}

	exit(1);
}
