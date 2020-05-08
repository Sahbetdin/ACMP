#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char prime(int n)
{
	int q = 49;
	int dev = 3;

	while (dev < n)
	{
		if (n % dev == 0)
			return (0);
		dev += 2;
	}
	return (1);
}

int main()
{
	int n;

	n = 10;
	while (n < 100)
	{
		if (n % 7 == 0)
			printf("n = %d\n", n);
		n += 2;
	}

	return (0);
}