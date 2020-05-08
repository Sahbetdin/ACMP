//https://stepik.org/lesson/307331/step/6?unit=289419
//Требуется выделить дерево обхода графа в глубину.

#include <stdio.h>
#include <stdlib.h>

int *order;
int k;


void	find_edge(int m, int *in_, int *out_, char *ticked_edge, int v, int i)
{
	int k;

	k = 1;
	while (k <= m)
	{
		if ((in_[k] == v && out_[k] == i) || (in_[k] == i && out_[k] == v))
		{
			ticked_edge[k] = 1;
			return ;
		}
		k++;
	}
}


void	dfs(int n, char **gr, char *visited, int v, int m, int *in_, int *out_, char *ticked_edge) {
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
			find_edge(m, in_, out_, ticked_edge, v, i);
			dfs(n, gr, visited, i, m, in_, out_, ticked_edge);
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
	char *ticked_edge;
	int *in_, *out_;
	int s;
	k = 0;

	scanf("%d %d", &n, &m);
	gr = (char **)malloc(sizeof(char *) * n + 1);
	visited = (char *)malloc(sizeof(char) * n + 1);
	order = (int *)malloc(sizeof(int) * 2 * n + 1);

	in_ = (int *)malloc(sizeof(int) * m + 1);
	out_ = (int *)malloc(sizeof(int) * m + 1);
	ticked_edge = (char *)malloc(sizeof(char) * m + 1);


	i = 0;
	while (i <= m)
	{
		in_[i] = 0;
		out_[i] = 0;
		ticked_edge[i] = 0;
		i++;
	}

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
		in_[i + 1] = u;
		out_[i + 1] = v;
		i++;
	}


	v = 1;
	dfs(n, gr, visited, v, m, in_, out_, ticked_edge);
	// i = 0;
	// printf("k = %d\n", k);

	// while (i < k)
	// {
	// 	printf("%d ", order[i]);
	// 	i++;
	// }
	i = 1;
	s = 0;
	while (i <= m)
	{
		s += ticked_edge[i];
		i++;
	}
	printf("%d\n", s);

	i = 1;
	while (i <= m)
	{
		if (ticked_edge[i] == 1)
			printf("%d ", i);
		i++;
	}


	i = 0;
	while (i <= n)
	{
		free(gr[i]);
		i++;
	}
	free(gr);
	free(visited);
	free(order);
	free(in_);
	free(out_);
	free(ticked_edge);
	return (0);
}

