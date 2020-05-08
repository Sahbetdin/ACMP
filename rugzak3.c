//https://stepik.org/lesson/307329/step/7?unit=289417

#include <stdio.h>
#include <stdlib.h>

void	print_dp(long m, long *dp)
{
	long j;

	j = 0;
	while (j < m)
	{
		printf("%4ld ", dp[j]);
		j++;
	}
	printf("\n");
}

long max(long a, long b)
{
	if (a > b)
		return (a);
	return (b);
}


long get_max_index(long n, long *p)
{
	long i, i_max;

	i_max = 0;
	i = 1;
	while (i <= n)
	{
		if (p[i] > p[i_max])
			i_max = i;
		i++;
	}
	return (i_max);
}



int main()
{
	long **dp, i, j, n, *w, *c, S, k, *ans, cost;


	scanf("%ld %ld", &S, &n);
	w = (long *)malloc(sizeof(long) * n + 1); //weights
	c = (long *)malloc(sizeof(long) * n + 1); //costs
	i = 0;
	while (i < n)
	{
		scanf("%ld", w + i + 1);
		i++;
	}
	i = 0;
	while (i < n)
	{
		scanf("%ld", c + i + 1);
		i++;
	}

	dp = (long **)malloc(sizeof(long *) * n + 1);
	ans = (long *)malloc(sizeof(long) * S + 1);

	i = 0;
	while (i <= n)
	{
		dp[i] = (long *)malloc(sizeof(long) * S + 1);
		i++;
	}

	i = 0;
	for (j = 0; j <= S; j++) {
		dp[i][j] = -1;
	}
	dp[0][0] = 0;


	for (j = 0; j <= S; j++) {
		for (i = 1; i <= n; i++) {
			if (j - w[i] >= 0) {
				dp[i][j] = max(dp[i - 1][j - w[i]] + c[i], dp[i - 1][j]);
			}
			else {
				dp[i][j] = dp[i - 1][j];
			}

		}
	}
	// print_dp(S + 1, dp[0]);
	// print_dp(S + 1, dp[1]);
	// print_dp(S + 1, dp[2]);
	// print_dp(S + 1, dp[3]);
	// print_dp(S + 1, dp[4]);

	printf("%ld ", dp[n][get_max_index(S, dp[n])]);
	i = n;
	j = get_max_index(S, dp[n]);

	// printf("i = %ld, j = %ld\n", i, j);
	k = -1;
	cost = dp[i][j];
	while (cost > 0)
	{
		k++;
		while (dp[i][j] == cost)
			i--;
		i++;
		ans[k] = i;
		cost = cost - c[i];
		j = j - w[i];
		i--;

	// printf("i = %ld, j = %ld\n", i, j);
	}
	i = k;
	printf("%ld\n", k + 1);

	while (i >= 0)
	{
		printf("%ld ", ans[i]);
		i--;
	}




	return (0);
}