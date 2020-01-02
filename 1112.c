#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n;

	FILE* file = fopen("input.txt", "r");
	fscanf(file, "%d", &n);
	
	printf("%d\n",  n / 100 + n / 10 % 10 + n % 10);

	fclose(file);
	return (0);
}