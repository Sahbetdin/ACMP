//https://stepik.org/lesson/307322/step/4?unit=289410

# include <stdio.h>
# include <stdlib.h>

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
	long m;
	long i;
	long tmp;

	scanf("%ld", &n);
	m = 1000003;
	i = 2;
	tmp = 1;
	while (i <= n)
	{
		tmp = rem_prod(tmp, i, m);
		i++;
	}

	printf("%ld\n", tmp);
	return (0);
}







