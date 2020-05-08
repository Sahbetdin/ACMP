#include <stdio.h>
#include <stdlib.h>


int main()
{
	int x1, y1, x2, y2, x3, y3;
	long double tmp_x, tmp_y;
	scanf("%d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3);
    printf("%.7Lf %.7Lf", (x1 + x2 + x3) / 3.0L, (y1 + y2 + y3) / 3.0L);

	return (0);
}