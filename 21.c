#include <stdio.h>
#include <stdlib.h>

int min(int x, int y)
{
	if (x < y)
		return (x);
	else
		return (y);
}

int max(int x, int y)
{
	if (x < y)
		return (y);
	else
		return (x);
}


int main()
{
	int a, b, c;
	int min_, max_;

	FILE* file = fopen("input.txt", "r");
	fscanf(file, "%d", &a);
	fscanf(file, "%d", &b);
	fscanf(file, "%d", &c);
	min_ = min(a, b);
	min_ = min(min_, c);

	max_ = max(a, b);
	max_ = max(max_, c);

	printf("%d\n", max_ - min_);
	fclose(file);
	return (0);
}