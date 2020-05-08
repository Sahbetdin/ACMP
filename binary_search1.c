
//https://stepik.org/lesson/307318/step/2?unit=289406

//16-March-2020
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// const MAXN = 100500;
// int n;
// int a[MAXN];

int main()
{
	int n, m;
	int k;
	int iter_res;
	int i, j;
	int prod;
	int max_;

	scanf("%d %d", &n, &m);
	k = 1;
	max_ = log2(n * 1.0);
	printf("%d\n", max_);

return (0);
	while (k <= m)
	{
		scanf("%d", &iter_res);
		printf("%f\n", log2(iter_res));

		// i = 1;
		// prod = 2;
		// while (prod < iter_res)
		// {
		// 	prod = prod * 2;
		// 	i++;
		// }
		printf("%d\n", i);
		k++;
	}
	return (0);

}