//https://stepik.org/lesson/307327/step/8?unit=289415

#include <stdio.h>
#include <stdlib.h>

const int MOD = 1e9L + 33;

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

	int n, m, i, j, ii, jj;
	long **s, tmp, *dp, *dp_col;

	scanf("%d %d", &n, &m);
	// n = 5;
	// m = 3;

	s = (long **)malloc(sizeof(long *) * n); //выделяем память под строки
	dp = (long *)malloc(sizeof(long) * m);//строка длиной m, содержит сумму пред m элем
	dp_col = (long *)malloc(sizeof(long) * m);//сумма по столбцам длиной m
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
		printf("2\n");
		return 0;		
	}
	s[0][0] = 1;
	
	s[0][1] = 1;
	j = 2;
	while (j < m)
	{
		s[0][j] = s[0][j - 1] * 2;
		if (s[0][j] >= MOD)
			s[0][j] = s[0][j] % MOD;
		j++;
	}
	
	if (n == 1)
	{
		printf("%ld\n", s[n - 1][m - 1]);
		return (0);
	}

	i = 2;
	s[1][0] = 1;
	while (i < n)
	{
		s[i][0] = s[i - 1][0] * 2;
		if (s[i][0] >= MOD)
			s[i][0] = s[i][0] % MOD;
		i++;
	}
	

//fill in row #1
	j = 1;
	dp[0] = s[1][0];
	while (j < m)
	{
		s[1][j] = dp[j-1] + s[0][j];
		if (s[1][0] >= MOD)
			s[1][0] = s[1][0] % MOD;
		dp[j] = dp[j - 1] + s[1][j];
		if (dp[j] >= MOD)
			dp[j] = dp[j] % MOD;
		dp_col[j] = s[0][j] + s[1][j];
		if (dp_col[j] >= MOD)
			dp_col[j] = dp_col[j] % MOD;
		j++;
	}

	// print_s(n,m,s);
//fill in row #2
	i = 2;
	while (i < n)
	{
		j = 1;
		dp[0] = s[i][0];
		while (j < m)
		{
			s[i][j] = dp[j - 1] + dp_col[j];
			if (s[i][j] >= MOD)
				s[i][j] = s[i][j] % MOD;
			dp[j] = dp[j - 1] + s[i][j];
			if (dp[j] >= MOD)
				dp[j] = dp[j] % MOD;
			dp_col[j] = dp_col[j] + s[i][j];
			if (dp_col[j] >= MOD)
				dp_col[j] = dp_col[j] % MOD;
			j++;
		}
		i++;
	}
	print_s(n,m,s);


	// printf("HERE\n");
	// print_dp(m, dp);
	// print_dp(m, dp_col);
	printf("%ld\n", s[n-1][m-1]);

	return 0;
}




// int main()
// {

// 	int n, m, i, j, ii, jj;
// 	long **s, tmp;

// 	scanf("%d %d", &n, &m);
// 	// n = 5;
// 	// m = 3;

// 	s = (long **)malloc(sizeof(long *) * n); //выделяем память под строки
// 	//нумерация строк от 0 до n - 1;
// 	//нумерация столбцов от 0 до m - 1;
// 	i = 0;
// 	while (i < n)
// 	{
// 		s[i] = (long *)malloc(sizeof(long) * m); //выделяем память под столбцы
// 		i++; //бежим по строкам
// 	}
// 	i = 0;
// 	while (i < n)
// 	{
// 		j = 0;
// 		while (j < m)
// 		{
// 			s[i][j] = 0;
// 			j++;
// 		}
// 		i++;
// 	}
// 	if (n == 1 && m == 1)
// 	{
// 		printf("1\n");
// 		return 0;
// 	}
// 	else if ((n == 1 && m == 2) || (n == 2 && m == 1))
// 	{
// 		printf("1\n");
// 		return 0;		
// 	}
// 	else if (n == 2 && m == 2)
// 	{
// 		printf("2\n");
// 		return 0;		
// 	}
// 	s[0][0] = 1;
// 	s[1][0] = 1;
// 	s[0][1] = 1;

// 	j = 2;
// 	while (j < m)
// 	{
// 		s[0][j] = s[0][j - 1] * 2;
// 		if (s[0][j] >= MOD)
// 			s[0][j] = s[0][j] % MOD;	
// 		j++;
// 	}
// 	i = 2;
// 	while (i < n)
// 	{
// 		s[i][0] = s[i - 1][0] * 2;
// 		if (s[i][0] >= MOD)
// 			s[i][0] = s[i][0] % MOD;
// 		i++;
// 	}
// 	// print_s(n,m,s);
// 	// return 0;
// 	i = 1;
// 	while (i < n)
// 	{
// 		j = 1;
// 		while (j < m)
// 		{
// 			tmp = 0;
// 			ii = 0;
// 			// printf("i = %d, j = %d \n", i, j);

// 			while (ii < i)
// 			{
// 				// if (s[ii][j] >= MOD)
// 				// 	s[ii][j] = s[ii][j] % MOD;
// 				tmp += s[ii][j];
// 				ii++;
// 			}
// 			s[i][j] += tmp;
// 			jj = 0;
// 			tmp = 0;
// 			while(jj < j)
// 			{
// 				// if (s[i][jj] >= MOD)
// 				// 	s[i][jj] = s[i][jj] % MOD;
// 				tmp += s[i][jj];
// 				// if (tmp >= MOD)
// 				// 	tmp = tmp % MOD;
// 				jj++;
// 			}
// 			s[i][j] += tmp;
// 			if (s[i][j] >= MOD)
// 				s[i][j] = s[i][j] % MOD;	
// 			j++;
// 		}
// 		i++;
// 	}
// print_s(n,m,s);
// 	printf("%ld\n", s[n - 1][m - 1]);
// 	return (0);
// }