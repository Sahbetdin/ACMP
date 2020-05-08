//https://stepik.org/lesson/307320/step/2?unit=289408


#include <stdio.h>

int gcd(int a, int b, int *c)
{
    if (b == 0)
    	return a;
	(*c)++;
	return (gcd(b, a % b, c));
}


//кол-во итераций взятия остатка в алгоритме Евлкида
int main()
{
	int a, b;
	int count;

	scanf("%d %d", &a, &b);
	count = 0;
	gcd(a,b, &count);
	printf("%d\n", count);
	return (0);
}
