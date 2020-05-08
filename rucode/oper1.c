/*
def f(n):
	if n == 0:
		return 1
	else:
		index = n - 1
		sum = 1
		while (index >= 0):
			sum = sum + f(index)
			print("index = " , sum)
			index = index - 1
		#print("~~~~~~~")
		return sum

print(f(30))

*/
#include <stdio.h>


long f(long n)
{
	long index;
	long sum;

	if (n == 0)
		return (1);
	else
	{
		index = n - 1;
		sum = 1;
		while (index >= 0)
		{
			sum = sum + f(index);
			printf("n = %ld, sum\n", n);
			index = index - 1;
		}
		printf("~~~~~~~~\n");
		return (sum);
	}
}


/*
n = 1
index = 0
sum = 1
+

n = 2;
index = 1,0
sum = 1

n = 3
*/


// int	main()
// {
// 	int k;

// 	k = 4;
// 	printf("%ld\n", f(k));

// 	return (0);
// }



int	main()
{
	long k;
	long s;
	long i;
	long f[32];


	k = 30;
	f[0] = 0;
	i = 1;
	while (i <= k)
	{
		f[i] = f[i - 1] * 2 + 1;
		printf("f[%ld] = %ld\n", i, f[i]);
		i++;
	}



	return (0);
}






