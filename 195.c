#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a, b, c;

	FILE* file = fopen("input.txt", "r");
	fscanf(file, "%d", &a);
	fscanf(file, "%d", &b);
	fscanf(file, "%d", &c);
	
	printf("%d\n", 2 * a * b * c);

	fclose(file);
	return (0);
}