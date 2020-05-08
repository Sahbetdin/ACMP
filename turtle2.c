//https://stepik.org/lesson/307327/step/6?unit=289415

#include <stdio.h>
#include <stdlib.h>

int max1(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int max2(int a, int b, int c)
{
	int m;

	if (a > b)
		swap(&a, &b);
	if (b > c)
		swap(&b, &c);
	return (c);
}


void	print_s(int n, int m, long s[1005][1005])
{
	int i, j;

printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	i = 1;
	while (i <= n)
	{
		j = 1;
		while (j <= m)
		{
			printf("%4ld", s[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}


int main()
{
	int n, m, i, j;
	int **a;
	long **s;



	scanf("%d %d", &n, &m);
	a = (int **)malloc(sizeof(int *) * n + 1);
	s = (long **)malloc(sizeof(long *) * n + 1);
	i = 0;
	while (i <= n)
	{
		a[i] = (int *)malloc(sizeof(int) * m + 1);
		s[i] = (long *)malloc(sizeof(long) * m + 1);
		i++;
	}


	i = 0;
	while (i <= n) //zeroth column
	{
		a[i][0] = 0;
		s[i][0] = 0;
		i++;
	}
	j = 0;
	while (j <= m) //zeroth row
	{
		a[0][j] = 0;
		s[0][j] = 0;
		j++;
	}
	
	i = 1;
	while (i <= n)
	{
		j = 1;
		while (j <= m)
		{
			scanf("%d", a[i] + j);
			j++;
		}
		i++;
	}
// print_s(n, m, a);
// return 0;

	s[1][1] = 1;
	i = 1;
	while (i <= n) //zeroth column
	{
		if (a[i][1] == 1)
			break ;
		s[i][1] = 1;
		i++;
	}
	j = 1;
	while (j <= m) //zeroth row
	{
		if (a[1][j] == 1)
			break ;
		s[1][j] = 1;
		j++;
	}

//////
	i = 2;
	while (i <= n)
	{
		j = 2;
		while (j <= m)
		{

			s[i][j] = (a[i][j] == 0) ? (s[i-1][j] + s[i-1][j-1] + s[i][j-1]) % 1000000009 : 0;
			j++;
		}
		i++;
	}
	// print_s(n, m, s);
	printf("%ld\n", s[n][m]);

	return (0);
}