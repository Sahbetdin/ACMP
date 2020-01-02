#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i, n, m;
	int *a;


	FILE* file = fopen("input.txt", "r");
	fscanf(file, "%d", &n);
	fscanf(file, "%d", &m);
	printf("%d %d",  m - 1, n - 1);
	
	return (0);
}