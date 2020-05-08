#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main()
{
	char buf;
	int a, b;
	int fd;
	char fl1, fl2;


	fd = 0;
	read(fd, &buf, 1);
	fl1 = 1;
	fl2 = 0;

	while (read(fd, &buf, 1) > 0)
	{
		// write(1, &buf, 1);
		if (!fl1 && !fl2 && buf != ' ' && buf != '\0')
		{
			// write(1, "F\n", 2);
			write(1, "unsafe\n", 7);
			return (0);
		}
		else if (!fl1 && !fl2 && buf == ' ')
		{
			fl1 = 1;
		}
		else if(fl1 && fl2 && buf != ' ')
		{
			fl1 = 0;
			fl2 = 0;
		}
		else if(fl1 && !fl2 && buf != ' ')
		{
			write(1, "unsafe\n", 7);
			return (0);
		}
		else if(fl1 && !fl2 && buf == ' ')
		{
			fl2 = 1;
		}		
	}
	write(1, "safe\n", 5);
	return (0);
}