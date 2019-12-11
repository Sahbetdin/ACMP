#include <stdio.h>


int main(int argc, char const *argv[])
{
	int i, j;

	FILE* file = fopen("input.txt", "r");
	fscanf(file, "%d", &i);
	fscanf(file, "%d", &j);
	printf("%d\n", i + j);

	fclose(file);
	return 0;
}