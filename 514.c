#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i, n;
	int *a;


	FILE* file = fopen("input.txt", "r");
	fscanf(file, "%d", &n);

	i = 1;
	if (n == 1)
	{
		printf("%d\n", 1);
		return (0);
	}

	while (1)
	{
		if (n < i)
			break ;
		n = n - i;
		i++;
	}
	printf("%d\n", i - 1);


	return (0);
}