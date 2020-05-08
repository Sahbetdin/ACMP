//https://stepik.org/lesson/307320/step/3?unit=289408

#include <stdio.h>

int gcd(int a, int b)
{
    if (b == 0)
    	return a;
	return (gcd(b, a % b));
}


//кол-во итераций взятия остатка в алгоритме Евлкида
int main()
{
	int a, b, c;
	int d;


	scanf("%d %d %d", &a, &b, &c);
	d = gcd(a,b);
	if (c % d == 0)
		printf("1\n");
	else
		printf("0\n");
	return (0);
}















