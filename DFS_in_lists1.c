#include <stdio.h>
#include <stdlib.h>

//начато

typedef struct		s_list
{
	int				data;
	strcut s_list	*next;
}					t_list;

void	add_list(t_list **t, int )
{

}

int main()
{
	int n, m, i, j;
	t_list **gr;

	scanf("%d %d", &n, &m);
	gr = (t_list **)malloc(sizeof(t_list *) * n);
	i = 0;
	while (i < n)
	{
		gr[i] = NULL;
		i++;
	}





	return (0);
}