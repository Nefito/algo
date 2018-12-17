#include <stdio.h>
#include <stdlib.h>

#define SIZE 6

int main()
{
	int a[SIZE][SIZE], d[SIZE], v[SIZE];
	int temp, minindex, min;

	for (int i = 0; i < SIZE; i++)
	{
		a[i][i] = 0;
		for (int j = i + 1; j < SIZE; j++)
		{
			printf("Enter the weight for %d - %d: ", i + 1, j + 1);
			scanf("%d", &temp);
			a[i][j] = temp;
			a[j][i] = temp;
		}
	}
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			printf(" %5d ", a[i][j]);
		}
		printf("\n");
	}
	for (int i = 0; i < SIZE; i++)
	{
		d[i] = 10000;
		v[i] = 1;
	}

	d[0] = 0;
	do
	{
		minindex = 10000;
		min = 10000;
		for (int i = 0; i < SIZE; i++)
		{
			if ((v[i] == 1) && (d[i] < min))
			{
				min = d[i];
				minindex = i;
			}
		}
		if (minindex != 10000)
		{
			for (int i = 0; i < SIZE; i++)
			{
				if (a[minindex][i] > 0)
				{
					temp = min + a[minindex][i];
					if (temp < d[i])
					{
						d[i] = temp;
					}
				}
			}
			v[minindex] = 0;
		}
	}while (minindex < 10000);

	printf("\nThe smallest distance for the vertexes: \n");
	for (int i = 0; i < SIZE; i++)
	{
		printf("%d ", d[i]);
	}

	int ver[SIZE];
	int end = 4;
	ver[0] = end + 1;
	int k = 1;
	int weight = d[end];



	while (end > 0)
	{
		for (int i = 0; i < SIZE; i++)
		{
			if (a[end][i] != 0)
			{
				 temp = weight - a[end][i];
				if (temp == d[i])
				{
					weight = temp;
					end = i;
					ver[k] = i + 1;
					k++;
				}
			}
		}
	}

	printf("\nThe shortest route:\n");
	for (int i = k - 1; i >= 0; i--)
	{
		printf("%d ", ver[i]);
	}
	printf("\n");
	return 0;
}
