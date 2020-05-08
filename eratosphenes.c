

# include <stdio.h>
# include <stdlib.h>
# include <math.h>


int isPrimeNumber(int number)
{
    int iLoop = 0;
    int iPrimeFlag = 1;
    int iLimit = sqrt(number); // calculate of square root n
    if(number <= 1)
    {
        iPrimeFlag = 0;
    }
    else
    {
        for(iLoop = 2; iLoop <= iLimit; iLoop++)
        {
            if((number % iLoop) == 0) // Check prime number
            {
                iPrimeFlag = 0;
                break;
            }
        }
    }
    return iPrimeFlag;
}



int my_is_prime(int n)
{
	int lim;
	int i;

	if (n == 1)
		return (0);
	if (n == 2 || n == 3 || n == 5 || n == 7 || n == 11)
		return (1);
	if (n % 2 == 0)
		return (0);
	if (n % 3 == 0)
		return (0);

	i = 3;
	lim = (int)(sqrt(n) + 5.0);
	// printf("lim = %d\n", lim);
	while (i < lim)
	{
		if (n % i == 0)
			return (0);			
		i += 2;
	}
	return (1);
}

//https://stepik.org/lesson/307321/step/3?unit=289409
//printf 1 if the number is primary,
// 0 otherwise.
int main(void)
{
	int n;
	int i;
	int lim;

	scanf("%d", &n);
	printf("%d\n", my_is_prime(n));


	// i = 1;
	// while (i < 1000)
	// {
	// 	if (my_is_prime(i) ^ isPrimeNumber(i))
	// 	{
	// 		printf("i = %d\n", i);
	// 		getchar();
	// 	}
	// 	i++;
	// }

	return (0);
}


//https://stepik.org/lesson/307321/step/2?unit=289409
// int main()
// {
// 	long a, b, c;
// 	long double tmp;

// 	scanf("%ld %ld %ld", &a, &b, &c);
// 	tmp = 1./a + 1./b + 1./c;
// 	tmp = 1./ tmp;
// 	printf("%ld\n", (long)tmp );


// 	return (0);
// }
