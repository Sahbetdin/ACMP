#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i, n;
	int *a;


	FILE* file = fopen("input.txt", "r");
	fscanf(file, "%d", &n);
	
	printf("%d %d %d", n / 6, 2 * n / 3 , n / 6 );
	fclose(file);
	return (0);
}