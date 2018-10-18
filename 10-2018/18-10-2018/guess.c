#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	int a[4], b[4];
	int i, flag = 0;
	srand(time(NULL));

	for(i = 0; i < 4; i++)
	{
		a[i] = rand() % 10;
	}
	while(!a[0])
	{
		a[0] = rand() % 10;
	}

	while(1)
	{
		for(i = 0; i < 4; i++)
		{
			printf("请输入第%d数: ", i + 1);
			scanf("%d", &b[i]);
			if(b[i] < 0 || b[i] > 9)
			{
				fprintf(stderr, "error number: %d\n", b[i]);
				return(1);
			}
		}

		for(i = 0; i < 4; i++)
		{
			printf("第%d个数: ", i+1);
			if(a[i] > b[i])
			{
				printf("小\n");
			}
			else if(a[i] < b[i])
			{
				printf("大\n");
			}
			else
			{
				printf("%d\n", b[i]);
				flag++;
			}
		}

		if(flag == 4)
		{
			printf("恭喜你猜对了!!!\n");
			break;
		}
		flag = 0;
	}

	printf("数为: ");
	for(i = 0; i < 4; i++)
	{
		printf("%d", a[i]);
	}
	fputs("\n", stdout);
	return 0;
}
