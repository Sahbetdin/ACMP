//https://stepik.org/lesson/307331/step/2?unit=289419
//steps in graphs during DFS
#include <stdio.h>
#include <stdlib.h>
//3rd of April 2020

//v - vertix for which DFS will start
//we use adj, next, n, m as input
//we write visited node to list[*i_addr] and increment *i_addr
// void	DFS(int *adj, int *next, int n, int m, int *list, int *i_addr, int v)
// {
// 	int row; //current row
// 	int u; //next vertex

// 	list[*i_addr] = v; //include to the list
// 	// printf("i_addr = %d\n", *i_addr);
// 	// printf("list[*i_addr] = %d\n", list[*i_addr]);

// 	adj[v] = 1; //say that visited
// 	*i_addr += 1; //increase i for being ready for next one

// 	row = next[v]; //row where the next vertex stays

// 	// printf("row = %d\n", row);


// 	while (row != 0)
// 	{
// 		// printf("ZZ\n");
// 		u = adj[row];
// 		// printf("u = %d\n", u);

// 		if (adj[u] == 1)
// 		{
// 			// printf("ONE\n");

// 			row = next[row];
// 			next[v] = row;
// 		}
// 		else
// 		{
// 			// printf("	DFS\n");
// 			next[v] = row;
// 			DFS(adj, next, n, m, list, i_addr, u);
// 		}
// 	}
// 	list[*i_addr] = u;
// 	*i_addr += 1;
// 	printf("FIN for %d\n", v);

// }

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

void	DFS(int *adj, int *next, int n, int m, int *list, int *i_addr, int v)
{
	int j, row, u;

	adj[v] = 1;

	list[*i_addr] = v;
	(*i_addr)++;
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

			list[*i_addr] = v;
			(*i_addr)++;
		}
		row = next[row];
	}
}

/*
4 3
1 2
1 3
3 4
*/

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
	scanf("%d", &v); //start DFS from v vertex
	i = 0;
	print_adj_next(N, adj, next);
	DFS(adj, next, n, m, list, &i, v);

	printf("i = %d\n", i);
	printf("\nNOW LIST:\n");
	k = 0;
	while (k < i)
	{
		printf("%d ", list[k]);
		k++;
	}




/*
//print adjacency list for all vertice
	i = 1;
	int curr_row;
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
*/

	free(adj);
	free(next);
	free(list);
	return (0);
}