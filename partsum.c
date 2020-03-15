https://stepik.org/lesson/307317/step/6?unit=289405
#include <stdio.h>
#include <stdlib.h>

int main()
{
	long n, q;
	long *arr;
    long *partsum;
	long i;
	long left, right;


	scanf("%ld %ld", &n, &q);



	arr = (long *)malloc(sizeof(long) * n + 1);
	arr[0] = 0;
	i = 1;
	while (i <= n)
	{
		scanf("%ld", arr + i);
		i++;
	}

	i = 1;

	partsum = (long *)malloc(sizeof(long) * n + 1);
    partsum[0] = 0;
    partsum[1] = arr[1];
    i = 2;
    while(i <= n)
    {
        partsum[i] = partsum[i - 1] + arr[i];
        i++;
    }
	i = 1;
	// while (i <= n)
	// {
	// 	printf("%ld ", partsum[i]);
	// 	i++;
	// }
	while (i <= q)
	{
		scanf("%ld %ld", &left, &right);
		printf("%ld", partsum[right] - partsum[left - 1]);
		i++;
	}


	free(arr);
    free(partsum);
	return 0;
}