#include <stdio.h>
#include <stdlib.h>
//5rd of April 2020
//https://stepik.org/lesson/307331/step/5?unit=289419
//прямые и обратные ребра
//показать кол-во обратных ребер

void	print_adj_next(int N, int *adj, int *next)
{
	int k;

	// print lists adj, next
	k = 1;
	while (k <= N)
	{
		printf("adj[%d] = %d, next[%d] = %d \n", k, adj[k], k, next[k]);
		k++;
	}
}

//print adjacency list for all vertice
void	print_adj_list(int n, int *adj, int *next)
{
	int curr_row;
	int i;

	i = 1;

	while (i <= n)
	{
		printf("%d : ", i);
		curr_row = next[i];
		while (curr_row != 0)
		{
			printf("%d -> ", adj[curr_row]);
			curr_row = next[curr_row];
		}
		printf("NULL\n");
		i++;
	}
}

void	DFS(int *adj, int *next, int n, int m, int *list, int *i_addr, int v)
{
	int j, row, u;

	adj[v] = 1;

	// list[*i_addr] = v;
	// (*i_addr)++;

	// printf(" %d ", v);

	row = next[v];
	while (row != 0)
	{
		u = adj[row];
		next[v] = next[row];
		if (adj[u] == 0)
		{
			DFS(adj, next, n, m, list, i_addr, u);
			// printf(" %d ", v);

			// list[*i_addr] = v;
			// (*i_addr)++;
		}
		row = next[row];
	}
}

int main()
{
	int n, m, N, u, v, i, k;

	int *adj;
	int *next;

	scanf("%d %d", &n, &m);
	N = n + 2 * m;

	adj = (int *)malloc(sizeof(int) * N + 1);
	next = (int *)malloc(sizeof(int) * N + 1);

	i = 0;
	while (i <= N)
	{
		adj[i] = 0;
		next[i] = 0;
		i++;
	}

	i = n + 1;
	k = 1;
	while (k <= m)
	{
		scanf("%d %d", &u, &v);
		// printf("u = %d, v = %d\n", u, v);
		adj[i] = v;
		adj[i + 1] = u;
		
		next[i] = next[u];	
		next[i + 1] = next[v];
	
		next[u] = i;
		next[v] = i + 1;

		i = i + 2;
		k++;
	}


	int *list;
	list = (int *)malloc(sizeof(int) * 2 * n + 1);
	// scanf("%d", &v); //start DFS from v vertex
	i = 0;
	v = 1;
	// print_adj_list(n, adj, next);
	// print_adj_next(N, adj, next);
	DFS(adj, next, n, m, list, &i, v);
	// print_adj_next(N, adj, next);
	// print_adj_list(n, adj, next);


//	k = 0;
	// while (k < i)
	// {
	// 	printf("%d ", list[k]);
	// 	k++;
	// }

	free(adj);
	free(next);
	free(list);
	return (0);
}