#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
	int i, j, n;
	char str[2601];
	char buf[1];
	int fd;
	int ret;
	int flag;
	int k;

	i = 0;
	fd = open("input.txt", O_RDONLY);
	while ((ret = read(fd, buf, 1)))
	{
		str[i] = buf[0];
		i++;
	}
	str[i] = '\0';
	close(fd);

	i = 0;
	flag = 0;
	k = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9' && !flag)
		{
			n = str[i] - '0';
			flag = 1;
		}
		else if (str[i] >= '0' && str[i] <= '9' && flag)
		{
			n = 10 * n + str[i] - '0';
		}
		else if (str[i] >= 65 && str[i] <= 90 && flag)
		{
			j = 0;
			while (j < n)
			{
				write(1, str + i, 1);
				j++;
				k++;
				if (k % 40 == 0)
					write(1, "\n", 1);
			}
			flag = 0;
			n = 0;
		}
		else if (str[i] >= 65 && str[i] <= 90 && !flag)
		{
			write(1, str + i, 1);
			k++;
			if (k % 40 == 0)
				write(1, "\n", 1);				
		}
		i++;
	}

//	printf("%s\n", str);
	


	return (0);
}