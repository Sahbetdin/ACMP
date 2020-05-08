
#include <stdio.h>
#include <stdlib.h>
//this is the same as DFS_site.c
//3-4th April 2020


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


// void	DFS(int n, char **g, char *visited, int *order, int *i_addr, int v)
// {
// 	int j;

// 	//we say that v is visited and put it to the visited list
// 	visited[v] = 1;
// 	order[*i_addr] = v;
// 	(*i_addr)++;
// 	print_visited(n, visited);
// 	printf("visited %d\n", v);

// 	j = 1;
// 	while (j <= n)
// 	{
// 		if (visited[j] == 1 && j == n)
// 		{
// 			printf(HERE)
// 			printf("v = %d; j == n\n", v);
// 			order[*i_addr] = j;
// 			print_order(n, order);
// 			visited[j] = 2;
// 			(*i_addr)++;
// 		}
// 		else if (g[v][j] == 0)
// 		{
// 			printf("v = %d; increment j for g[] = 0. Now j = %d\n", v, j);
// 			j++;
// 		}
// 		else if (g[v][j] == 1 && visited[j] == 0)
// 		{
// 			printf("v = %d; start DFS at v = %d\n", v, j);
// 			DFS(n, g, visited, order, i_addr, j);

// 		}
// 		else if (g[v][j] == 1 && visited[j] == 1 && j < n)
// 		{
// 			printf("v = %d; increment j for g[] = 1\n", v);
// 			j++;
// 		}
// 	}
// }

int k;

void	DFS(int n, char **g, char *visited, int *order, int v)
{
	int j;
	int row;

	//printf("Now in v = %d\n", v);	
	order[k] = v;
	k++;
	visited[v] = 1;
	j = 1;
	while (j <= n)
	{
		if (g[v][j] == 1 && visited[j] == 0)
		{
			DFS(n, g, visited, order, j);
			// printf("Fin j = %d\n", j);	
			order[k] = v;
			k++;

		}

		j++;
	}


	
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



	scanf("%d", &v);
	k = 0;
	DFS(n, g, visited, order, v);
	printf("~~~~~~~~\n");
	print_order(n, order);





	




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