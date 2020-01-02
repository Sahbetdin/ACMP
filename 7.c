#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

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

int	ft_strcmp(const char *s1, const char *s2)
{
	int i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	if (s1[i] != s2[i])
		return (int)((unsigned char)s1[i] - (unsigned char)s2[i]);
	else
		return (0);
}


char *compare(char *s1, char *s2)
{
	int i;
	int a;
	int b;

	a = ft_strlen(s1);
	b = ft_strlen(s2);
	if (a > b)
		return (s1);
	else if (b > a)
		return (s2);
	else
	{
		if (ft_strcmp(s1, s2) > 0)
			return (s1);
		else
			return (s2);
	}
}

int main()
{
	int i, a, b, c, max;
	char str1[150];
	char str2[150];
	char str3[150];
	char *max_s;
	char buf[1];
	int fd;
	int ret;

	scanf("%s", str1);
	scanf("%s", str2);
	scanf("%s", str3);
	a = 0;
	while (str1[a] && str1[a] == 48)
		a++;

	b = 0;
	while (str2[b] && str2[b] == 48)
		b++;

	c = 0;
	while (str3[c] && str3[c] == 48)
		c++;

	max_s = compare(str1 + a, str2 + b);
	max_s = compare(max_s, str3 + c);
	ft_putstr(max_s);
	
	return (0);
}