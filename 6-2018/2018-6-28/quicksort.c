 /*************************************************************************
	> File Name: quicksort.c
	> Author: free
	> Mail: fancanglang@foxmail.com 
	> Created Time: Thu 28 Jun 2018 11:41:15 AM CST
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>

void swap(int *x, int *y)
{
	int tmp;
	tmp = *x;
	*x = *y;
	*y = tmp;
}

void sort(int *arr, int len, int left, int right)
{
	if(left < right)
	{
		int i, j;
		i = left + 1;
		j = right;
		while(i < j)
		{
			if(arr[i] > arr[left])
			{
				swap(&arr[i], &arr[j]);
				j--;
			}
			else i++;
		}

		if(arr[i] >= arr[left])
			i--;

		swap(&arr[i], &arr[left]);

		sort(arr, len, left, i);
		sort(arr, len, j, right);
	}
}



int main(void)
{
	int arr[1000];
	int fd, fd2;
	int i;

	fd = open("random", O_RDWR);
	if(fd < 0)
	{
		perror("open");
		exit(1);
	}
	umask(0);
	fd2 = open("result", O_CREAT | O_RDWR, 0644);
	if(fd2 < 0)
	{
		perror("open");
		exit(1);
	}

	dup2(fd, STDIN_FILENO);
	dup2(fd2, STDOUT_FILENO);

	for(i=0;i < 1000; i++)
	{
		scanf("%d", &arr[i]);
	}

	sort(arr, 1000, 0, 999);

	for(i = 0; i < 1000; i++)
	{
		printf("%d\n", arr[i]);
	}
	close(fd);
	close(fd2);

	return 0;
}
