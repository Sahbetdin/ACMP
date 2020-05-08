#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
	char str[300];
	char fl1, fl2;
	int i, n;


	fgets(str, 256, stdin); 
	// printf("%s\n", str);


	n = (int)strlen(str);
	// printf("n = %d\n", n);

	if (n == 1)
		printf("safe\n");
	i = 1;
	fl1 = 1;
	fl2 = 0;
	while (i < n - 1)
	{
		if (!fl1 && !fl2 && str[i] != ' ')
		{
			printf("unsafe\n");
			return (0);
		}
		else if (!fl1 && !fl2 && str[i] == ' ')
		{
			fl1 = 1;
		}
		else if(fl1 && fl2 && str[i] != ' ')
		{
			fl1 = 0;
			fl2 = 0;
		}
		else if(fl1 && !fl2 && str[i] != ' ')
		{
			printf("unsafe\n");
			return (0);
		}
		else if(fl1 && !fl2 && str[i] == ' ')
		{
			fl2 = 1;
		}
		i++;
	}
	printf("safe\n");
	return (0);
}