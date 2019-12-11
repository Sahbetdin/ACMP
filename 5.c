#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>


int main()
{
	int v;
	char *s;
	char u;
	int fd;
	

	scanf("%d", &v);
	s = strdup("2.71828182845904523536028750");
	fd = open("OUTPUT.TXT", O_WRONLY | O_CREAT | O_TRUNC, 0644);

	if (v == 0)
		write(fd, "3", 1);
	else
	{

		write(fd, s, v + 1);
		if (s[v + 2] - '0' < 5)
			write(fd, s + v + 1, 1);
		else
		{
			u = s[v + 1] + 1;
			write(fd, &u, 1);
		}
	}
	free(s);
	close(fd);
	return (0);
}

