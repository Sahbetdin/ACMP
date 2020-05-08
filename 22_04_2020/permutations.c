#include <stdio.h>
#include <stdlib.h>

void	swap(long *a, long *b)
{
	long c;
	c = *a;
	*a = *b;
	*b = c;
}

long	summ(long *a, long n)
{
	long i, s;

	i = 0;
	while (i < n)
	{
		s += a[i];
		i++;
	}
	return (s);
}

char is_norm(long a, long b, long k)
{
	long tmp;

	if (a > b)
		tmp = a - b;
	else
		tmp = b - a;
	
	if (tmp <= k)
		return 1;
	return 0;
}

void	print_arr(long *a, long n)
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

//берем в used
void	foo(long *arr, long *used, long n, long k, long pos)
{

	if (pos == n)
	{
		print_arr(arr, n);
		return ;
	}
	for (int i = 0; i < n; i++)
	{
		swap(arr + pos, arr + i);
		pos++;
		foo(arr, used, n, k, pos);

	}
}


int main()
{
	long n, k;
	long *arr, *used;
	long i;

	scanf("%ld %ld", &n, &k);
	arr = (long *)malloc(sizeof(long) * n);
	used = (long *)malloc(sizeof(long) * n);
	i = 0;
	while (i < n)
	{
		arr[i] = i + 1;
		used[i] = 0;
		i++;
	}
	foo(arr, used, n, k, 0);


	free(arr);
	free(used);
	return (0);
}