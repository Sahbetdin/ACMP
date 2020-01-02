#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
	int v;
	int i;
	int *dig;
	int n;
	int p;
	int carry;
	char u;

	//scanf("%d", &v);
	FILE* file = fopen("input.txt", "r");
	fscanf (file, "%d", &v);
	fclose (file);
    if (v > 0)
        printf("%d", v * (v + 1) / 2);
    else if (v < 0)
    {
        v = -v;
        printf("%d", -(v * (v + 1) / 2 - 1));
    }
    else
        printf("%d", 1);
	return (0);
}
