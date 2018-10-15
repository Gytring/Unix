#include <stdio.h>
#include <string.h>

int len(const char *p);
int main(void)
{
	char s[] = "Go spurs go!";
	int len_def, len_std;

	len_def = len(s);
	len_std = strlen(s);

	printf("len_def: %d\n", len_def);
	printf("len_std: %d\n", len_std);

	return(0);
}
//标准库的实现
int str_len(const char *p)
{
	const char *str = p;

	while(*str++);

	return (str - p - 1);
}

//我的实现
int len(const char *p)
{
	const char *str = p;
	int len = 0;
	while(str[len] != '\0')
		len++;
	return len;
}
