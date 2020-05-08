//https://stepik.org/lesson/307327/step/2?unit=289415

#include <stdio.h>
#include <stdlib.h>

int min1(int a, int b)
{
	if (a > b)
		return (b);
	return (a);
}

void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int min2(int a, int b, int c)
{
	int m;

	if (a < b)
		swap(&a, &b);
	if (b < c)
		swap(&b, &c);
	return (c);
}

void	print_s(int n, int m, int **s)
{
	int i, j;

	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < m)
		{
			printf("%4d", s[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

int	update_c(int **s, int x[2])
{
	int i, j;
	int min_;

printf("HERe\n");
	if (x[0] == 0)
	{
		printf("DDDDDDD\n");
		x[0]--;
		return (s[x[0]][x[1]]);
	}
	else if (x[1] == 0)
	{
		printf("JJJJJJ\n");
		x[1]--;
		return (s[x[0]][x[1]]);

	}
	

	//s[x[0] - 1][x[1]], s[x[0]][x[1] - 1], s[x[0] - 1][x[1] - 1]


	if (s[x[0] - 1][x[1]] < s[x[0]][x[1] - 1])
	{
		min_ = s[x[0] - 1][x[1]];
		i = x[0] - 1;
		j = x[1];
	}
	else
	{
		min_ = s[x[0]][x[1] - 1];
		i = x[0];
		j = x[1] - 1;
	}
	if (s[x[0] - 1][x[1] - 1] < s[i][j])
	{
		min_ = s[x[0] - 1][x[1] - 1];
		i = x[0] - 1;
		j = x[1] - 1;
	}

	x[0] = i;
	x[1] = j;
	return (min_);
}



int main()
{
	int **a;
	int **s;
	int n, m; // n rows, m columns
	int i, j;

	scanf("%d %d", &n, &m);
	a = (int **)malloc(sizeof(int *) * n);
	s = (int **)malloc(sizeof(int *) * n);
	i = 0;
	while (i < n)
	{
		a[i] = (int *)malloc(sizeof(int) * m);
		s[i] = (int *)malloc(sizeof(int) * m);
		i++;
	}
	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < m)
		{
			scanf("%d", a[i] + j);
			j++;
		}
		i++;
	}

	s[0][0] = a[0][0];
	j = 1;//to the right in first row
	while (j < m)
	{
		s[0][j] = s[0][j - 1] + a[0][j];
		j++;
	}
	i = 1; //down in first column
	while (i < n)
	{
		s[i][0] = s[i - 1][0] + a[i][0];
		i++;
	}
	i = 1;
	while (i < n)
	{
		j = 1;
		while (j < m)
		{
			// printf("i = %d, j = %d, .. = %d\n", i, j, a[i][j]);
			// printf(" %d,  %d, %d\n", s[i - 1][j], s[i][j - 1], s[i - 1][j - 1]);
			s[i][j] = a[i][j] + min2(s[i - 1][j], s[i][j - 1], s[i - 1][j - 1]);
			j++;
		}
		i++;
	}
	print_s(n, m, s);
	printf("%d ", s[n - 1][m - 1]);
//восстановаление ответа
	int curr_s, x[2], count;
	int xx[10000], yy[10000];
	x[0] = n - 1; x[1] = m - 1;	
	curr_s = s[n - 1][m - 1];
	// printf("curr_s = %d\n", curr_s);

	//printf("%d %d %d\n", s[x[0] - 1][x[1]], s[x[0]][x[1] - 1], s[x[0] -1][x[1]-1]);
	
	printf("~~~~~~~~~~\n");
	count = 0;
	while (!(x[0] != 0 && x[1] != 0))
	{
		if (x[0] == 0)
		{
			x[1]--;
			
		}
		else (x[1] == 0)
		{
			x[0]--;
		}
		else
		{

		}

	}



	return 0;
}


