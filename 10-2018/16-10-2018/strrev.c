#include <stdio.h>
#include <string.h>

char *rev(const char *p);
char *revs(char *p);

int main(int argc, char *argv[])
{
	char p[100], *q, *ms;
	printf("请输入字符串:         ");
	//scanf("%s", p);
	fgets(p, 100, stdin);

	q = rev(p);
	ms = revs(p);
	printf("反转后的字符串为:rev  %s\n", q);
	printf("反转后的字符串为:revs %s\n", ms);
	return 0;
}


char *rev(const char *p)
{
	int i, len = strlen(p);
	char str[len];
	for(i = 0; i < len; i++)
	{
		str[i] = p[len - i - 1];
	}
	str[i] = '\0';
	return str;
}

char *revs(char *p)
{
	char *str = p;
	char *src = p;
	char ch;
	while(*str++)
		;
	str--;	//回到字符串最后一个字符
	str--;  //回到'/0' 之前

	while(src < str)
	{
		ch = *src;
		*src++ = *str;
		*str-- = ch;
	}
	return(p);
}

char *revstr(char *str)
{
	int		len = strlen(str);
    char    *start = str;
    char    *end = str + len - 1;
    char    ch;
    if (str != NULL)
    {
        while (start < end)
        {
            ch = *start;
            *start++ = *end;
            *end-- = ch;
        }
    }
    return str;
}
