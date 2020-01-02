#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n, k;

	FILE* file = fopen("input.txt", "r");
	fscanf(file, "%d", &n);
	fscanf(file, "%d", &k);
	
	printf("%d %d %d\n", k / n, k % n , (n - k % n) % n);

	fclose(file);
	return (0);
}