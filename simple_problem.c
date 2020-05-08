//https://stepik.org/lesson/311541/step/6?unit=293969

# include <stdio.h>
# include <stdlib.h>


long min(long a, long b)
{
	if (a > b)
		return (b);
	return (a);
}

long max(long a, long b)
{
	if (a > b)
		return (a);
	return (b);
}


long binary_simple_problem(long n, long x, long y)
{
	long left = 0, right;
	long mid;
	long tmp;
	long min_val;
	long s, m;
	long min_, max_;

	min_ = min(x, y);
	max_ = max(x, y);
	s = min_;
	// printf("s = %ld\n", s);

	m = n - 1;

	right = m * min_;
	// printf("right = %ld\n", right);

	while (left + 1 < right)
	{
		mid = (left + right) / 2;
		// printf("mid = %ld ", mid);

		 //amount of copies in time mid;
		tmp = mid / min_ + mid / max_;
		// printf("tmp = %ld ", tmp);
		if (tmp >= m)
		{
			// printf("ASSIGNED R\n");
			right = mid;
		}
		else
		{
			// printf("ASSIGNED L\n");
			left = mid;
		}
	}
	return (right + s);
}

/*
есть x, y, n.
время работы для a, b листов:
a + b = n;
ax + by = min

a * x + y * (n-a) = min
a * x - y * a + y * n = min
a(x - y) + y * n = min > 0;
a_left = 0; res_left = y * n
a_right = n; res_right = n * x


4 1 1

*/
 
int main()
{
	long n, x, y;
	long ans;
	long both_time;

	scanf("%ld %ld %ld", &n, &x, &y);
	if (x == y)
	{
		n = n - 1; //copied first one
		both_time = n / x * x * 2;
		// printf("both work time = %ld\n",  n / 2 * x);
		// printf(" one work time = %ld\n",  n % 2 * x);

		ans = n / 2 * x + n % 2 * x;
		printf("%ld\n", ans + x);
		// ans = ans + x; //added time for first one
		// printf("%ld\n", ans);
		return (0);
	}
	ans = binary_simple_problem(n, x, y);
	printf("%ld\n", ans);

	return (0);
}