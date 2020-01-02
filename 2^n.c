#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int *power_of_2(int v, int n)
{
    int *dig;
	int p;
	int carry;
	int i;

	dig = (int *)malloc(sizeof(int) * n);
    i = 0;
	dig[i] = 1;
    while (++i < n)
		dig[i] = 0;
    p = 0;
    while (p < v)
    {
        carry = 0;
        i = 0;
        while (i < n)
        {
            carry = carry + dig[i] * 2;
            dig[i] = carry % 10;
            carry /= 10;
            i++;
        }
        p++;
    }
    return (dig);
}

int main(void)
{
	int v;
	int i;
	int *dig;
	int n;
	int p;
	int carry;
	char u;

	scanf("%d", &v);
	// FILE* file = fopen("input.txt", "r");
	// fscanf (file, "%d", &v);
	// fclose (file);

	n = 310;
	dig = power_of_2(v, n);
    i = n;
	while (i && dig[i] == 0)
    	i--;
	while (i >= 0)
    {
		u = dig[i] + '0';
		write(1, &u, 1);
	    i--;
    }
	write(1, "\n", 1);
    free(dig);
	return (0);
}
