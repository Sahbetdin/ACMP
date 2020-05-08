//https://stepik.org/lesson/307329/step/2?unit=289417
/*
n слитков золота с весами w_i.
Рюкзак может вместить W.
какие слитки взять?
Какой наибольший вес можно унести?

10
2 4 5 3

*/

#include <stdio.h>
#include <stdlib.h>

void	print_dp(int m, int *dp)
{
	int j;

	j = 0;
	while (j < m)
	{
		printf("%4d ", dp[j]);
		j++;
	}
	printf("\n");
}


int main()
{
	int **dp, i, j, n, *w, S, *prev, *ans, curr, k;

	scanf("%d %d", &S, &n);
	w = (int *)malloc(sizeof(int) * n + 1);
	i = 0;
	while (i < n)
	{
		scanf("%d", w + i + 1);
		i++;
	}
	dp = (int **)malloc(sizeof(int *) * n + 1);
	i = 0;
	while (i <= n)
	{
		dp[i] = (int *)malloc(sizeof(int) * S + 1);
		i++;
	}
	prev = (int *)malloc(sizeof(int) * S + 1);
	ans = (int *)malloc(sizeof(int) * n + 1);
	j = 0;
	while (j <= S)
	{
		prev[j] = -1;
		j++;
	}
	j = 0;
	while (j <= S)
	{
		dp[0][j] = 0;
		j++;
	}
	dp[0][0] = 1;




	for (i = 1; i <= n; ++i) {
		// printf("i = %d ", i);

		for (j = 0; j <= S; ++j) {
			if (w[i] <= j) {
				dp[i][j] = dp[i - 1][j] || dp[i - 1][j - w[i]];
				prev[i] = w[j];
			} else {
				dp[i][j] = dp[i - 1][j];
			}
			// printf("i = %d, j = %d\n", i, j);
			// getchar();
		}
	}
	// print_dp(S + 1, dp[0]);
	// print_dp(S + 1, dp[1]);
	// print_dp(S + 1, dp[2]);
	// print_dp(S + 1, dp[3]);
	// print_dp(S + 1, dp[4]);

	// print_dp(S + 1, dp[5]);
	// print_dp(S + 1, dp[6]);

	for (j = S; j >= 0; --j) {
		if (dp[n][j] == 1) {
			printf("%d ", j);
			break ;
		}
	}


	i = n;
	while (i >= 0)
	{
		if (dp[i][j] == 1)
			i--;
		else
			break ;
	}
	i++;
	// printf("i = %d, j = %d\n", i, j);


	k = -1;
	while (j > 0)
	{
		k++;
		while (dp[i][j] == 1)
			i--;
		i++;
		ans[k] = i;
		// printf("%d ", ans[k]);
		j = j - w[i];
		i--;
	}

	printf("%d\n", k + 1);
	// //распечатываем индексы родителей
	i = k;
	while (i >= 0)
	{
		printf("%d ", ans[i]);
		i--;
	}
	return (0);
}