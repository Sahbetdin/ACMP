//https://stepik.org/lesson/307326/step/8?unit=289414

//solution:
//http://www.problems.ru/view_problem_details_new.php?id=102778

#include <stdio.h>

int main()
{
	long n;
	long a1, a2, a3;
	long i;

	scanf("%ld", &n);
	if (n == 0)
	{
		printf("1\n");
		return (0);
	}

	if (n == 1)
	{
		printf("2\n");
		return (0);
	}
	if (n == 2)
	{
		printf("3\n");
		return (0);
	}
	i = 2;
	a1 = 2;
	a2 = 3;
	while (i < n)
	{
		a3 = a1 + a2;
		a1 = a2;
		a2 = a3;
		i++;
	}
	printf("%ld\n", a3);


	return (0);
}