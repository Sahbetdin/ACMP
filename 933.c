#include <stdio.h>

int main()
{
	int i, n;
	int a, b, c, t;
  	int s;

	scanf("%d", &a);
	scanf("%d", &b);
	scanf("%d", &c);
	scanf("%d", &t);
	
	if (t > a)
      	s = a * b + (t - a) * c;
	else
		s = a * b;
	printf("%d\n", s);

	return (0);
}