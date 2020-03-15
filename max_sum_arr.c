//https://stepik.org/lesson/307317/step/7?unit=289405

#include <stdio.h>
#include <stdlib.h>

long give_max(long a, long b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

int main()
{
	long n;
	long *arr;
	long max_neg;
	long i;
	long if_pos;
	long s;
	long ans;
	long j;
	max_neg = -1000000000;


	scanf("%ld", &n);
	if (n == 0)
	{
		printf("0\n");
		return 0;
	}

	arr = (long *)malloc(sizeof(long) * n + 1);
	arr[0] = 0;
	i = 1;
	while (i <= n)
	{
		scanf("%ld", arr + i);
		i++;
	}

	// i = 1;
	// while (i <= n)
	// {
	// 	printf(" %ld ", arr[i]);
	// 	i++;
	// }
	if_pos = 0;

	i = 1;
	s = 0;
	ans = 0;
	while (i <= n)
	{
		s += arr[i];
		if (arr[i] > 0 && if_pos == 0)
			if_pos = 1;
		if (arr[i] < 0 && arr[i] > max_neg)
			max_neg = arr[i];
		if (s < 0)
			s = 0;
		ans = give_max(ans, s);
		// printf("s = %ld\n", s);
		i++;
	}

	if (if_pos == 1)
		printf("%ld\n", ans);		
	else
		printf("%ld\n", max_neg);



	free(arr);
	return 0;
}