#include <stdio.h>
#include <stdlib.h>

int min(int x, int y)
{
	if (x < y)
		return (x);
	else
		return (y);
}

int max(int x, int y)
{
	if (x < y)
		return (y);
	else
		return (x);
}

void swap(int *a, int *b)
{
	int c;

	c = *a;
	*a = *b;
	*b = c;
}

int main()
{
	int a[3];
	int b[3];
	int max_a, max_b;
	int min_a, min_b;
	int mid_a, mid_b;

	FILE* file = fopen("input.txt", "r");
	fscanf(file, "%d", &a[0]);
	fscanf(file, "%d", &a[1]);
	fscanf(file, "%d", &a[2]);
	fscanf(file, "%d", &b[0]);
	fscanf(file, "%d", &b[1]);
	fscanf(file, "%d", &b[2]);
	fclose(file);

	min_a = min(min(a[0], a[1]), a[2]);
	min_b = min(min(b[0], b[1]), b[2]);

	max_a = max(max(a[0], a[1]), a[2]);
	max_b = max(max(b[0], b[1]), b[2]);

	mid_a = a[0] + a[1] + a[2] - min_a - max_a;
	mid_b = b[0] + b[1] + b[2] - min_b - max_b;
	printf("%d\n", min_a * min_b + max_a * max_b + mid_a * mid_b);

	// if (a[0] > a[1])
	// 	swap(&a[0], &a[1]);
	// if (a[1] > a[2])
	// 	swap(&a[1], &a[2]);
	// if (a[0] > a[1])
	// 	swap(&a[0], &a[1]);

	// if (b[0] > b[1])
	// 	swap(&b[0], &b[1]);
	// if (b[1] > b[2])
	// 	swap(&b[1], &b[2]);
	// if (b[0] > b[1])
	// 	swap(&b[0], &b[1]);
	// printf("%d\n", a[0] * b[0] + a[1] * b[1] + a[2] * b[2]);
	return (0);
}