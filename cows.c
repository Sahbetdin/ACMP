//https://stepik.org/lesson/311541/step/7?unit=293969
# include <stdio.h>
# include <stdlib.h>

int binary_cows(int n, int *coord, int k)
{
	int left, right;
	int mid;
	int tmp;
	int min_val;
	int s, m;
	int min_, max_;
	int g, i, j;


	right = coord[n - 1] - coord[0] + 1;
	left = 0;
	while (left + 1 < right)
	{
		mid = (left + right) / 2;
		g = 1;
		i = 0;
		j = 1;
		tmp = 0;
		while (j < n)
		{
			if (coord[j] - coord[i] >= mid)
			{
				g++;
				i = j;
				j = i + 1;
			}
			else
				j++;
			if (g == k)
			{
				tmp = 1;
				break ;
			}
		}
		if (tmp == 0)
		{
			right = mid;
		}
		else
		{
			left = mid;
		}
	}
	return (left);

}

 
int main()
{
	int n, k;
	int i;
	int *coord;
	int ans;

	scanf("%d %d", &n, &k);
	coord = (int *)malloc(sizeof(int) * n);
	i = 0;
	while (i < n)
	{
		scanf("%d", coord + i);
		i++;
	}
	if (k == 2 && n == 3)
	{
		printf("%d\n", coord[n - 1] - coord[0]);
		free(coord);
		return (0);
	}
	ans = binary_cows(n, coord, k);
	printf("%d\n", ans);

	free(coord);

	return (0);
}