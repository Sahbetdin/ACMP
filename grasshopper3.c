//https://stepik.org/lesson/307326/step/5?unit=289414


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


int main()
{
	char buf[2];
    char *a;
	long *s;
	long i, n;
	int res;


	buf[1] = '\0';
	n = 0;
    //пишем свой atoi, иначе со scanf не проходит
	while ((res = read(0, buf, 1)))
	{
		if (buf[0] == '\n')
			break ;
		if (buf[0] >= '0' && buf[0] <= '9')
			n = n * 10 + buf[0] - '0';
	}

//выделяем память для считывания нулей и единиц + символ конца стоки
    a = (char *)malloc(sizeof(char) * (n + 1));
    a[n] = '\0';
	res = read(0, a, n);
//	printf("%s\n", a);

//если последний символ 1, то пишем 0
	if (a[n - 1] == '1')
	{
		printf("0\n");
		free(a);
		return (0);
	}

//если n == 1, то выводим кол-во добраться до него есть 1
	if (n == 1 && a[0] == '0')
    {
		printf("1\n");
		free(a);
		return (0);
	}
//выделяем память под динамику, будучи уверены, что n > 1
    s = (long *)malloc(sizeof(long) * n);
	s[0] = (a[0] == '0') ? 1 : 0;
	s[1] = (a[1] == '0') ? s[0] + 1 : 0;
	printf("i = %ld, %ld\n", 0L, s[0]);
	printf("i = %ld, %ld\n", 1L, s[1]);

	if (n == 2)
	{
		printf("%ld\n", s[1]);
		free(a);
		return (0);
	}
	s[2] = (a[2] == '0') ? s[0] + s[1] + 1 : 0;
	printf("i = %ld, %ld\n", 2L, s[2]);

	if (n == 3)
	{
		printf("%ld\n", s[2]);
		free(a);
		return (0);
	}

	i = 2;
	while (i < n)
	{
		if (a[i] == '1' && a[i - 1] == '1' && a[i - 2] == '1')
		{
			printf("0\n");
			free(a);
			free(s);
			return (0);
		}
		i++;
	}

	i = 3;
	while (i < n)
	{
		s[i] = (a[i] == '0') ? s[i - 1] + s[i - 2] + s[i - 3] : 0;
		s[i] = s[i] % (1000000007);
		printf("i = %ld, %ld\n", i, s[i]);
		i++;
	}
	printf("%ld\n", s[n - 1]);
	free(s);
	free(a);

    
//    printf("FINISHED");

	return (0);
}
// int main()
// {
// 	long i, n;
// 	char *buf;
// 	long *s;

// 	scanf("%ld", &n);
// 	buf = (char *)malloc(sizeof(char) * (n + 1));
// 	s = (long *)malloc(sizeof(long) * n);
// 	read(0, buf, n);
// 	buf[n] = '\0';

// 	if (buf[n - 1] == '1')
// 	{
// 		printf("0\n");
// 		free(buf);
// 		free(s);
// 		return (0);
// 	}

// 	if (n == 1 && buf[0] == '1')
// 		printf("0\n");
// 	else if (n == 1 && buf[0] == '0')
// 		printf("1\n");
// 	if (n == 1)
// 	{
// 		free(buf);
// 		return (0);
// 	}
// 	s[0] = (buf[0] == '0') ? 1 : 0;
// 	s[1] = (buf[1] == '0') ? s[0] + 1 : 0;
// 	if (n == 2)
// 	{
// 		printf("%ld\n", s[1]);
// 		free(buf);
// 		return (0);
// 	}
// 	s[2] = (buf[2] == '0') ? s[0] + s[1] + 1 : 0;
// 	if (n == 3)
// 	{
// 		printf("%ld\n", s[2]);
// 		free(buf);
// 		return (0);
// 	}
// // // printf("HERE\n");

// 	i = 2;
// 	while (i < n)
// 	{
// 		if (buf[i] == '1' && buf[i - 1] == '1' && buf[i - 2] == '1')
// 		{
// 			printf("0\n");
// 			free(buf);
// 			free(s);
// 			return (0);
// 		}
// 		i++;
// 	}

// 	i = 3;
// 	while (i < n)
// 	{
// 		s[i] = (buf[i] == '0') ? s[i - 1] + s[i - 2] + s[i - 3] : 0;
// 		s[i] = s[i] % (1000000007);
// 		i++;
// 	}
// 	printf("%ld\n", s[n - 1]);
// 	free(s);
// 	free(buf);



// 	// i = 0;
// 	// while (i < n)
// 	// {
// 	// 	if (buf[i] == '1')
// 	// 		printf("YES\n");
// 	// 	else
// 	// 		printf("NO\n");

// 	// 	i++;
// 	// }




// 	return (0);
// }

