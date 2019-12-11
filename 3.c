#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
	long long v;
	long long i;


	scanf("%llu", &v);
	// FILE* file = fopen("input.txt", "r");
	// fscanf (file, "%d", &v);
	// fclose (file);

    i = v/10;
    i = i * (i + 1);
    i = 100 * i;
    i = i + 25;

    printf("%llu", i);
	return (0);
}