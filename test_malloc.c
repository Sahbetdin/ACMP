#include <stdio.h>
#include <stdlib.h>


int main()
{
	int *x;

	x = (int *)malloc(sizeof(int) * 0);
	x[0] = 4;
	x[1] = 43;
	printf("%d\n", x[1]);

	free(x);
	return 0;
}