
#include <stdio.h>
#include <stdlib.h>


long max1(long a, long b)
{
	if (a > b)
		return (a);
	return (b);
}

void swap(long *a, long *b)
{
	long tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

long max2(long a, long b, long c)
{
	long m;

	if (a > b)
		swap(&a, &b);
	if (b > c)
		swap(&b, &c);
	return (c);
}

int main()
{
	long i, n;
	long *x;
	long *s;


	// long a, b, c;

	// a = 300;
	// b = 51;
	// c = 300;
	// printf("%ld\n", max2(a,b,c));
	// return (0);

	scanf("%ld", &n);
	x = (long *)malloc(sizeof(long) * n);
	s = (long *)malloc(sizeof(long) * n);

	scanf("%ld", x); //x[0]
	s[0] = x[0];

	if (n > 1) //e.g. n == 2
	{
		scanf("%ld", x + 1); //x[1]
		s[1] = s[0] + x[1];
	}
	if (n > 2) //e.g. n = 3 
 	{
		scanf("%ld", x + 2); //x[2]
		s[2] = max1(0, s[1]) + x[2];
	}
	if (n > 3) //e.g. n = 4
	{
		scanf("%ld", x + 3); //x[3]
		s[3] = max1(s[2], s[0]) + x[3];
	}
	if (n > 4)
	{
		scanf("%ld", x + 4); //x[4]
		s[4] = max2(0, s[1], s[3]) + x[4];
	}

	i = 5;
	while (i < n)
	{
		scanf("%ld", x + i); //x[i]
		s[i] = max2(s[i - 1], s[i - 3], s[i - 5]) + x[i];
		i++;
	}
	printf("%ld\n", s[n - 1]);

	free(x);
	free(s);
	return (0);
}