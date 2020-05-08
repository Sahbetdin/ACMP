#include <stdio.h>
#include <stdlib.h>

long double abs_d(long double a)
{
	if (a < 0)
		return (-a);
	return (a);
}


int main()
{
	int x1,y1,x2,y2;
	int a1,b1,a2,b2;
	int i, n;
	int flag1_hor, flag2_hor, flag1_ver, flag2_ver;
	long double coef1, coef2, bee1, bee2, eps, tmp_x, tmp_y;
	scanf("%d", &n);

	i = 0;
	while (i < n)
	{
		eps = 1.0e-5l;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		scanf("%d %d %d %d", &a1, &b1, &a2, &b2);
		if (x2 - x1 == 0)
			flag1_ver = 1;
		else if (x2 - x1 != 0)
			flag1_ver = 0;
		
		if (y2 - y1 == 0)
			flag1_hor = 1;
		else if (y2 - y1 != 0)
			flag1_hor = 0;
			
		if (a2 - a1 == 0)
			flag2_ver = 1;
		else if (a2 - a1 != 0)
			flag2_ver = 0;
		
		if (b2 - b1 == 0)
			flag2_hor = 1;
		else if (b2 - b1 != 0)
			flag2_hor = 0;

		if (flag1_ver == 1 && flag2_ver == 1)
		{
			if (x1 == a1)
				printf("2\n");
			else 
				printf("0\n");
			i++;
			continue ;
		}
		else if (flag1_hor == 1 && flag2_hor == 1)
		{
			if (y1 == b1)
				printf("2\n");
			else
				printf("0\n");
			i++;
			continue ;
		}
		else if (flag1_ver == 1 && flag2_hor == 1)
		{
			printf("1 %.10Lf %.10Lf\n", x1 * 1.0L, b1 * 1.0L);
			// printf("1 %d %d\n", x1, b1);
			i++;
			continue ;
		}
		else if (flag1_hor == 1 && flag2_ver == 1)
		{
			printf("1 %.10Lf %.10Lf\n", a1 * 1.0L, y1 * 1.0L);
			// printf("1 %d %d\n", a1, y1);
			i++;
			continue ;
		}

	// printf("flag1_ver = %d\n", flag1_ver);
	// printf("flag2_ver = %d\n", flag2_ver);
	// printf("flag1_hor = %d\n", flag1_hor);
	// printf("flag2_hor = %d\n", flag2_hor);

		if (flag1_ver == 0)
		{
			coef1 = 1.0L * (y2 - y1)/ (x2 - x1);
			bee1 = 1.0L *y1 - coef1 * x1;
		}
		if (flag2_ver == 0)
		{
			coef2 = 1.0L * (b2 - b1)/ (a2 - a1);
			bee2 = 1.0L *b1 - coef2 * a1;
		}
		if (abs_d(coef1 - coef2) < eps && abs_d(bee2 - bee1) < eps)
		{
			printf("2\n");
			i++;
			continue ;
		}
		else if (abs_d(coef1 - coef2) < eps && abs_d(bee2 - bee1) > eps)
		{
			printf("0\n");
			i++;
			continue ;
		}
		else 
		{
			tmp_x = (bee2 - bee1) / (coef1 - coef2);
			tmp_y = coef1 * tmp_x + bee1;
			printf("1 %.10Lf %.10Lf\n", tmp_x, tmp_y);
			i++;
			continue ;
		}
	}



	return (0);
}