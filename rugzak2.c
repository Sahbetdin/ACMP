//https://stepik.org/lesson/307329/step/6?unit=289417

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

int max_price(int n, long double *p)
{
	int i, i_max;
	long double max_p;

	i_max = 1;
	i = 2;
	while (i <= n)
	{
		// printf("price = %Lf\n", p[i]);
		if (p[i] > p[i_max])
			i_max = i;
		i++;
	}
	return (i_max);
}

int main()
{
	int **dp, i, j, n, *w, *c, S, k, i_max;
	long double *p, c_total;

	scanf("%d %d", &S, &n);
	w = (int *)malloc(sizeof(int) * n + 1); //weights
	c = (int *)malloc(sizeof(int) * n + 1); //costs
	p = (long double *)malloc(sizeof(long double) * n + 1); //prices
	i = 0;
	while (i < n)
	{
		scanf("%d", w + i + 1);
		i++;
	}
	i = 0;
	while (i < n)
	{
		scanf("%d", c + i + 1);
		i++;
	}
	i = 1;
	while (i <= n)
	{
		p[i] = c[i] * 1.0L /w[i];
		i++;
	}

	// printf("i_max = %d\n", c[i_max]);
	// printf("c_max = %d\n", c[i_max]);
	// return 0;

	c_total = 0.0L;
	int count;
	count = 0;
	while (1)
	{
		count++;
		i_max = max_price(n, p);
		// printf("i_max = %d\n", i_max);
		if (w[i_max] == -1)
			break ;
		else if (w[i_max] < S)
		{
			c_total += c[i_max];
			S -= w[i_max];
			c[i_max] = -1;
			p[i_max] = -1.0L;
			w[i_max] = -1;
		}
		else
		{
			c_total += S * p[i_max];
			// printf("c_total =  %Lf\n", c_total);
			break ;
		}

	}
	// printf("count = %d\n", count);


	if (c_total - (long)c_total < 1.e-10l)
		printf("%ld\n", (long)c_total);
	else
		printf("%ld\n", (long)c_total + 1);



	// dp = (int **)malloc(sizeof(int *) * n + 1);
	// i = 0;
	// while (i <= n)
	// {
	// 	dp[i] = (int *)malloc(sizeof(int) * S + 1);
	// 	i++;
	// }


/*
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
*/

	// print_dp(S + 1, dp[0]);
	// print_dp(S + 1, dp[1]);
	// print_dp(S + 1, dp[2]);
	// print_dp(S + 1, dp[3]);
	// print_dp(S + 1, dp[4]);

	// print_dp(S + 1, dp[5]);
	// print_dp(S + 1, dp[6]);
	return (0);
}