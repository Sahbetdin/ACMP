#include <stdio.h>
#include <unistd.h>

void	print_memory(int *s, int n)
{
	int i;
	char u;

	i = 0;
	while (i < 20)
	{
		u = (char )(s[i] + 48);
		write(1, &u, 1);
		i++;

	}
	write(1, "\n", 1);
}

void multiply_arithmetic(int *s, int n, int b)
{
	int i;
	int j;
	int dig;
	
	i = n - 1;
	while (i >= 0)
	{
		s[i] *= b;
		j = i;
		while (s[j] > 9)
		{
			dig = s[j] / 10;
			s[j] -= 10 * dig;
			s[j + 1] += dig;
			j++;
		}
		i--;		
	}
}

void print_fin(int *s, int n)
{
	int i;
	char u;

	i = n - 1;
	while (i && s[i] == 0)
		i--;
	while (i >= 0)
	{
		u = (char )(s[i] + 48);
		write(1, &u, 1);
		i--;
	}
	write(1, "\n", 1);
}


int main()
{
	int i, j, k, n, m;
	int a[2600];

	n = 2600;
	FILE* file = fopen("input.txt", "r");
	fscanf(file, "%d", &m);
	

	if (m == 0)
		printf("1");
	else if (m == 1)
		printf("2");
	else if (m == 2)
		printf("4");
	else if (m == 3)
		printf("8");
	else if (m >= 4)
	{
		i = -1;
		while (++i < n)
			a[i] = 0;
		a[0] = 6;
		a[1] = 1;
		j = 4;
		while (j < m)
		{
			multiply_arithmetic(a, n, 2);
			// print_memory(a, n);
			j++;			
		}
		print_fin(a, n);
	}
	fclose(file);
	return (0);
}