
#include <stdio.h>
#include <stdlib.h>


// void	dfs(int n, char **gr, char *visited, int v) {
// 	int i;

// 	visited[v] = 1;
// 	for (i = 1; i <= n; i++)
// 	{
// 		if(gr[v][i] && !visited[i])
// 		{
// 			printf(" %d -> %d ", v, i);
// 			dfs(n, gr, visited, i);
// 		}
// 	}
// 	printf("finished %d\n", v);
// }

//Промежуточный этап
// void	dfs(int n, char **gr, char *visited, int v) {
// 	int i;

// 	printf("ST: %d \n", v);

// 	visited[v] = 1;
// 	for (i = 1; i <= n; i++)
// 	{
// 		if(gr[v][i] && !visited[i])
// 		{
// 			// printf(" %d -> %d \n", v, i);
// 			dfs(n, gr, visited, i);
// 			printf("FIN %d \n", v);

// 		}
// 		// else
// 		// 	printf("fin: %d ", i);
// 	}
// 	// printf("fin: %d ~~\n", v);

// }

int *order;
int k;

void	dfs(int n, char **gr, char *visited, int v) {
	int i;

	// printf(" %d ", v);
	order[k] = v;
	k++;

	visited[v] = 1;
	for (i = 1; i <= n; i++)
	{
		if(gr[v][i] && !visited[i])
		{
			// printf(" %d -> %d \n", v, i);
			dfs(n, gr, visited, i);
			// printf(" %d ", v);
			order[k] = v;
			k++;
		}
	}
}



int		main() {

	int i, j, count = 0;
	int n, m, u, v;
	char **gr, *visited;
	k = 0;

	scanf("%d %d", &n, &m);
	gr = (char **)malloc(sizeof(char *) * n + 1);
	visited = (char *)malloc(sizeof(char) * n + 1);
	order = (int *)malloc(sizeof(int) * 2 * n + 1);

	i = 0;
	while (i <= 2 * n)
	{
		order[i] = 0;
		i++;
	}

	i = 0;
	while (i <= n)
	{
		gr[i] = (char *)malloc(sizeof(char) * n + 1);
		i++;
	}

	i = 0;
	while (i <= n)
	{
		visited[i] = 0;
		j = 0;
		while (j <= n)
		{
			gr[i][j] = 0;
			j++;
		}
		i++;
	}

	i = 0;
	while (i < m)
	{
		scanf("%d %d", &u, &v);
		gr[u][v] = 1;
		gr[v][u] = 1;
		i++;
	}


	scanf("%d", &v);

	dfs(n, gr, visited, v);
	i = 0;
	printf("%d\n", k);

	while (i < k)
	{
		printf("%d ", order[i]);
		i++;
	}

	return (0);
}
