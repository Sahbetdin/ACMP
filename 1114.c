#include <stdio.h>
#include <stdlib.h>

int main()
{
	int v, t;

	FILE* file = fopen("input.txt", "r");
	fscanf(file, "%d", &v);
	fscanf(file, "%d", &t);
	
	printf("%d\n", ((v * t) % 109 + 109) % 109 + 1);

	fclose(file);
	return (0);
}