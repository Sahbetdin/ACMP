#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <fcntl.h>

/*gets v-th power of two as in array of ints 
n is number of digits*/
/* 0 < v < 1000 */
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
	int i, n;
	int *dig;
	char u;
    int fd;

    FILE * fp1;
    FILE * fp2;
    fp1 = fopen ("1.txt","w");
    fp2 = fopen ("2.txt","w");

    v = 1;
    while (v < 1000)
    {

        fprintf (fp1, "%.0Lf\n", powl(2, v));
        n = 310;
        dig = power_of_2(v, n);
        i = n;
        while (i && dig[i] == 0)
            i--;

        while (i >= 0)
        {
    //		u = dig[i] + '0';
    //		write(fd, &u, 1);
            fprintf (fp2, "%d", dig[i]);
    //      printf("%d", dig[i]);
            i--;
        }
        fprintf (fp2, "\n");
        free(dig);
    v++;
    }
    fclose (fp1);
    fclose (fp2);
	return (0);

}
