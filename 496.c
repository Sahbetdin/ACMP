#include <stdio.h>
#include <stdlib.h>

int get_max3(int a, int b, int c)
{
	int max;
	if (a > b)
		max = a;
	else
		max = b;
	if (c > max)
		max = c;
	return (max);
}

int main()
{
	int i, n;
	int *a;
	int sum, x, y, z;

	FILE* file = fopen("input.txt", "r");
	fscanf(file, "%d", &n);
	a = (int *)malloc(sizeof(int) * n);
	i = -1;
	while (++i < n)
		fscanf(file, "%d", a + i);
	i = 0;
	while (i < n)
	{
		x = a[i];
??????		if (i + 1 >= n - 2)
			y = ...
		else
			y = a[i + 1];

		sum = a[i] + [i + 1] + a[i + 2];
		i++;
	}
	a_max = a[0] + a[1] + a[n - 1];
	a_max = a[0] + [1] + a[2];
	a_max = 
	
	// i = -1;
	// while (++i < n)
	// 	printf("%d ", a[i]);



	return (0);
}