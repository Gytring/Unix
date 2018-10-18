#include "stdio.h"

char *get_string_1()
{
    char p[] = "hello world!";
	printf("1 %s\n", p);
    return p;
}

char *get_string_2()
{
    char *p = "hello world!";
    return p;
}

int main()
{
    char *p;
//    p = get_string_1();
//    printf("get_string_1: %s\n", get_string_1());
//    p = get_string_2();
//    printf("get_string_2: %s\n", p);
	char b[10] = {
		'1', '2', '3'
	};
	char a[10] = "123456789asd";
	printf("%s\n", a);
	printf("%s\n", b);
    return 0;
}
