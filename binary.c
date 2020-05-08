
//https://stepik.org/lesson/307318/step/2?unit=289406
//16-March-2020
#include <stdio.h>
#include <stdlib.h>
//#include <math.h>



//returns first 1 occurence
//n = amount of elements
//k = current infex from which we start 1-s.
int binary_iter_count(int n, int k)
{
	int left;
	int right = n;
	int mid;
	int count;

	count = 0;
	left = -1;
	right = n;
	while (left + 1 < right)
	{
	// printf("HERE\n");
		mid = (left + right) / 2;
		count++;
		if (k > mid)
			left = mid;
		else
			right = mid;
		// printf("left = %d, right = %d\n", left, right);
	}
	// return (right);
	return (count);
}

// void zerofy(int *a, int MAXN)
// {
// 	int i;

// 	i = 0;
// 	while (i < MAXN)
// 	{
// 		if (a[i] != 0)
// 			a[i] = 0;
// 		i++;
// 	}
// }


// void print_arr(int *a)
// {
// 	int i;

// 	i = 0;
// 	while (i < 10)
// 	{
// 		printf("%d ", a[i]);
// 		i++;
// 	}
// }

int main()
{
	int MAXN = 100500;
	int n;
	int a[MAXN];

	int m;
	int k;
	int cur;
	int i;
	int tmp;

	scanf("%d %d", &n, &m);
	k = 0;
	while (k < m)
	{
		// zerofy(a, MAXN);
		scanf("%d", &cur);
		// tmp = log2(cur);
		// if (cur == n / 2)
		// 	printf("%  d\n", tmp);
		// else if (pow(2, tmp) == cur)
		// 	printf("%  d\n", tmp);


		// i = cur;

		// while (i < MAXN)
		// {
		// 	a[i] = 1;
		// 	i++;
		// }
		// // print_arr();
		tmp = binary_iter_count(n, cur);
		printf("%    d\n", tmp);
		// getchar();
		k++;
	}

	return (0);
}










