//https://stepik.org/lesson/307322/step/2?unit=289410

# include <stdio.h>
# include <stdlib.h>
# include <math.h>


long fib(long n)
{
	long i;
	long a1, a2, a3;

	if (n == 0 || n == 1)
		return (1);
	i = 1;
	a1 = 1;
	a2 = 1;
	while (i < n)
	{
		//0 1 2 3 4 5  6  7  8  9
		//1 1 2 3 5 8 13 21 34 55
		a3 = a1 + a2;
		a3 = a3 % 1000003l;
		a1 = a2;
		a2 = a3;
		i++;
	}
	return (a3);
}

int main()
{
	long n;
	long s;
	long i;
	long tmp;

	scanf("%ld", &n);
	tmp = fib(n);
	printf("%ld\n", tmp);


	return (0);
}
