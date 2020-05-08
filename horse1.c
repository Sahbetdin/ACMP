//https://stepik.org/lesson/307327/step/7?unit=289415

#include <stdio.h>
#include <stdlib.h>

void	print_s(int n, int **s)
{
	int i, j;

printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < n)
		{
			printf("%4d", s[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

void update_s(int n, int m, long **s, int i, int j)
{
	/*
	з - здесь находимся
	к - клетка-кандидат на попадание в з
		* к * к
		к * *
		* * з
		к * *
	*/
	//j - для столбцов, i - для строк
	if (j - 2 >= 0)
	{
		if (i - 1 >= 0)
			s[i][j] += s[i - 1][j - 2];
		if (i + 1 < n)
			s[i][j] += s[i + 1][j - 2];
	}
	if (i - 2 >= 0)
	{
		if (j - 1 >= 0)
			s[i][j] += s[i - 2][j - 1];
		if (j + 1 < m)
			s[i][j] += s[i - 2][j + 1];
	}
	if (s[i][j] >= 1000000123)
		s[i][j] = s[i][j] % 1000000123;
}

int main()
{
	int n, m, k, beg_i, i, j, l;
	long **s;

	scanf("%d %d", &n, &m);
	s = (long **)malloc(sizeof(long *) * n); //выделяем память под строки
	//нумерация строк от 0 до n - 1;
	//нумерация столбцов от 0 до m - 1;
	i = 0;
	while (i < n)
	{
		s[i] = (long *)malloc(sizeof(long) * m); //выделяем память под столбцы
		i++; //бежим по строкам
	}
	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < m)
		{
			s[i][j] = 0;
			j++;
		}
		i++;
	}
	s[0][0] = 1;
	l = n - 1 + m; //кол-во диагоналей
	k = 0;
	while (k < l) //можно начать с k = 3
	{
		if (k < m)
		{
			j = k;
			i = 0;
		}
		else
		{
			j = m - 1;
			i = k - j;
		}
		while (i < n && j >= 0)
		{
			update_s(n, m, s, i, j);
			j--;
			i = k - j;
		}
		k++;
	}

printf("%ld\n", s[n - 1][m - 1]);


	i = 0;
	while (i < n)
	{
		free(s[i]);
		i++;
	}
	free(s);


	return (0);
}


//обход по диагонали для квадратной матрицы
// int main()
// {
// 	int n, k, beg_i, i, j, l;
// 	int **s;

// n = 5;

// 	s = (int **)malloc(sizeof(int *) * n);
// 	i = 0;
// 	while (i < n)
// 	{
// 		s[i] = (int *)malloc(sizeof(int) * n);
// 		i++;
// 	}

// 	i = 0;
// 	while (i < n)
// 	{
// 		j = 0;
// 		while (j < n)
// 		{
// 			s[i][j] = 0;
// 			j++;
// 		}
// 		i++;
// 	}
// 	s[0][0] = 1;

	

// 	k = 0;
// 	while (k < n)
// 	{
// 		j = k;
// 		while (j >= 0)
// 		{
// 			i = k - j;
// 			// printf("i = %d, j = %d ", i, j);
// 			// printf("bef: %d, ", s[i][j]);
// 			//////////////////
// 			if (j - 2 >= 0)
// 			{
// 				if (i - 1 >= 0)
// 				{
// 				//	printf("s[i-1][j-2] = %d,", s[i - 1][j - 2]);
// 					s[i][j] += s[i - 1][j - 2];
// 				}
// 				if (i + 1 < n)
// 					s[i][j] += s[i + 1][j - 2];
// 			}
// 			if (i - 2 >= 0)
// 			{
// 				if (j - 1 >= 0)
// 				{
// 					// printf("s[i-2][j-1] = %d,", s[i - 2][j - 1]);
// 					s[i][j] += s[i - 2][j - 1];
// 				}
// 				if (j + 1 < n)
// 					s[i][j] += s[i - 2][j + 1];
// 			}
// 			// printf("aft: %d \n", s[i][j]);

// 			//////////////////////
// 			j--;
// 		}

// 		k++;
// 	}
// 	l = 2 * n - 1;
// 	while (k < l)
// 	{
// 		j = n - 1;
// 		i = k - j;
// 		while (i < n)
// 		{
// 			// printf("i = %d, j = %d\n", i, j);
// 			//////////////////
// 			if (j - 2 >= 0)
// 			{
// 				if (i - 1 >= 0)
// 				{
// 				//	printf("s[i-1][j-2] = %d,", s[i - 1][j - 2]);
// 					s[i][j] += s[i - 1][j - 2];
// 				}
// 				if (i + 1 < n)
// 					s[i][j] += s[i + 1][j - 2];
// 			}
// 			if (i - 2 >= 0)
// 			{
// 				if (j - 1 >= 0)
// 				{
// 					// printf("s[i-2][j-1] = %d,", s[i - 2][j - 1]);
// 					s[i][j] += s[i - 2][j - 1];
// 				}
// 				if (j + 1 < n)
// 					s[i][j] += s[i - 2][j + 1];
// 			}
// 			//////////////////////

// 			j--;
// 			i = k - j;
// 		}

// 		// printf("k = %d\n", k);
// 		k++;
// 	}
// // print_s(n, s);

// printf("%d\n", s[n - 1][n - 1]);
// 	// n = n -1;
// 	// l = 2 * n + 1;

// 	// k = 0;
// 	// while (k < l)
// 	// {
// 	// 	if (k <= n)
// 	// 	{
// 	// 		j = k;
// 	// 		i = 0;
// 	// 	}
// 	// 	else
// 	// 	{
// 	// 		i = k - n;
// 	// 		j = n;

// 	// 	}
// 	// 	printf("i = %d, j = %d\n", i, j);


// 	// 	k++; //current row in diagonal
// 	// }


// 	return (0);
// }