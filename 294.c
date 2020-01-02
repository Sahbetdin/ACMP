#include <stdio.h>
#include <stdlib.h>

int min(int x, int y)
{
	if (x < y)
		return (x);
	else
		return (y);
}

int max(int x, int y)
{
	if (x < y)
		return (y);
	else
		return (x);
}


int main()
{
	int bo_bef, bo_lost, bo_pr;
	int nut_bef, nut_lost, nut_pr;
	int lost_pairs;
	int uscherb;

	FILE* file = fopen("input.txt", "r");
	fscanf(file, "%d", &bo_bef);
	fscanf(file, "%d", &bo_lost);
	fscanf(file, "%d", &bo_pr);
	fscanf(file, "%d", &nut_bef);
	fscanf(file, "%d", &nut_lost);
	fscanf(file, "%d", &nut_pr);

	fclose(file);
	lost_pairs = min(bo_bef - bo_bef * bo_lost / 100, nut_bef - nut_bef * nut_lost / 100);
	uscherb = (bo_bef - lost_pairs) * bo_pr + (nut_bef - lost_pairs) * nut_pr;

	printf("%d\n", uscherb);
	return (0);
}