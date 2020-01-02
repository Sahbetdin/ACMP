#include <stdio.h>
#include <stdlib.h>

int main()
{
	int h;
	int a, b;


	FILE* file = fopen("input.txt", "r");
	fscanf(file, "%d", &h);
	fscanf(file, "%d", &a);
	fscanf(file, "%d", &b);
	fclose(file);

	printf("%d\n", (h - a) / (a - b) + 1);
	return (0);
}