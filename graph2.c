//https://stepik.org/lesson/307330/step/7?unit=289418
//Список ребер -> список смежности

#include <stdio.h>
#include <stdlib.h>


int sum_row_int(int n, char *row)
{
	int res, i;

	res = 0;
	i = 1;
	while (i <= n)
	{
		if (row[i] == 1)
			res++;
		i++;
	}
	return (res);
}

int main()
{
	int n, m, i, j, u, v;
	char **g;
	char buf;

	scanf("%d %d", &n, &m);

	g = (char **)malloc(sizeof(char *) * n + 1);
	i = 0;
	while (i <= n)
	{
		g[i] = (char *)malloc(sizeof(char) * n + 1);
		i++;
	}

	i = 0;
	while (i <= n)
	{
		j = 0;
		while (j <= n)
		{
			g[i][j] = 0;
			j++;
		}
		i++;
	}

	i = 0;
	while (i < m)
	{
		scanf("%d %d", &u, &v);
		g[u][v] = 1;
		g[v][u] = 1;
		i++;
	}


	for (i = 1; i <= n; i++) {
		printf("%d ", sum_row_int(n, g[i]));
		for (j = 1; j <= n; j++) {
			if (g[i][j] == 1)
				printf("%d ", j);
		}
		printf("\n");
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