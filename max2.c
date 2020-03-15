//https://stepik.org/lesson/307317/step/4?unit=289405

#include <stdio.h>
#include <stdlib.h>

long mod = 1791791791;

long NextRand(long a, long b, long cur) {
    cur = (cur * a + b) % mod;
    return (cur);
}

int main()
{
	long a, b, cur, n;
	long *arr;
	long i;
	long pos1;
	long pos2;


	scanf("%ld", &n);
	scanf("%ld", &cur);
	scanf("%ld", &a);
	scanf("%ld", &b);


	arr = (long *)malloc(sizeof(long) * n + 1);
	// arr[0] = 2;
	// arr[3] = 10000;
	// arr[1] = 100;
	// arr[2] = 105;
	// arr[4] = 94;
	// arr[5] = 89;
	// arr[6] = 11;
	arr[0] = cur;
	i = 1;
	while (i <= n)
	{
		arr[i] = NextRand(a, b, arr[i - 1]);
		// printf("arr = %ld\n", arr[i]);
		i++;
	}


	if (n == 2)
	{
		if (arr[1] <= arr[2])
			printf("2 1\n");
		else
			printf("1 2\n");
		return (0);
	} 

	pos1 = 1;
	pos2 = 2;
	if (arr[2] > arr[1])
	{
		pos1 = 2;
		pos2 = 1;
	}
	i = 3;
	while (i <= n)
	{
		if (arr[i] > arr[pos1])
		{
			pos2 = pos1;
			pos1 = i;
		}
		else if (arr[i] > arr[pos2])
			pos2 = i;
		i++;
	}
	printf("%ld %ld\n", pos1, pos2);



	// printf("%ld\n", arr[1]);
	// printf("%ld\n", arr[3]);
	// printf("%ld\n", arr[4]);



//	printf("%ld\n", maxx_pos + 1);
	free(arr);
	return 0;
}