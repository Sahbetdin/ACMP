//https://stepik.org/lesson/307321/step/4?unit=289409


#include <stdio.h>
#include <limits.h>


int main()
{
	// unsigned long x;
	// unsigned long input;

	// scanf("%ld", &input);
	// printf("%lld\n", LLONG_MAX);


	unsigned char x;
	unsigned char inp;
	unsigned char res;
	unsigned char overfl_n;


	// scanf("%hhu", &inp);
	// overfl_n = 3 - inp % 256;
	// printf("%hhu\n", overfl_n);

	res = inp * 3;
	inp = 1;
	while (inp < 255)
	{
		res = inp * 3;
		printf("%hhu %hhu\n", inp, res);
		inp++;
	}
	return (0);
}