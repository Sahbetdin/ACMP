//12th Dec 2019

#include <stdio.h>

int IsPrime(int n)
{
	int i, k;
	if (n == 2 || n == 3)
		return (n);
	i = 2;
	while (i < 40 && i < n)
	{
		if (n % i == 0)
			return (0);
		i++;
	}
	return (n);
}

int main()
{
	int a, b, c, s;

	scanf("%d", &a);
	scanf("%d", &b);
	scanf("%d", &c);

	s = 0;
	if (IsPrime(a) == a)
		s += a;
	if (IsPrime(b) == b)
		s += b;
	if (IsPrime(c) == c)
		s += c;

	printf("%d\n", s);
	if (IsPrime(s))
		printf("YES\n");
	else
		printf("NO\n");

	return (0);
}