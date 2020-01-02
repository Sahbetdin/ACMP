#include <stdio.h>

int main()
{
	int L, W, H;

	FILE* file = fopen("input.txt", "r");
	fscanf(file, "%d", &L);
	fscanf(file, "%d", &W);
	fscanf(file, "%d", &H);

	printf("%d\n", (((2 * L + 2 * W) * H) - 1) / 16 + 1);

	fclose(file);
	return (0);
}