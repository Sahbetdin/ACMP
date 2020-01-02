#include <stdio.h>

int main()
{
	int n;

	FILE* file = fopen("input.txt", "r");
	fscanf(file, "%d", &n);
	printf("%d\n", n + 1);

	fclose(file);
	return (0);
}