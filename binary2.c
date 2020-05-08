//https://stepik.org/lesson/307318/step/3?unit=289406
#include <stdio.h>
#include <stdlib.h>


int main()
{
	int n, q;
	int left, right, mid;
	int k;
	int a_mid;

	scanf("%d %d", &n, &q);

	k = 0;
	left = -1;
	right = n;
	while (k < q)
	{
		scanf("%d", &a_mid);
		mid = (left + right) / 2;
		if (a_mid == 1)
			right = mid;
		else
			left = mid;
		k++;
	}
	printf("%d\n", right);


	return (0);
}