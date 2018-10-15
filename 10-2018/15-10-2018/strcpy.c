#include <stdio.h>
#include <string.h>
#include <assert.h>

char *cpy(char *dest, const char *src);
char *str_cpy(char *dest, const char *src);

int main(void)
{
	char *str = "This is the strcpy finish";
	printf("%s\n", str);
	char dest1[10], dest3[10], dest2[10];

	strcpy(dest1, str);
	printf("strcpy: %s\n", dest1);
	str_cpy(dest3, dest1);
	printf("str_cpy: %s\n", dest3);
	cpy(dest2, dest3);
	printf("cpy: %s\n", dest2);

	return 0;
}

char *cpy(char *dest, const char *src)
{
	if(dest == NULL && src == NULL)
		return NULL;

	char *add = dest;

	int i;
	for(i = 0; src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';
	return add;
}

char *str_cpy(char *dest, const char *src)
{
	assert((dest != NULL) && (src != NULL));

	char *add = dest;
	while((*dest++ = *src++) != '\0');

	return add;
}
