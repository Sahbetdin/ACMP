//https://stepik.org/lesson/307320/step/5?unit=289408

#include <stdio.h>
#include <stdlib.h>

//a > b
//НОК(a, b)=a : НОД(a, b) * b

long gcd(long a, long b)
{
	if (b == 0)
		return a;
	return (gcd(b, a % b));
}

long max(long a, long b)
{
	if (a > b)
		return (a);
	return (b);
}

long min(long a, long b)
{
	if (a < b)
		return (a);
	return (b);
}


//кол-во итераций взятия остатка в алгоритме Евлкида
int main()
{
	long a, b, d, tmp;
	long maxx = 1000000000000000000;

	scanf("%ld %ld", &a, &b);
	d = gcd(a, b);

	tmp = max(a,b) / gcd(a,b);
	if (tmp > maxx)
	{
		printf("1\n");
		return (0);
	}
	if (maxx / min(a,b) < tmp)
	{
		printf("-1\n");
	}
	else
	{
		printf("%ld\n", tmp * min(a,b));
	}



	return (0);
}
