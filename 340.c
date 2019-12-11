#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int main()
{
	int i, n, tmp;
	int *a;
	int *b;


	a = (int *)malloc(sizeof(int) * 3);
	b = (int *)malloc(sizeof(int) * 3);
	
	FILE* file = fopen("input.txt", "r");
	i = -1;
	while (++i < 3)
		fscanf(file, "%d", &a[i]);
	i = -1;
	while (++i < 3)
		fscanf(file, "%d", &b[i]);
	if (a[0] < a[1])
		swap(a, a + 1);
	if (a[1] < a[2])
		swap(a + 1, a + 2);
	if (a[0] < a[1])
		swap(a, a + 1);

	// i = -1;
	// while (++i < 3)
	// 	printf("%d ", a[i]);

	if (b[0] < b[1])
		swap(b, b + 1);
	if (b[1] < b[2])
		swap(b + 1, b + 2);
	if (b[0] < b[1])
		swap(b, b + 1);

	if (a[0] == b[0] && a[1] == b[1] && a[2] == b[2])
		printf("Boxes are equal\n");
	else if (a[0] >= b[0] && a[1] >= b[1] && a[2] >= b[2])
		printf("The first box is larger than the second one\n");
	else if (a[0] <= b[0] && a[1] <= b[1] && a[2] <= b[2])
		printf("The first box is smaller than the second one\n");
	else
		printf("Boxes are incomparable\n");
	return (0);
}