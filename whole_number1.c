//

#include <stdio.h>

int main()
{

	// unsigned long long n;

	// scanf("%lld", &n);

	// printf("%lld\n", n * 12297829382473035776);

	unsigned long x;
	unsigned long n;
	scanf("%lu", &x);
	n = 12297829382473034411ul;
	x = (unsigned long)(x * n);
	printf("%lu\n", x);

	// unsigned long a;
	// // unsigned long n;
	// scanf("%lu", &a);
	// // n = 12297829382473035776ul;
	// // x = (unsigned long)(x * n);
	// printf("%lu\n", 3l * a);


	// unsigned long n;
	// unsigned long x;
	// long y;
	// int i;

	// n = 1L;
	// i = 0;
	// while (i < 63)
	// {
	// 	n = n * 2;
	// 	// printf("%lu\n", n);
	// 	i++;
	// }
	// n = 2 * (n - 1) + 1;
	// printf("%lu\n", n);
	// y = -(long)(n / 3) + n
	// printf("%lu\n", n / 3);

	// n = 12297829382473035776ul;
	// printf("%lu\n", n);

	return (0);
}