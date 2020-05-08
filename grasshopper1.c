//https://stepik.org/lesson/307326/step/2?unit=289414

#include <stdio.h>
#include <stdlib.h>


long max(long a, long b)
{
	if (a > b)
		return (a);
	return (b);
}


int main()
{
	long i, n, a;
	long *x;
	long s, s_prev, s_prev_prev;

	scanf("%ld", &n);

	s_prev = 0;
	scanf("%ld", &s);

	i = 2;
	while (i <= n)
	{
		scanf("%ld", &a);
		s_prev_prev = s_prev;
		s_prev = s;
		s = max(s_prev, s_prev_prev) + a;
		i++;
	}
	printf("%ld\n", s);

	return (0);
}
