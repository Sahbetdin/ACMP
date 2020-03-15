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
	arr[0] = cur;
	i = 1;
	while (i <= n)
	{
		arr[i] = NextRand(a, b, arr[i - 1]);
		printf("arr = %ld\n", arr[i]);
		i++;
	}

	if (n == 2)
	{
		if (arr[1] <= arr[2])
			printf("1 2");
		else
			printf("2 1");
		return (0);
	} 

	pos1 = 1;
	pos2 = 2;
	i = 3;
	while (i <= n)
	{
		
		i++;
	}



	// printf("%ld\n", arr[1]);
	// printf("%ld\n", arr[3]);
	// printf("%ld\n", arr[4]);



//	printf("%ld\n", maxx_pos + 1);
	free(arr);
	return 0;
}