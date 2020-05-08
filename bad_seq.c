
//https://stepik.org/lesson/307326/step/9?unit=289414

//solution
//https://site.ada.edu.az/~medv/acm/Docs%20e-olimp/Volume%2014/1343.htm

#include <stdio.h>

int main()
{
	long n;
	long a1, a2, a3;
	long i;

	scanf("%ld", &n);
	if (n == 0)
	{
		printf("1\n");
		return (0);
	}

	if (n == 1)
	{
		printf("3\n");
		return (0);
	}
	if (n == 2)
	{
		printf("8\n");
		return (0);
	}
	i = 2;
	a1 = 3;
	a2 = 8;
	while (i < n)
	{
		a3 = 3 * a2 - a1;
		a1 = a2;
		a2 = a3;
		i++;
	}
	printf("%ld\n", a3);


	return (0);
}