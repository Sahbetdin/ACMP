#include <stdio.h>
#include <stdlib.h>

int max(int x, int y)
{
	if (x < y)
		return (y);
	else
		return (x);
}

int main()
{
	int h;
	int a, b;


	FILE* file = fopen("input.txt", "r");
	fscanf(file, "%d", &h);
	fscanf(file, "%d", &a);
	fscanf(file, "%d", &b);
	fclose(file);

	printf("%d\n", max(1, 1 + (h - b - 1)/(a - b)));
	return (0);
}