//8 apr 2020
//Дороги
//https://acmp.ru/index.asp?main=task&id_task=15

#include <stdio.h>
#include <stdlib.h>

int sum_row(int n, char *row)
{
	int res, i;

	res = 0;
	i = 1;
	while (i <= n)
	{
		if (row[i] == '1')
			res++;
		i++;
	}
	return (res);
}

int main()
{
	int n, i, j;
	int **g;


	scanf("%d", &n);

	g = (int **)malloc(sizeof(int *) * n);
	i = 0;
	while (i < n)
	{
		g[i] = (int *)malloc(sizeof(int) * n);
		i++;
	}

	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < n)
		{
			scanf("%d", g[i] + j);
			j++;
		}
		i++;
	}

	int s;
	s = 0;
	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < n)
		{
			s += g[i][j];
//			printf("%d ", g[i][j]);
			j++;
		}
		// printf("\n");
		i++;
	}
	printf("%d\n", s / 2);


//free allocated memory
	i = 0;
	while (i < n)
	{
		free(g[i]);
		i++;
	}
	free(g);
	return (0);
}
