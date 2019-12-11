#include <stdio.h>


int main(int argc, char const *argv[])
{
	int i;

	FILE* file = fopen("input.txt", "r");
	fscanf(file, "%d", &i);
	printf("%d\n", i * (i + 1) /2);

	fclose(file);
	return 0;
}