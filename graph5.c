//https://stepik.org/lesson/307330/step/10?unit=289418
//Матрица смежности -> список ребер
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
	int n, i, j, s;
	char **g;
	char buf;

	scanf("%d", &n);

	g = (char **)malloc(sizeof(char *) * n + 1);
	i = 1;
	while (i <= n)
	{
		g[i] = (char *)malloc(sizeof(char) * n + 1);
		i++;
	}

	i = 1;
	while (i <= n)
	{
		j = 0;
		while (j <= n)
		{
			scanf("%c", g[i] + j);
			j++;
		}
		i++;
	}

	s = 0;
	for (i = 1; i <= n; i++) {
		for (j = i + 1; j <= n; j++) {
			if (g[i][j] == '1')
				s++;
		}
	}

	printf("%d\n", s);
	for (i = 1; i <= n; i++) {
		for (j = i + 1; j <= n; j++) {
			if (g[i][j] == '1')
				printf("%d %d\n", i, j);
		}
	}

//free allocated memory
	i = 1;
	while (i <= n)
	{
		free(g[i]);
		i++;
	}
	free(g);
	return (0);
}
