#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i, n;
	int *a;


	FILE* file = fopen("input.txt", "r");
	fscanf(file, "%d", &n);
	printf("%d\n", n);
	

	fclose(file);
	return (0);
}