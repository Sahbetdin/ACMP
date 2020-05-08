//https://stepik.org/lesson/307326/step/4?unit=289414

#include <stdio.h>
#include <stdlib.h>

long min1(long a, long b)
{
	if (a > b)
		return (b);
	return (a);
}

void swap(long *a, long *b)
{
	long tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

long min2(long a, long b, long c)
{
	long m;

	if (a < b)
		swap(&a, &b);
	if (b < c)
		swap(&b, &c);
	return (c);
}


int main()
{
	long	i, n;
	long	*x;
	long	max_ = 1000500;


	scanf("%ld", &n);
	if (n == 1)
		printf("0\n");
	else if (n == 2 || n == 3)
		printf("1\n");
	if (n == 1 || n == 2 || n == 3)
		return (0);

	x = (long *)malloc(sizeof(long) * (n + 1));

	while (i <= n)
	{
		x[i] = max_;
		i++;
	}

	x[1] = 0;
	x[2] = 1;
	x[3] = 1;
	i = 4;
	while (i <= n)
	{
		if (i % 6 == 0)
			x[i] = min2(x[i - 1], x[i / 3], x[i / 2]) + 1;
		else if (i % 3 == 0)
			x[i] = min1(x[i - 1], x[i / 3]) + 1;
		else if (i % 2 == 0)
			x[i] = min1(x[i - 1], x[i / 2]) + 1;
		else
			x[i] = x[i - 1] + 1;
		i++;
	}
	printf("%ld\n", x[n]);
	free(x);
	return (0);
}
