#include <stdio.h>
#include <stdlib.h>

long difference(long *arr, long *used, long n)
{
	long j;
	long diff;

	j = -1;
	diff = 0;
	while (++j < n)
	{
		if (used[j] == 1)
			diff += arr[j];
		else
			diff -= arr[j];
	}
	if (diff < 0)
		diff = -diff;
	return (diff);
}
void	print_used(long *a, long n)
{
	long i;

	i = 0;
	while (i < n)
	{
		printf("%ld ", a[i]);
		i++;
	}
	printf("\n");
}

void	boo(long *arr, long *used, long n, long pos, long *addr_d)
{
	long tmp;

	if (pos == n)
	{
		// print_used(used, n);
		tmp = difference(arr, used, n);
		if (tmp < *addr_d)
			*addr_d = tmp;
		return ;
	}
	boo(arr, used, n, pos + 1, addr_d);

	used[pos] = 1;
	boo(arr, used, n, pos + 1, addr_d);
	used[pos] = 0;
}


int main()
{
	long i, n, *arr, *used;
	long diff;
	
	scanf("%ld", &n);
	arr = (long *)malloc(sizeof(long) * n);
	used = (long *)malloc(sizeof(long) * n);
	i = -1;
	while (++i < n)
	{
		scanf("%ld", arr + i);
		used[i] = 0;
	}
	diff = difference(arr,used, n);
	boo(arr, used, n, 0, &diff);
	printf("%ld\n", diff);


	free(arr);
	free(used);
	return (0);
}