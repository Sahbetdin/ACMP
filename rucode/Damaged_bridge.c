#include <stdio.h>
#include <stdlib.h>


int main()
{
	long max_, s;
	long n;
	long i;
	long *a;

	scanf("%ld", &max_);
	scanf("%ld", &n);
	a = (long *)malloc(sizeof(long) * n);
	i = 0;
	while (i < n)
	{
		scanf("%ld", a + i);
		i++;
	}
//nолько локом	
	s = a[0];
	if (s > max_ || n == 1)
	{
		printf("0\n");
		free(a);
		return (0);
	}

// 1 вагон
	s += a[1];
	if (s > max_)
	{
		printf("0\n");
		free(a);
		return (0);
	}
	else if (n == 2)
	{
		printf("1\n");
		free(a);
		return (0);
	}

// 2 вагон
	s += a[2];
	if (s > max_)
	{
		printf("1\n");
		// printf("HERE\n");
		free(a);
		return (0);
	}
	else if (n == 3)
	{
		printf("2\n");
		free(a);
		return (0);
	}

// 3 вагон
	s += a[3];
	if (s > max_)
	{
		printf("2\n");
		free(a);
		return (0);
	}
	else if (n == 4)
	{
		printf("3\n");
		free(a);
		return (0);
	}

	i = 4;
	// printf("MAX_ = %ld\n", max_);
	while (i < n)
	{
		s = a[i] + a[i - 1] + a[i - 2] + a[i - 3];
		// printf("s = %ld, i = %ld\n", s, i);
		if (s < max_)
		{
			// printf("HERE\n");
			i++;
		}
		else
		{
			// printf("NEY\n");
			break ;
		}
	}
	printf("%ld\n", i - 1);
	return (0);
}