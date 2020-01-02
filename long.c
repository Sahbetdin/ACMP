#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a;
	int b;

//	FILE* file = fopen("input.txt", "r");
//	fscanf(file, "%d", &a1);

	a = 2000000000;
	b = a + a;
	printf("%d\n", b);	

//	fclose(file);
	return (0);
}