#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int max_(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int max3(int a, int b, int c)
{
	int tmp;

	tmp = (a > b) ? a : b;
	if (c > tmp)
		tmp = c;
	return (tmp);
}

int main()
{
	char str1[101];
	char str2[101];
	int n1, n2, i, j, n3, k;
	int **dp;
	char *par;

	scanf("%s %s", str1, str2);
	n1 = (int)strlen(str1);
	n2 = (int)strlen(str2);
	n3 = max_(n1, n2);
	dp = (int **)malloc(sizeof(int *) * n1 + 1);
	par = (char *)malloc(sizeof(char) * n3);
	i = 0;
	while (i < n3)
	{
		par[i] = 0;
		i++;
	}
	i = 0;
	while (i <= n1)
	{
		dp[i] = (int *)malloc(sizeof(int) * n2 + 1);
		i++;
	}

	// for (i = 0; i <= n1; i++)
	// 	dp[i][0] = 0;
	// for (j = 0; j <= n2; j++)
	// 	dp[0][j] = 0;

	for (i = 0; i <= n1; ++i) {
		for (j = 0; j <= n2; ++j) {
			if (i == 0 || j == 0)
				dp[i][j] = 0;
			else if (str1[i] == str2[j])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max_(dp[i - 1][j], dp[i][j - 1]);
		}
	}

	k = 0;
	i = n1;
	j = n2;
	while (i > 0 && j > 0) {
		if (str1[i] == str2[j])
		{
			par[k] = dp[i][j];
			i--;
			j--;
			k++;
		} else if (dp[i - 1][j] == dp[i][j - 1])
			i--;
		else 
			j--;
		
	}

	i = k;
	while (i >= 0)
	{
		if (par[i] != 0)
			printf("%c ", par[i]);
		i--;
	}
	//printf("%d\n", dp[n1][n2]);


	return (0);
}