#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>

#define DIRMODE 0775

#define PATHSIZE 255
int main(void)
{
	char path_buf[PATHSIZE];
	int flag;

	getcwd(path_buf, PATHSIZE);

	printf("%s\n", path_buf);
	flag = mkdir("testTTAT", DIRMODE);
	if(flag < 0)
	{
		perror("mkdir");
		exit(1);
	}
	return 0;
}
