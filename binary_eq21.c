//https://stepik.org/lesson/311541/step/3?unit=293969
//find intersection point (any) of polynom and circle
//24th March 2020

# include <stdio.h>
# include <stdlib.h>
# include <math.h>


//find polynom value in a point
long double f(long *coeff, int n, long double x)
{
	if (n > 1)
		return (coeff[n] + x * f(coeff, n - 1, x));
	else if (n == 1)
		return coeff[0] * x + coeff[1];
	else  //if (n == 0)
		return coeff[0];
}

void binary_eq(int cx, int cy, int cd, int n, long *coeff, long double x)
{
	long double mid, left, right;
	long double eps = 1.0e-13l;
	long double tmp0, tmp1, tmp2, tmp, tmp_f;
	long double rad_2;
	long double res_left, res_right;

	rad_2 = cd * cd * 1.0l;
	tmp = 100000000.0l;
	left = (cx - cd - 10) * 1.0l;
	right = x;
	// printf("left = %LF\n", left);
	// printf("right = %LF\n", right);
	while (fabsl(tmp - rad_2) > eps)
	{
		mid = (left + right) / 2.0;

		tmp0 = pow(mid - cx, 2);
		tmp_f = f(coeff, n, mid);
	// printf("mid = %LF\n", mid);
	// printf("tmp_f = %LF\n", tmp_f);

		tmp1 = pow(tmp_f - cy, 2);
		tmp = tmp0 + tmp1;
	// printf("   tmp = %LF\n", tmp);
//	getchar();
		if (tmp > rad_2)
			left = mid;
		else
			right = mid;

	}
	printf("%.15Lf\n", right);
}


int main()
{
	int cx, cy, cd;
	int n, i;
	long *coeff;
	int x;
long double xx;

	scanf("%d %d %d %d", &cx, &cy, &cd, &n);
	coeff = (long *)malloc(sizeof(long) * n + 1);
	i = 0;
	while (i <= n)
	{
		scanf("%ld", coeff + i);
		i++;
	}
	scanf("%d", &x);
	xx = x* 1.0l;
	//printf("%Lf\n", f(coeff, n, -21.5l));

	binary_eq(cx, cy, cd, n, coeff, xx);

//	printf("%Lf\n", f(coeff, n, xx));



	return (0);
}