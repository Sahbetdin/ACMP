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
	int n, i, j;
	int min_;
	int max_;

	FILE* file = fopen("input.txt", "r");
	fscanf(file, "%d", &n);
	fscanf(file, "%d", &i);
	fscanf(file, "%d", &j);
	fclose(file);

	min_ = min(i, j);
	max_ = max(i, j);
	printf("%d\n", min(max_ - min_ - 1, n - max_ + min_ - 1));
	
	return (0);
}