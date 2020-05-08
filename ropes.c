//https://stepik.org/lesson/311541/step/8?unit=293969
# include <stdio.h>
# include <stdlib.h>

int max(int n, int *x)
{
	int i;
	int max_;

	max_ = x[0];
	i = 1;
	while (i < n)
	{
		if (x[i] > max_)
			max_ = x[i];
		i++;
	}
	return (max_);
}



int binary_ropes(int n, int *x, int k)
{
	int left, right;
	int mid;
	int tmp, tmp_prev;
	int i, s;

	left = 0;
	i = 0;
	right = max(n, x) + 10;

	// printf("%d\n", right + 10);
	if (right == k)
		return (1);
	tmp = 0;
	while (left + 1 < right)
	{
		mid = (left + right) / 2; // длина всех веревок
		// printf("mid = %d ", mid);
		s = 0; //количество веревок 
		i = 0;
		while (i < n)
		{
			s += x[i] / mid; //кол-во кусков веревок из всех веревок
			i++;
		}
		// printf("s = %d \n", s);

		if (s >= k)
			left = mid;
		else
			right = mid;
		// printf("left = %d, right = %d\n ", left, right);
		// printf("~~~~~~~~~~~~~~~\n");

	}
	return (left);
}

 
int main()
{
	int n, k;
	int i;
	int *x;
	int ans;

	scanf("%d %d", &n, &k);
	x = (int *)malloc(sizeof(int) * n);
	i = 0;
	while (i < n)
	{
		scanf("%d", x + i);
		i++;
	}
	ans = binary_ropes(n, x, k);
	printf("%d\n", ans);

	free(x);
	return (0);
}