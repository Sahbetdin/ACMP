#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>


typedef struct			s_list
{
	int					data;
	struct s_list		*next;
}						t_list;

/*
this is a vertice v with adjacency list of neighbours *head
*/
typedef struct			s_neighbours
{
	struct s_list		*head;
	int					v;
}						t_neighbours;

/*
n - number of vertices
m - number of edges
*/
typedef struct			s_graph
{
	int 				n; 
	int 				m;
	struct s_neighbours	*start_vert;
}						t_graph;

typedef struct			s_queue
{
	int					*front;
	int					*rear;
	int					n;
} t_queue;

void	queue_init(t_queue *Q, int size);
int		queue_is_empty(t_queue *Q);
int		queue_is_full(t_queue *Q);
int		queue_insert(t_queue *Q, int x);
void	queue_print(t_queue *Q);
int		queue_out_first(t_queue *Q);
int		queue_shine_first(t_queue *Q);
void	queue_delete(t_queue *Q);
int		queue_pop(t_queue *Q);



/*
adds element with data x to the beginnig of a 
list and updates head, which is *t
*/
void	add_element(t_list **t, int x)
{
	t_list *tmp;

	tmp = (t_list *)malloc(sizeof(t_list));
	tmp->next = *t;
	tmp->data = x;
	*t = tmp;
}

void	delete_list(t_list **t)
{
	t_list *tmp1;
	t_list *tmp2;

	tmp1 = *t;
	while (tmp1 != NULL)
	{
		tmp2 = tmp1->next;
		free(tmp1);
		tmp1 = tmp2;
	}
	*t = NULL;
}

void	delete_graph( t_graph *g)
{
	int i;

	i = 0;
	while (i < g->n)
	{
		delete_list(&g->start_vert[i].head);
		i++;
	}
	free(g->start_vert);
	g->start_vert = NULL;
}

void	print_array_char(int n, char *arr)
{
	int i;

	i = 0;
	while (i < n)
	{
		printf("%d ", arr[i]);
		i++;
	}
	printf("\n");
}

void	print_list(t_list **t)
{
	t_list *tmp;

	tmp = *t;
	while (tmp != NULL)
	{
		printf("%d -> ", tmp->data);
		tmp = tmp->next;
	}
	printf("NULL\n");
}

void	graph_print(int n, t_neighbours *vert)
{
	int j;

	j = 0;
	while (j < n)
	{
		printf("%d: ", j);
		print_list(&vert[j].head);
		j++;
	}

}

void	Dijkstra(t_graph *g, int *shortest)
{
	t_queue q;
	
}




int main(int argc, char **argv)
{
	int fd, n, m;
	int i, j, k, u, v;
	t_graph G;
	// t_neighbours	*start_vert;
	
	if (argc < 2)
		return (0);

	FILE* file = fopen(argv[1], "r");
	fscanf(file, "%d %d", &G.n, &G.m);
	printf("n = %d, m = %d\n", G.n, G.m);

//init graph G
	G.start_vert = (t_neighbours *)malloc(sizeof(t_neighbours) * G.n);
	i = 0;
	while (i < G.n)
	{
		G.start_vert[i].v = i;
		G.start_vert[i].head = NULL;
		i++;
	}

//read edges list NOT WEIGHT
	j = 0;
	while (j < G.m)
	{
		fscanf(file, "%d %d", &v, &u);
		add_element(&G.start_vert[v].head, u);
		add_element(&G.start_vert[u].head, v);
		// printf("%d %d\n", v, u);
		j++;
	}
	fclose(file);

	// graph_print(G.n, G.start_vert);

//DFS algorithm
	// char *visited;
	// visited_init(G.n, visited);
	// DFS(&G, 0, visited);
	// free(visited);

//BFS algorithm
	BFS(&G, 0);

	delete_graph(&G);
	return (0);
}


















///////QUEUE FUNCTIONS////////////////

void	queue_init(t_queue *Q, int size)
{
	int i;

	Q->n = size;
	Q->front = (int *)malloc(sizeof(int) * size);
	i = 0;
	while (i < size)
	{
		Q->front[i] = 0;
		i++;
	}
	Q->rear = Q->front; 
}

int		queue_is_empty(t_queue *Q)
{
	if (Q->front == Q->rear)
		return (1);
	else
		return (0);
}

int		queue_is_full(t_queue *Q)
{
	if (Q->rear - Q->front == Q->n)
		return (1);
	else
		return (0);
}

//if successfully inserted, then return 1
//else return 0
int		queue_insert(t_queue *Q, int x)
{
	if (queue_is_full(Q))
	{
		printf("queue is full\n");
		return (0);
	}
	else
	{
		Q->rear[0] = x;
		Q->rear++;
	}
	return (1);
}

void	queue_print(t_queue *Q)
{
	int i;

	if (queue_is_empty(Q))
	{
		printf("empty\n");
		return ;
	}
	i = 0;
	while (Q->front + i < Q->rear)
	{
		printf("%d ", Q->front[i]);
		i++;
	}
	printf("\n");
}

//if could deleted first, then 
// return that element
//else return -1
int		queue_out_first(t_queue *Q)
{
	int elem;
	int i;
	int maxi;

	if (queue_is_empty(Q) == 0)
	{
		maxi = Q->rear - Q->front;
		elem = Q->front[0];
		i = 0;
		while (i < maxi - 1)
		{
			Q->front[i] = Q->front[i + 1];
			i++;
		}
		Q->rear--;
		return (elem);
	}
	else
		return (-1);
}

//returns first element if the queue is not empty
//else returns -1. 
//Could be resolved?
int		queue_shine_first(t_queue *Q)
{
	if (queue_is_empty(Q) == 0)
	{
		return (Q->front[0]);
	}
	else
		return (-1);
}

void	queue_delete(t_queue *Q)
{
	free(Q->front);
}

/*
if queue is not empty returns pops first element 
and shifts all other elements
else returns -1
*/
int		queue_pop(t_queue *Q)
{
	int tmp;
	int i;

	if (queue_is_empty(Q))
		return (-1);
	tmp = Q->front[0];
	i = 0;
	while (i < Q->n - 1)
	{
		Q->front[i] = Q->front[i + 1];
		i++;
	}
	(Q->rear)--;
	(Q->n)--;
	return (tmp);
}
//////////////////////////////////////

















