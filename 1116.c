#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a1;
	int b1;
	int c1;
	int a2;
	int b2;
	int c2;

	FILE* file = fopen("input.txt", "r");
	fscanf(file, "%d", &a1);
	fscanf(file, "%d", &b1);
	fscanf(file, "%d", &c1);
	fscanf(file, "%d", &a2);
	fscanf(file, "%d", &b2);
	fscanf(file, "%d", &c2);
	
	printf("%d\n",  (a2 - a1) * 3600 + (b2 - b1) * 60 + (c2 - c1));

	fclose(file);
	return (0);
}