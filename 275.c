#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_putstr(char const *s)
{

	if (s)
		write(1, s, ft_strlen(s));
}

int main()
{
	int i, n;
	int *a;
	char s[3000];
	int sum;


	FILE* file = fopen("input.txt", "r");
	fscanf(file, "%s", s);
	n = ft_strlen(s);
	i = 0;
	sum = 0;
	while (i < n)
	{
		if (s[i] == '1')
			
		i++;
	}

	

	fclose(file);
	return (0);
}