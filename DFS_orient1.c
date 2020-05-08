#include <stdio.h>
#include <stdlib.h>
//8th of April 2020

// print lists adj, next
void	print_adj_next(int N, int *adj, int *next)
{
	int k;

	k = 1;
	while (k <= N)
	{
		printf("adj[%d] = %d, next[%d] = %d \n", k, adj[k], k, next[k]);
		k++;
	}

}

void	copy_adj_next(int N, int *adj, int *next, int *adj_copy, int *next_copy)
{
	int i;

	i = 0;
	while (i <= N)
	{
		adj_copy[i] = adj[i];
		next_copy[i] = next[i];
		i++;
	}
}


//template
// void	DFS(int *adj, int *next, int n, int m, int v)
// {
// 	int j, row, u;

// 	adj[v] = 1;

// 	// printf(" %d ", v);

// 	row = next[v];
// 	while (row != 0)
// 	{
// 		u = adj[row];
// 		next[v] = next[row];
// 		if (adj[u] == 0)
// 		{
// 			DFS(adj, next, n, m, u);
// 			// printf(" %d ", v);
// 		}
// 		row = next[row];
// 	}
// }

void	init_parent(int n, int *par)
{
	int i;

	i = 0;
	while (i <= n)
	{
		par[i] = 0;
		i++;
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

void	print_order(int n, int *order)
{
	int i;

	i = 1;
	printf("ORDER: ");
	while (i <= n)
	{
		printf("%d ", order[i]);
		i++;
	}
	printf("\n");
}

int		find_in_order(int n, int *order, int el)
{
	int i;

	i = 1;
	while (i <= n)
	{
		if (order[i] == el)
			return (i);
		i++;
	}
	return (-1);
}


void	DFS(int *adj, int *next, int n, int m, int v, int *par, int *order, int *i_addr)
{
	int j, row, u;

	order[*i_addr] = v;
	(*i_addr)++;
	adj[v] = 1;

	// printf("vis-ed v = %d\n", v);

	row = next[v];
	while (row != 0)
	{
		u = adj[row];
		next[v] = next[row];
		if (adj[u] == 0)
		{
			// printf("  GO to : %d \n", u);

			// if (par[u] == 0)
				par[u] = v;
			DFS(adj, next, n, m, u, par, order, i_addr);
			// printf("       FIN v = %d\n", u);
			adj[u] = 2; 
		}
		else if (adj[u] == 1)
		{
			// printf("i_addr = %d\n", *i_addr);
			printf("YES\n");
			j = find_in_order(n, order, u);
			printf("%d\n", *i_addr - j);
			// printf("u = %d ", u);
			while (j < *i_addr)
			{
				printf("%d ", order[j]);
				j++;
			}
			// print_order(n, order);
			exit (1);

		}
		row = next[row];
	}
	// print_parent(n, par);
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


int main()
{
	int n, m, N, u, v, i, k, i_order;
	int *parent;
	int *adj, *adj_copy;
	int *next, *next_copy, *order;

	scanf("%d %d", &n, &m);
	N = n + 2 * m;

	parent = (int *)malloc(sizeof(int) * n + 1);
	order = (int *)malloc(sizeof(int) * n + 1);
	adj = (int *)malloc(sizeof(int) * N + 1);
	adj_copy = (int *)malloc(sizeof(int) * N + 1);
	next = (int *)malloc(sizeof(int) * N + 1);
	next_copy = (int *)malloc(sizeof(int) * N + 1);

	i = 0;
	while (i <= N)
	{
		adj[i] = 0;
		next[i] = 0;
		i++;
	}

//осталось найти те, которые сразу идут в родительскую

	i = n + 1;
	k = 1;
	while (k <= m)
	{
		scanf("%d %d", &u, &v);
		if (u == v)
		{
			printf("2\n");
			printf("%d %d\n", u , u);
			exit (1);
		}
		adj[i] = v;
		adj[i + 1] = u;		
		next[i] = next[u];	
		next[u] = i;
		i = i + 2;
		k++;
	}


	i = 1;
	while (i <= n)
	{
		i_order = 1;
		v = i;
		init_parent(n, parent);
		parent[v] = -1;
		copy_adj_next(N, adj, next, adj_copy, next_copy);
		DFS(adj_copy, next_copy, n, m, v, parent, order, &i_order);
		i++;
	}
	printf("NO\n");

	free(adj);
	free(next);
	free(adj_copy);
	free(order);
	free(next_copy);

	return (0);
}