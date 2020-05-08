//https://stepik.org/lesson/307322/step/3?unit=289410

# include <stdio.h>
# include <stdlib.h>
# include <math.h>

//remainder for addition
long rem_add(long a, long b, long m)
{
	long tmp;

	tmp = (a % m + b % m) % m;
	return (tmp);
}

//remainder for difference
long rem_diff(long a, long b, long m)
{
	long tmp;

	tmp = (a % m - b % m) % m;
	if (tmp < 0)
		tmp += m;
	return (tmp);
}

//remainder for product
long rem_prod(long a, long b, long m)
{
	long tmp;

	tmp = ((a % m) * (b % m)) % m;
	return (tmp);
}


int main()
{
	long n;
	long s;
	long i;
	long tmp;
	long m;
	long a, b;

	scanf("%ld %ld", &a, &b);
	m = 1000007;
	tmp = rem_prod(rem_add(a, b, m), rem_diff(a, b, m), m);
	printf("%ld\n", tmp);


	return (0);
}
