//https://stepik.org/lesson/307318/step/9?unit=289406

#include <stdio.h>
#include <stdlib.h>


//returns first 1 occurence
int binary_search_descend(int *a, int n, int x)
{
	int left = -1;
	int right = n;
	int mid;

	while (left + 1 < right)
	{
		mid = (left + right) / 2;
		if (a[mid] > x)
			left = mid;
		else if (a[mid] < x)
			right = mid;
		else
			return (mid);

		// printf("left = %d, right = %d\n", left, right);
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
	int flag;


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
		if (x < arr[n - 1])
		{
			printf("NO SOLUTION\n");
			k++;
			continue ;
		}
		ind = binary_search_descend(arr, n, x);
		flag = 0;
		if (arr[ind] == x)
		{
			while (ind >= 0 && arr[ind] == arr[ind - 1])
			{
				// printf("HERE\n");
				ind--;
				// flag = 1;
			}
			if (ind == 0)
				printf("%d\n", 1);
			// else if (flag == 1)
				// printf("%d\n", ind + 1);
			else // if (flag == 0)
				printf("%d\n", ind + 1);

			k++;
			continue ;
		}
		printf("%d\n", ind + 1);
		k++;
	}

	return (0);
}