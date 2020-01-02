#include <stdio.h>
#include <stdlib.h>


int main()
{
	int i, j, n;
	double a, b, c, d, x;
	double sol[202];
	double v;

	FILE* file = fopen("input.txt", "r");
	fscanf(file, "%lf", &a);
	fscanf(file, "%lf", &b);
	fscanf(file, "%lf", &c);
	fscanf(file, "%lf", &d);
	x = -100;
	j = 0;
	while (x <= 100)
	{
		v = a * x * x * x + b * x * x + c * x + d;
		if (v == 0)
		{
			sol[j] = x;
			j++;
			sol[j] = 2000000000;
		}
		x++;
	}
	j = 0;
	while (sol[j] != 2000000000)
	{
		if (sol[j] == 2000000001)
			continue;
		i = j + 1;
		while (sol[i] != 2000000000)
		{
			if (sol[i] == sol[j])
			{
				sol[i] = 2000000001;
			}
			i++;
		}
		j++;
	}
	j = 0;
	while (sol[j] != 2000000000)
	{
		if (sol[j] == 2000000001)
			continue;		
		printf("%d ", (int)sol[j]);
		j++;
	}


	return (0);
}