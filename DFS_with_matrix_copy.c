
#include <stdio.h>
#include <stdlib.h>


void	append(int *arr, int *i_addr, int value)
{
	arr[*i_addr] = value;
	(*i_addr)++;
}

void print_visited(int n, char *arr)
{
	int i;

	i = 1;
	while (i <= n)
	{
		printf("%d ", arr[i]);
		i++;
	}
	// printf("\n");
}

void print_order(int n, int *arr)
{
	int i;

	i = 0;
	while (i < 2 * n + 1)
	{
		printf("%d ", arr[i]);
		i++;
	}

}

void	DFS(int n, char **g, char *visited, int v)
{
	int j;

	printf("\n%d", v);
	visited[v] = 1;

	for(j = 1; j <= n; j++)
		if(!visited[j] && g[v][j] == 1)
			DFS(n, g, visited, j);
}



int main()
{
	int n, m, i, j, u, v;
	char **g;
	char buf;
	int *order;
	char *visited;


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




	visited = (char *)malloc(sizeof(char) * n + 1);
	order = (int *)malloc(sizeof(char) *  2 * n + 1);
	i = 0;
	while (i <= n)
	{
		visited[i] = 0;
		order[i] = 0;
		i++;
	}

	DFS(n, g, visited, 1);


	




//free allocated memory
	i = 1;
	while (i <= n)
	{
		free(g[i]);
		i++;
	}
	free(g);
	free(visited);
	free(order);
	return (0);
}