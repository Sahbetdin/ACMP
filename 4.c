#include <unistd.h>
#include <stdio.h>

int main(void)
{
	int v;
	char u;

    scanf("%d", &v);
    u = v + '0';
    write(1, &u, 1);
    write(1, "9", 1);
    v = 9 - v;
    u = v + '0';
    write(1, &u, 1);
	return (0);
}