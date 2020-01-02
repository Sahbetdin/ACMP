#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i, n;
	int *a;


	FILE* file = fopen("input.txt", "r");
	fscanf(file, "%d", &n);
	printf("The next number for the number %d is %d.\nThe previous number for the number %d is %d.", n, n + 1, n, n - 1);
	

	fclose(file);
	return (0);
}

//дз
//1038, 697, 1115, 1114, 1110, 1111, 1112, 1116, 
//без циклов и условий