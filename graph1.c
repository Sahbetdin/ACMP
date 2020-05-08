//https://stepik.org/lesson/307330/step/6?unit=289418
//Матрица смежности -> список смежности
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

	for (i = 1; i <= n; i++) {
		printf("%d ", sum_row(n, g[i]));
		for (j = 1; j <= n; j++) {
			if (g[i][j] == '1')
				printf("%d ", j);
		}
		printf("\n");
	}


/*
	i = 0;
	while (i < n)
	{
		j = 0;
		while (j <= n)
		{
			if (g[i][j] == '0')
				printf("NO ");
			else if (g[i][j] == '1')
				printf("YES ");
			else 
				printf(" K\n");
			j++;
		}
		i++;
	}
	*/	

/*
	i = 1;
	while (i <= n)
	{
		j = 1;
		while (j <= n)
		{
			printf("%d \n", g[i][j]);
			j++;
		}
		printf("~~~~~~\n");
		i++;
	}
*/


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
