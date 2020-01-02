#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	int i, j, n;
	char str[6];
	char buf[1];
	int fd;
	int ret;
	int k;

	i = 0;
	while ((ret = read(0, buf, 1)) && i < 6)
	{
		str[i] = buf[0];
		i++;
	}
	str[5] = '\0';
	i = 0;
	if (!(str[0] >= 'A' && str[0] <= 'H'))
	{
		printf("ERROR\n");
		return (0);
	}
	if (!(str[3] >= 'A' && str[3] <= 'H'))
	{
		printf("ERROR\n");
		return (0);
	}
	if (!(str[1] >= '1' && str[1] <= '8'))
	{
		printf("ERROR\n");
		return (0);
	}
	if (!(str[4] >= '1' && str[4] <= '8'))
	{
		printf("ERROR\n");
		return (0);
	}
	if (str[2] != '-')
	{
		printf("ERROR\n");
		return (0);
	}



		if (str[1] )
	else
	


	return (0);
}