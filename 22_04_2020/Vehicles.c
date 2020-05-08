#include <stdio.h>

long s = 0;

void	foo(long n, long k)
{
	long tmp;

	if (n <= k)
	{
		s++;
		return ;
	}
	tmp = n / 2; 
	foo(tmp, k);
	foo(n - tmp, k);
}


int main()
{
    long n, k;

    scanf("%ld %ld", &n, &k);
	foo(n, k);
	printf("%ld\n", s);

    return (0);
}