
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


int abs(int a)
{
	if (a > 0)
		return (a);
	return (-a);
}

void	print_s(int n, int **s)
{
	int i, j;

	i = 0;
	printf("~~~~~~~~~~~~\n");
	while (i < n)
	{
		j = 0;
		while (j < i + 1)
		{
			printf("%4d", s[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	printf("~~~~~~~~~~~~\n");
}

int get_max(int n, int *a)
{
	int i;
	int max_;

	max_ = a[0];
	i = 1;
	while (i < n)
	{
		if (a[i] > max_)
			max_ = a[i];
		i++;
	}
	return (max_);
}


int main()
{
	int **a;
	int **s;
	int n, m; // n rows, m columns
	int i, j;
	int tmp1, tmp2;

	scanf("%d", &n);
	a = (int **)malloc(sizeof(int *) * n);
	s = (int **)malloc(sizeof(int *) * n);
	i = 0;
	while (i < n)
	{
		a[i] = (int *)malloc(sizeof(int) * i + 1);
		s[i] = (int *)malloc(sizeof(int) * i + 1);
		i++;
	}

	i = 0;
	while (i < n)
	{
		j = 0;
		// printf("i = %d\n", i);
		while (j < i + 1)
		{
			scanf("%d", a[i] + j);
			// printf("el = %d\n", a[i][j]);
			j++;
		}
		i++;
	}

	if (n == 1)
	{
		printf("%d\n", a[0][0]);
		return (0); //забили на утечки памяти
	}
	if (n == 2)
	{
		printf("%d\n", max1(a[1][0],a[1][1]));
		return (0);
	}
	s[0][0] = a[0][0];
	s[1][0] = s[0][0] + a[1][0];
	s[1][1] = s[0][0] + a[1][1];

	i = 2;
	while (i < n)
	{
		s[i][0] = s[i - 1][0] + a[i][0];
		s[i][i] = s[i - 1][i - 1] + a[i][i];
		j = 1;
		while (j < i)
		{
			s[i][j] = a[i][j] + max1(s[i - 1][j - 1], s[i - 1][j]);
			j++;
		}
		i++;
	}
	// print_s(n, s);
	printf("%d\n", get_max(n, s[n - 1]));

	return (0);
}