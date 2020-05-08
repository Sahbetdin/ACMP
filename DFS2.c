//https://stepik.org/lesson/307331/step/2?unit=289419
//steps in graphs during DFS

#include <stdio.h>
#include <stdlib.h>
//3rd of April 2020
//find components

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
void print_adj_list(int n, int *adj, int *next)
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

void	print_components(int n, int *comp)
{
	int i;

	i = 1;
	while (i <= n)
	{
		printf("%d ", comp[i]);
		i++;
	}
	printf("\n");
}

void	DFS(int *adj, int *next, int n, int m, int v, int *comp, int c)
{
	int j, row, u;

	adj[v] = 1;
	comp[v] = c;
	// printf(" %d ", v);

	row = next[v];
	while (row != 0)
	{
		u = adj[row];
		next[v] = next[row];
		if (adj[u] == 0)
		{
			DFS(adj, next, n, m, u, comp, c);
			// printf(" %d ", v);
		}
		row = next[row];
	}
}

int main()
{
	int n, m, N, u, v, i, j, k;

	int *adj;
	int *next;
	int *comp;
	int count;

	scanf("%d %d", &n, &m);
	N = n + 2 * m;
	// printf("N = %d\n", N);

	adj = (int *)malloc(sizeof(int) * N + 1);
	next = (int *)malloc(sizeof(int) * N + 1);
	comp = (int *)malloc(sizeof(int) * n + 1);

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
	// print_adj_next(N, adj, next);


//components of adjacency
	i = -1;
	while (++i <= n)
		comp[i] = 0;

	count = 1;
	j = 1;
	while (j <= n)
	{
		DFS(adj, next, n, m, j, comp, count);
		while (comp[j] != 0)
			j++;
		// printf("j = %d\n", j);
		count++;
	}


	printf("%d\n", count - 1);
	print_components(n, comp); //print components

	free(adj);
	free(next);
	free(comp);
	return (0);
}

/*
2 1
1 2
*/

/*
11 13
1 2
1 3
2 3
2 4
3 4
3 5
2 6
5 6
5 7
8 9
9 10
8 10
10 11
1
*/