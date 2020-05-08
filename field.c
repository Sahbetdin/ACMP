//https://stepik.org/lesson/307327/step/3?unit=289415

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

int abs(int a)
{
	if (a > 0)
		return (a);
	return (-a);
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


int main()
{
	int **a;
	int **s;
	int n, m; // n rows, m columns
	int i, j;
	int tmp1, tmp2;

	scanf("%d %d", &m, &n);
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

	s[0][0] = 0;
	j = 1;//to the right in first row
	while (j < m)
	{
		s[0][j] = abs(a[0][j] - a[0][j - 1]) + s[0][j - 1];
		j++;
	}
	i = 1; //down in first column
	while (i < n)
	{
		s[i][0] = abs(a[i][0] - a[i - 1][0]) + s[i - 1][0];
		i++;
	}
	i = 1;
	while (i < n)
	{
		j = 1;
		while (j < m)
		{
			// tmp1 = abs(a[i][j] - a[i][j - 1]);
			// tmp2 = abs(a[i][j] - a[i - 1][j]);
			// if (tmp1 < tmp2)
			// 	s[i][j] = tmp1 + s[i][j - 1];
			// else if (tmp1 > tmp2)
			// 	s[i][j] = tmp2 + s[i - 1][j];
			// else
			// 	s[i][j] = tmp1 + min1(s[i][j - 1], s[i - 1][j]);
			// printf("i = %d, j = %d, .. = %d\n", i, j, a[i][j]);
		//	printf(" %d,  %d, %d\n", s[i - 1][j], s[i][j - 1], s[i - 1][j - 1]);
			// s[i][j] = min1(abs(a[i][j] - a[i][j - 1]), abs(a[i][j] - a[i - 1][j])) + min1(s[i][j - 1], s[i - 1][j]);
			// printf("%d ", abs(a[i][j] - a[i][j - 1]) + s[i][j - 1]);
			// printf("%d\n", abs(a[i][j] - a[i - 1][j]) + s[i - 1][j]);
			s[i][j] = min1(abs(a[i][j] - a[i][j - 1]) + s[i][j - 1], abs(a[i][j] - a[i - 1][j]) + s[i - 1][j]);
			j++;
		}
		i++;
	}
	// print_s(n, m, s);
	printf("%d\n", s[n - 1][m - 1]);		
	return 0;
}
