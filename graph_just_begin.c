#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

struct node 
{
	int data;
	struct node *next;
};

struct list
{
	struct node *head;
};

struct Graph
{
	int v;
	struct list *array;
};

struct Graph *graph(int v)
{
	int i;
	struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));

	graph->v = v;
	graph->array = (struct list *)malloc(v * sizeof(struct list));
	i = 0;
	while (i < v)
	{
		graph->array[i].head = NULL;
		i++;
	}
	return (graph);
}

struct node *c_node(int x)
{
	struct node *q = (struct node *)malloc(sizeof(node));
	q->data = x;
	q->next = NULL;
	return (q);
}

//add edge from src to dest
//the node is assed to the beginning
void	add_edge(struct Graph *graph, int src, int dest)
{
	struct node *temp = c_node(dest);
	temp->next = graph->array[src].head;
	graph->array[src].head = temp;
	temp->next = graph->array[i].head;
	graph->array[src].head = temp;
}

void	print_graph(struct Graph *graph)
{
	int v;
	struct node *trav;
	v = 0;
	while (v < graph->v)
	{
		trav = graph->array[v].head;
		while (trav != NULL)
		{
			printf("-> %d\n", trav->data);
			trav = trav->next;
		}
		v++;
	}
}


int main(int argc, char const *argv[])
{
	struct Graph *new_gr;

	new_gr = graph(3);



	return 0;
}
