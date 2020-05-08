//https://stepik.org/lesson/311541/step/2?unit=293969

//find polynom value in a point
# include <stdio.h>
# include <stdlib.h>
# define ABS(x) ((x < 0) ? -x : x)

long double f(int *coeff, int n, long double x)
{
	if (n > 1)
		return (coeff[n] + x * f(coeff, n - 1, x));
	return coeff[0] * x + coeff[1];
}

long double binary_eq(int *coeff, int n, long double x)
{
	long double left, right;
	long double mid;
	long double bound = 50.0l;
	long double eps = 1.0e-7;
	long double tmp;

	left = -bound;
	right = bound;
	tmp = 1.0L;
	while (ABS(tmp) > eps)
	{
		mid = (left + right) / 2;
		tmp = f(coeff, n, mid);
		// printf("tmp = %Lf\n", tmp);
		if (tmp < 0)
			left = mid;
		else
			right = mid;
	}
	return (right);
}

int main()
{
	long double x;
	long double res;
	int n, i;
	int *coeff;

	scanf("%d", &n);
	coeff = (int *)malloc(sizeof(int) * n + 1);
	i = 0;
	while (i <= n)
	{
		scanf("%d", coeff + i);
		i++;
	}
	res = binary_eq(coeff, n, x);
	printf("%5.16Lf\n", res);
	free(coeff);
	return (0);
}