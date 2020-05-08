//https://stepik.org/lesson/307331/step/9?unit=289419
//8th of April 2020
//fund CYCLES in graph -> YES, else NO

#include <stdio.h>
#include <stdlib.h>

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

void	print_parent(int n, int *par)
{
	int i;

	i = 1;
	printf("PAR: ");
	while (i <= n)
	{
		printf("%d ", par[i]);
		i++;
	}
	printf("\n");
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



void	DFS(int *adj, int *next, int n, int m, int v, int *par)
{
	int j, row, u;

	adj[v] = 1;

	// printf(" %d ", v);
	row = next[v];
/*walk through neighbours of v*/
	while (row != 0)
	{
		u = adj[row];
		next[v] = next[row];
		if (adj[u] == 0)
		// if (if_visited(n, adj, u) == 0)
		{
			// printf("u =  %d ", u);
			if (par[u] == 0)
				par[u] = v;
			// print_parent(n, par);
			DFS(adj, next, n, m, u, par);
			// printf(" %d ", v);
		}
		else if (adj[u] == 1 && par[v] != u)
		{
			printf("YES\n");
			exit(1);
			// printf("YES in u = %d\n", u);
		}
		row = next[row];
	}
}



int main()
{
	int n, m, N, u, v, i, j, k, *parent;

	int *adj;
	int *next;

	scanf("%d %d", &n, &m);
	N = n + 2 * m;

	parent = (int *)malloc(sizeof(int) * n + 1);
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
		adj[i] = v;
		adj[i + 1] = u;
		
		next[i] = next[u];	
		next[i + 1] = next[v];
	
		next[u] = i;
		next[v] = i + 1;

		i = i + 2;
		k++;
	}

//initialize parents array
	i = 0;
	while (i <= n)
	{
		parent[i] = 0;
		i++;
	}
//start from 1	
	v = 1;
	parent[v] = -1;
	DFS(adj, next, n, m, v, parent);
	printf("NO\n");


	free(adj);
	free(next);
	free(parent);
	return (0);
}











/*
2 1
1 2
*/

/*

6 4
1 2
1 3
4 5
5 6

~~~~~~~~~

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
