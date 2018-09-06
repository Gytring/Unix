#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void swap(int *x, int *y)
{
	int tmp;
	tmp = *x;
	*x  = *y;
	*y  = tmp;
}

void quick_sort(int *arr, int l, int r)
{
	if(l < r)
	{
		int i, j;
		i = l + 1;
		j = r;
		while(i < j)
		{
			if(arr[i] > arr[l])
			{
				swap(&arr[i], &arr[j]);
				j--;
			}
			else
				i++;
		}

		if(arr[i] >= arr[l])
			i--;
		swap(&arr[l], &arr[i]);
		quick_sort(arr, l, i);
		quick_sort(arr, j, r);
	}
}

void gen_arr(int arr[], int len, int max)
{
	srand((int)time(0));

	int i;
	for(i = 0; i < len; i++)
	{
		arr[i] = (int)(rand() % max);
	}
	return;
}

void display(int *arr, int len)
{
	int i;
	for(i = 0; i < len; i++)
	{
		printf("%d\t", arr[i]);
		if((i + 1) % 10 == 0 )
			printf("\n");
	}
	printf("\n");
}

int main(int argc, char *argv[])
{
	int len, maxnum;
	if(argc != 3)
	{
		printf("Usage: ./a.out length maxnum\n");
		exit(1);
	}
	len = atoi(argv[1]);
	if(len <= 0)
	{
		printf("length error");
		exit(1);
	}
	maxnum = atoi(argv[2]);

	int arr[len];
	gen_arr(arr, len, maxnum);

	printf("排序前的数组: \n");
	display(arr, len);

	printf("排序后的数组: \n");
	quick_sort(arr, 0, len);
	display(arr, len);

	exit(0);
}
