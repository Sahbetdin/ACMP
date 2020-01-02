//13th dec 2019
//wrong answer on 1st test.
//переписал на питоне.
//https://acmp.ru/index.asp?main=task&id_task=9

#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
	int c;
	c = *a;
	*a = *b;
	*b = c;
}

int main()
{
	int i, n;
	int *a;
	int s, pr;
	int j, k;
	int tmp;


	FILE* file = fopen("input.txt", "r");
	fscanf(file, "%d", &n);
	a = (int *)malloc(sizeof(int) * n);
	i = -1;
	while (++i < n)
		fscanf(file, "%d", &a[i]);
	fclose(file);

	i = 0;
	s = 0;
	while (i < n)
	{
		if (a[i] > 0)
			s += a[i];
		i++;
	}
	//min
	tmp = a[0];
	i = 1;
	while (i < n)
	{
		if (a[i] < tmp)
		{
			tmp = a[i];
			j = i;
		}
		i++;
	}
	//max
	tmp = a[0];
	i = 1;
	while (i < n)
	{
		if (a[i] > tmp)
		{
			tmp = a[i];
			k = i;
		}
		i++;
	}
	if (k < j)
		swap(&k, &j);
//	printf("%d %d\n", j, k);
	pr = 1;
	j++;
	while (j < k)
	{
		pr *= a[j];
		j++;
	}

	printf("%d %d\n", s, pr);
	free(a);
	return (0);
}