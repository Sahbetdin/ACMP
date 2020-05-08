
//https://stepik.org/lesson/307327/step/9?unit=289415

#include <stdio.h>
#include <stdlib.h>


void	print_s(int n, int m, long **s)
{
	int i, j;

printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < m)
		{
			printf("%4ld", s[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

void	print_dp(int m, long *dp)
{
	int j;

	j = 0;
	while (j < m)
	{
		printf("%4ld ", dp[j]);
		j++;
	}
	printf("\n");
}



int main()
{
	int MOD = (int)1e9 + 7;
	int n, m, i, j, ii, jj;
	long **s, tmp, *dp, *dp_col, *dp_diag;

	scanf("%d %d", &n, &m);

	s = (long **)malloc(sizeof(long *) * n); //выделяем память под строки
	dp = (long *)malloc(sizeof(long) * m);//строка длиной m, содержит сумму пред m элем
	dp_col = (long *)malloc(sizeof(long) * m);//сумма по столбцам длиной m
	dp_diag = (long *)malloc(sizeof(long) * m);//сумма по диаг для каждого столбца

	//нумерация строк от 0 до n - 1;
	//нумерация столбцов от 0 до m - 1;
	i = 0;
	while (i < n)
	{
		s[i] = (long *)malloc(sizeof(long) * m); //выделяем память под столбцы
		i++; //бежим по строкам
	}
	//обнуление, possibly not necessary
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
	if (n == 1 && m == 1)
	{
		printf("1\n");
		return 0;
	}
	else if ((n == 1 && m == 2) || (n == 2 && m == 1))
	{
		printf("1\n");
		return 0;		
	}
	else if (n == 2 && m == 2)
	{
		printf("3\n");
		return 0;		
	}
	s[0][0] = 1;
	s[0][1] = 1;
	dp_col[0] = s[0][0];
	dp_diag[0] = s[0][0];


	j = 2;
	while (j < m)
	{
		s[0][j] = s[0][j - 1] * 2;
		if (s[0][j] >= MOD)
			s[0][j] = s[0][j] % MOD;
		dp_diag[j] = s[0][j];
		dp_col[j] = s[0][j];
		j++;
	}
	
	if (n == 1)
	{
		printf("%ld\n", s[n - 1][m - 1]);
		return (0);
	}

	i = 2;
	s[1][0] = 1;
	dp_col[1] = s[0][1];
	dp_diag[1] = s[0][1];
	while (i < n)
	{
		s[i][0] = s[i - 1][0] * 2;
		if (s[i][0] >= MOD)
			s[i][0] = s[i][0] % MOD;
		i++;
	}
	

	// printf("~~~~~~~~~~~~~\n");
	// print_dp(m, dp_col);
	// printf("~~~~~~~~~~~~~\n");
//fill in row #2
	i = 1;
	while (i < n)
	{
		j = 1;
		dp[0] = s[i][0];
		while (j < m)
		{
			// printf("dp[j - 1] = %ld\n", dp[j - 1]);
			// printf("dp_col[j] = %ld\n", dp_col[j]);
			s[i][j] = dp[j - 1] + dp_col[j] + dp_diag[j - 1];
			if (s[i][j] >= MOD)
				s[i][j] = s[i][j] % MOD;

			dp_col[j] = dp_col[j] + s[i][j];
			if (dp_col[j] >= MOD)
				dp_col[j] = dp_col[j] % MOD;

			dp[j] = dp[j - 1] + s[i][j];
			if (dp[j] >= MOD)
				dp[j] = dp[j] % MOD;
			j++;
		}
		// print_dp(m, dp);

		j--;
		// printf("   i = %d  |  ", i);
		// print_dp(m, dp_diag);
		while (j > 0)
		{
			dp_diag[j] = dp_diag[j - 1] + s[i][j];
			if (dp_diag[j] >= MOD)
				dp_diag[j] = dp_diag[j] % MOD;
			j--;
		}
		dp_diag[0] = s[i][0];
		if (dp_diag[0] >= MOD)
			dp_diag[0] = dp_diag[0] % MOD;
		// printf("JJ i = %d  |  ", i);
		// print_dp(m, dp_diag);
		i++;
	}
	// print_s(n,m,s);
	// print_dp(m, dp);
	// print_dp(m, dp_col);
	printf("%ld\n", s[n - 1][m - 1]);

	return 0;
}

