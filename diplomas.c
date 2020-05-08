//https://stepik.org/lesson/311541/step/5?unit=293969


# include <stdio.h>
# include <stdlib.h>
# include <math.h>

long max(long a, long b)
{
	if (a > b)
		return (a);
	return (b);
}



long diplomas_numb(long w, long h, long x)
{
	return ((x / w) * (x / h));
}

long binary_dipl(long w, long h, long n)
{
	long left = 0; //сторона
	long right = max(w, h) * n; //сторона
	long mid;
	long tmp;

	while (left + 1 < right)
	{
		mid = (left + right) / 2;
		tmp = diplomas_numb(w, h, mid);
		// printf("left = %ld, right =  %ld\n", left, right);
		// printf("       %ld %ld\n", mid, tmp);
		// getchar();

		if (tmp > n)
			right = mid;
		else
			left = mid;
	}
	return (right);
}

int main()
{
	long w, h, n;
	long ans;

	scanf("%ld %ld %ld", &w, &h, &n);
	ans = binary_dipl(w, h, n);
	printf("%ld\n", ans);

	return (0);
}