//https://stepik.org/lesson/307324/step/2?unit=289412

#include <stdio.h>
#include <stdlib.h>


long fast_pow(long a, long n, long mod)
{
	if (n == 0L)
		return (1L);
	else if (n % 2 == 1)
		return (a * fast_pow(a, n - 1, mod)) % mod;
	long tmp = fast_pow(a, n / 2, mod);
	return (tmp * tmp) % mod;
}

int main()
{
	long n, m;
	long i, prod;


	scanf("%ld %ld", &n, &m);
	prod = fast_pow(n, n, m);
	printf("%ld\n", prod);



	return (0);
}

//https://stepik.org/lesson/307324/step/3?unit=289412
// int main()
// {
// 	int a, b, c, d;

// 	scanf("%d %d %d %d", &a, &b, &c, &d);



// 	return (0);
// }


















