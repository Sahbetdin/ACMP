#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a, b, c;

	FILE* file = fopen("input.txt", "r");
	fscanf(file, "%d", &a);
	fscanf(file, "%d", &b);
	fscanf(file, "%d", &c);

	if (a + b < c)
	{
		printf("NO\n");
		return (0);
	}
	if (a + c < b)
	{
		printf("NO\n");
		return (0);
	}
	if (b + c < a)
	{
		printf("NO\n");
		return (0);
	}
	printf("YES\n");
	return (0);
}