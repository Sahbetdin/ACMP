#include <stdio.h>
#include <stdlib.h>

void	print_arr(int **arr, int n)
{
	int i, j;

	i = 1;
	while (i <= n)
	{
		j = 1;
		while (j <= n)
		{
			printf("%4d", arr[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

void	print_dist(int *a, int n)
{
	int i;

	i = 1;
	while (i <= n)
	{
		printf("%4d ", a[i]);
		i++;
	}
	printf("\n");
}

void	append_q(int *Q, int value)
{
	int i;

	i = 0;
	while (i < 10000 && Q[i] != -1)
		i++;
	Q[i] = value;
	return ;
}

int pop_q(int *Q, int n)
{
	int i, tmp;

	tmp = Q[0];
	i = 0;
	while (i < 3 * n)
	{
		Q[i] = Q[i + 1];
		i++;
	}
	return (tmp);
}

//par = parent array
void	dijkstra(int **arr, int n, int *Q, int *dist, int *pos, int *par)
{
	int j;
	int tmp;
	int pos_other;
	
	// print_dist(dist, n);
	// printf("Q: ");
	// print_dist(Q, 14);	
	tmp = Q[*pos];
	if (tmp == -1)
		return ;
	
	pos_other = *pos;
	j = 1;
	while (j <= n)
	{
		if (arr[tmp][j] >= 0 && tmp != j && arr[tmp][j] + dist[tmp] < dist[j])
		{
			par[j] = tmp;
			dist[j] = arr[tmp][j] + dist[tmp];
			append_q(Q, j);
		}
		j++;
	}
	(*pos)++;
	dijkstra(arr, n, Q, dist, pos);
}


int main()
{
	int n, i, j, st, end;
	int const max_size = 10000;
	int Q[max_size];
	int *dist;
	int *parent;
	int **arr;

	scanf("%d %d %d", &n, &st, &end);
	arr = (int **)malloc(sizeof(int *) * n + 1);
	dist = (int *)malloc(sizeof(int) * n + 1);
	parent = (int *)malloc(sizeof(int) * n + 1);
	i = 0;
	while (i < max_size)
	{
		Q[i] = -1;
		i++;
	}

	i = 0;
	while (i <= n)
	{
		arr[i] = (int *)malloc(sizeof(int) * n + 1);
		dist[i] = 10100;
		parent[i] = 0;
		i++;
	}
	dist[st] = 0;
	i = 1;
	while (i <= n)
	{
		j = 1;
		while (j <= n)
		{
			scanf("%d", arr[i] + j);
			j++;
		}
		i++;
	}

//	print_arr(arr, n);
	Q[0] = st;
	int pos = 0;
	parent[st] = 0;
	dijkstra(arr, n, Q, dist, &pos, parent); //0 - position in Q
	print_dist(parent, n);	


	// print_dist(dist, n);	
	if (dist[end] == 10100)
		printf("-1\n");
	else
		printf("%d\n", dist[end]);


	return (0);
}



/*
6 1 6
0 2 4 1 0 0
2 0 0 3 0 0
4 0 0 3 5 0
1 3 3 0 0 1
0 0 5 0 0 2
0 0 0 1 2 0
ans:2 ?

5 1 5
0 1 0 4 0
1 0 0 2 0
0 0 0 5 2
4 2 5 0 1
0 0 2 1 0
ans: 4

5 2 3
0 1 3 2 0
1 0 6 0 2
3 6 0 5 7
2 0 5 0 3
0 2 7 3 0
ans:4

5 1 5 
0 1 3 2 0
1 0 6 0 2
3 6 0 5 7
2 0 5 0 3
0 2 7 3 0
ans:3

*/