//https://stepik.org/lesson/307320/step/4?unit=289408

#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b)
{
	if (b == 0)
		return a;
	return (gcd(b, a % b));
}


//кол-во итераций взятия остатка в алгоритме Евлкида
int main()
{
	int a, b, n, d;
	int *num;
	int i;

	scanf("%d", &n);
	num = (int *)malloc(sizeof(int) * n);
	i = 0;
	while (i < n)
	{
		scanf("%d", num + i);
		i++;
	}
	if (n == 1)
	{
		printf("%d\n", num[0]);
		free(num);
		return (0);
	}
	else if (n == 2)
	{
		printf("%d\n", gcd(num[0], num[1]));
		free(num);
		return (0);
	}

	d = gcd(num[0], num[1]);
	i = 2;
	while (i < n)
	{
		d = gcd(d, num[i]);
		i++;
	}
	printf("%d\n", d);
	free(num);
	return (0);
}















