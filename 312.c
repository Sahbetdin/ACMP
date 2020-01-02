#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a1, a2, n;
	int d;

	FILE* file = fopen("input.txt", "r");
	fscanf(file, "%d", &a1);
	fscanf(file, "%d", &a2);
	fscanf(file, "%d", &n);
	d = a2 - a1;
	printf("%d\n", a1 + d * (n - 1));

	fclose(file);
	return (0);
}