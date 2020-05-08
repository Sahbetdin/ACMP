#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int max_i = 18;
char maxx[] = "987654321";


//if 99918: then make it 9999190
void	normalize(char *str)
{
	int i;

	*str -= 10;
	str[-1]++;
	i = -1;
	while (str[i] == ':')
	{
		str[i]-= 10;
		i--;
		str[i]++;
	}
}

//check if the number has equal digits
char *parity(char *str, int len)
{
	int i;
	int j;

	i = max_i;
	while (i > max_i - len + 1)
	{
		j = i - 1;
		while (j > max_i - len)
		{
			if (str[j] == str[i])
				return (str + i);
			j--;
		}
		i--;
	}
	return (NULL);
}

int main()
{
	int len;
	int i;
	char ptr[20];
	char *head;
	char *tmp2, *tmp0;
	char *tmp_p;


	i = -1;
	while (++i < max_i)
		ptr[i] = '0';
	ptr[max_i] = '\0';

	scanf("%s", ptr);


	len = strlen(ptr);
	if (len == 9)
	{
		printf("-1\n");
		return (0);
	}

	ptr[max_i + 1] = '\0';
	i = len - 1;
	head = ptr + max_i - len + 1;
	while (i >= 0)
	{
		head[i] = ptr[i];
		i--;
	}
	ptr[max_i]++;

	while (strcmp(head, maxx) < 0)
	{
		if ((tmp_p = strchr(head, ':')))
		{
			normalize(tmp_p);
		}
		if (head[-1] == '1')
		{
			head--;
			len++;
		}

		if ((tmp2 = strchr(head, '2')))
		{
			(*tmp2)++;
			tmp2++;
			while (*tmp2 != '\0')
			{
				*tmp2 = '0';
				tmp2++;
			}
			continue ;
		}
		else if ((tmp0 = strchr(head, '0')))
		{
			(*tmp0)++;
			tmp0++;
			while (*tmp0 != '\0')
			{
				*tmp0 = '0';
				tmp0++;
			}
			continue ;
		}
		else if ((tmp_p = parity(ptr, len)))
		{
			if (*tmp_p == '1')
				*tmp_p = *tmp_p + 2;
			else
				(*tmp_p)++;

			tmp_p++;
			while (*tmp_p != '\0')
			{
				*tmp_p = '0';
				tmp_p++;
			}
			// printf("%s\n", head);

			continue ;
		}
		else
		{
			printf("%s\n", head);
			return (0);
		}
	}
	printf("-1\n");

	return 0;
}