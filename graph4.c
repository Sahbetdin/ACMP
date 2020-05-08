//https://stepik.org/lesson/307330/step/9?unit=289418
//Список смежности -> матрица смежности

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
	int n, m, i, j, u, v, am;
	char **g;
	char buf;

	scanf("%d", &n);

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

	i = 1;
	while (i <= n)
	{
		scanf("%d", &am);
		j = 1;
		while (j <= am)
		{
			scanf("%d", &u);
			g[i][u] = 1;
			g[u][i] = 1;
			j++; //по всем связям
		}
		i++; //по всем вершинам
	}


	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			printf("%c", g[i][j] + 48);
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