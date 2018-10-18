#include <stdio.h>
//十进制数，站在用户的角度，原码
//二进制、八进制、十六进制，站在计算机的角度补码
//原码 --> 补码  和 补码 --> 原码 过程一样
int main(void)
{
	char a = 0x85;
	printf("%d\n", a);
	int b = -666;
	printf("%x\n", b);
	return 0;
}
