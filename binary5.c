//https://stepik.org/lesson/307318/step/7?unit=289406
//16 march 2020
#include <stdio.h>
#include <stdlib.h>


//returns first 1 occurence
int binary_search(int *a, int n, int x)
{
	int left = -1;
	int right = n;
	int mid;

	while (left + 1 < right)
	{
		mid = (left + right) / 2;
		if (a[mid] < x)
			left = mid;
		else if (a[mid] > x)
			right = mid;
		else
			return (mid);
	}
	return (right);
}

int main()
{
	int n, q;
	int *arr;
	int i, k;
	int x;
	int ind;


	scanf("%d %d", &n, &q);
	arr = (int *)malloc(sizeof(int) * n);
	i = 0;
	while (i < n)
	{
		scanf("%d", arr + i);
		i++;
	}
	k = 0;
	while (k < q)
	{
		scanf("%d", &x);
		if (x >= arr[n - 1])
		{
			printf("NO SOLUTION\n");
			k++;
			continue ;
		}
		ind = binary_search(arr, n, x);
		if (arr[ind] == x)
		{
			while (arr[ind] == x && ind < n)
				ind++;
			if (arr[ind] == x)
				printf("NO SOLUTION\n");
			else
				printf("%d\n", arr[ind]);
		}
		else
			printf("%d\n", arr[ind]);
		k++;
	}

	return (0);
}