#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n;

	scanf("%d", &n);
	if (n == 1)
		printf("%d %d\n", 2, 9);
	else if (n == 8)
		printf("%d %d\n", 7, 16);
	else if (n == 57)
		printf("%d %d\n", 49, 58);
	else if (n == 64)
		printf("%d %d\n", 56, 63);
	else if (n % 8 == 0)
		printf("%d %d %d\n", n - 8, n - 1, n + 8);
	else if (n % 8 == 1)
		printf("%d %d %d\n", n - 8, n + 1, n + 8);
	else if (n > 1 && n < 8)
		printf("%d %d %d\n", n - 1, n + 1, n + 8);
	else if (n > 57 && n < 64)
		printf("%d %d %d\n", n - 8, n - 1, n + 1);
	else
		printf("%d %d %d %d\n", n - 8, n - 1, n + 1, n + 8);

	return (0);
}