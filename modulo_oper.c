//https://stepik.org/lesson/307322/step/5?unit=289410

#include <stdio.h>
#include <stdlib.h>


//find polynom value in a point
// long f(int *coeff, int n, long x, int M)
// {
// 	if (n > 1)
// 		return ((coeff[n] + x * f(coeff, n - 1, x, M)));
// 	else if (n == 1)
// 		return (coeff[0] * x + coeff[1]) % M;
// 	else  //if (n == 0)
// 		return coeff[0];
// }


// int main()
// {
// 	long x;
// 	long res;
// 	int n, i, M;
// 	int *coeff;
// 	long hh, hh1;
// 	int MAX = 2147483647;

// 	scanf("%d %d", &n, &M);
// 	coeff = (int *)malloc(sizeof(int) * n + 1);
// 	i = 0;
// 	while (i <= n)
// 	{
// 		scanf("%d", coeff + i);
// 		i++;
// 	}


// 	i = 0;
// 	while (i < M + 30)
// 	{
// 			// printf("HERE %d %ld\n",i, f(coeff, n, i));
// 		hh = f(coeff, n, i, M);
// 		hh1 = hh % M;
// 		if (hh1 < 0)
// 			hh1 += M;
// 		// printf("%d %10ld %4ld\n", i, hh, hh1);
// 		if (f(coeff, n, i, M) == 0)
// 		{
// 			printf("%d\n", i);
// 			free(coeff);
// 			return (0);
// 		}
// 		i++;
// 	}
// 	printf("-1\n");


// 	free(coeff);
// 	return (0);
// }



//polinom at point x.
//coeff is in descendning order
long f(long *coeff, long n, long x, long M)
{
	long i;
	long s, ord_x;

	if (n == 0)
		return (coeff[0]);
	else if (n == 1)
		return (coeff[1] * x + coeff[0]);
	s = coeff[n] % M;
	ord_x = 1;
	i = n - 1;
	while (i >= 0)
	{
		ord_x = ord_x * x % M;
		s = s + ord_x * coeff[i]; //% M;
		i--;
	}
	s = s % M;
	if (s < 0)
		s = s + M;
	return (s);
}

int main()
{
	long x;
	long res;
	long n, i, M;
	long *coeff;

	// scanf("%ld %ld", &n, &M);
	n = 35;
	M = 7;

	coeff = (long *)malloc(sizeof(long) * n + 1);
	i = 0;
	while (i <= n)
	{
		coeff[i] = 0;
		i++;
	}
	coeff[0] = 1;
	coeff[2] = 1;
	coeff[n] = 4;
	printf("%ld\n", f(coeff, n, 3, M));
	return(0);
	// while (i <= n)
	// {
	// 	scanf("%ld", coeff + i);
	// 	i++;
	// }
	x = 0l;
	while (x <= M)
	{
		if (f(coeff, n, x, M) == 0)
		{
			printf("%ld\n", x);
			free(coeff);
			return (0);
		}
		x++;
	}
	printf("-1\n");
	free(coeff);
	return 0;
}
