 /*************************************************************************
	> File Name: quicort.c
	> Author: free
	> Mail: fancanglang@foxmail.com 
	> Created Time: Fri 29 Jun 2018 08:58:57 AM CST
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <errno.h>
#define  SIZE 1000
#define  LENGTH 1000

void swap(int *x, int *y)
{
	int tmp;
	tmp = *x;
	*x = *y;
	*y = tmp;
}

void sort(int *array, int length, int left, int right)
{
	if(left < right)
	{
		int i, j;
		i = left + 1;
		j = right;
		while(i < j)
		{
			if(array[i] > array[left])
			{
				swap(&array[i], &array[j]);
				j--;
			}
			else
				i++;
		}
	

		if(array[i] >= array[left])
			i--;

		swap(&array[i], &array[left]);

		sort(array, SIZE, left, i);
		sort(array, SIZE, j, right);
	}
}

int main(void)
{
	int fd1, fd2, i;
	int array[SIZE];

	umask(0);
	fd1 = open("random", O_RDWR);
	fd2 = open("sort", O_RDWR | O_CREAT, 0644);

	if(fd1 < 0)
	{
		perror("open random");
		exit(1);
	}
	if(fd2 < 0)
	{
		perror("open sort");
		exit(1);
	}

	dup2(fd1, STDIN_FILENO);
	dup2(fd2, STDOUT_FILENO);
	close(fd1);
	close(fd2);


	for(i = 0; i < SIZE; i++)
	{
		scanf("%d", &array[i]);
	}

	sort(array, SIZE, 0, SIZE - 1);

	for(i = 0;i < SIZE; i++)
	{
		printf("%d\n", array[i]);
	}

	return 0;
}
