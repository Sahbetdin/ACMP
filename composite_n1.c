//https://stepik.org/lesson/307321/step/5?unit=289409

# include <stdio.h>
# include <stdlib.h>
# include <math.h>



long my_is_prime_return_factor(long n)
{
	long lim;
	long i;

	if (n == 1)
		return (0);
	if (n == 2 || n == 3 || n == 5 || n == 7 || n == 11)
		return (0);
	if (n % 2 == 0)
		return (2);
	if (n % 3 == 0)
		return (3);

	i = 3;
	lim = (int)(sqrt(n) + 2.0);
	// printf("lim = %d\n", lim);
	while (i < lim)
	{
		if (n % i == 0)
			return (i);			
		i += 2;
	}
	return (0);
}


int main()
{
	long n;
	long s;
	long i;
	long tmp;

	scanf("%ld", &n);
	s = 0;
	i = 4;
	while (i <= n)
	{
		if (i % 2 == 0)
		{
			// printf("YES i = %ld\n", i);
			s += 2;
		}
		else
		{
			tmp = my_is_prime_return_factor(i);
			// printf("NO i = %ld, tmp: %ld\n", i, tmp);
			s += tmp;
		}
		i++;
	}
	printf("%ld\n", s);


	return (0);
}









