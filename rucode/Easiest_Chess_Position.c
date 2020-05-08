//6-04-2020
//Easiest Chess Position

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char str[9];
	char king_w[3];
	char rook_w[3];
	char king_b[3];
	int pos[9], king_wh_pos[9], rook_wh_pos[9], i;

	fgets(str, 9, stdin); 
	king_w[0] = str[0];
	king_w[1] = str[1];
	king_w[2] = '\0';

	rook_w[0] = str[3];
	rook_w[1] = str[4];
	rook_w[2] = '\0';

	king_b[0] = str[6];
	king_b[1] = str[7];
	king_b[2] = '\0';

//черный король
	pos[0] = (king_b[0] - 'a' - 1) * 8 + king_b[1] - '1';
	pos[1] = (king_b[0] - 'a' - 1) * 8 + king_b[1] - '1' + 1;
	pos[2] = (king_b[0] - 'a' - 1) * 8 + king_b[1] - '1' + 2;

	pos[3] = (king_b[0] - 'a') * 8 + king_b[1] - '1';
	pos[4] = (king_b[0] - 'a') * 8 + king_b[1] - '1' + 1;
	pos[5] = (king_b[0] - 'a') * 8 + king_b[1] - '1' + 2;
	
	pos[6] = (king_b[0] - 'a' + 1) * 8 + king_b[1] - '1';
	pos[7] = (king_b[0] - 'a' + 1) * 8 + king_b[1] - '1' + 1;
	pos[8] = (king_b[0] - 'a' + 1) * 8 + king_b[1] - '1' + 2;

//белый король
	king_wh_pos[0] = (king_w[0] - 'a' - 1) * 8 + king_w[1] - '1';
	king_wh_pos[1] = (king_w[0] - 'a' - 1) * 8 + king_w[1] - '1' + 1;
	king_wh_pos[2] = (king_w[0] - 'a' - 1) * 8 + king_w[1] - '1' + 2;

	king_wh_pos[3] = (king_w[0] - 'a') * 8 + king_w[1] - '1';
	king_wh_pos[4] = (king_w[0] - 'a') * 8 + king_w[1] - '1' + 1;
	king_wh_pos[5] = (king_w[0] - 'a') * 8 + king_w[1] - '1' + 2;
	
	king_wh_pos[6] = (king_w[0] - 'a' + 1) * 8 + king_w[1] - '1';
	king_wh_pos[7] = (king_w[0] - 'a' + 1) * 8 + king_w[1] - '1' + 1;
	king_wh_pos[8] = (king_w[0] - 'a' + 1) * 8 + king_w[1] - '1' + 2;

//белая ладья


	i = 0;
	while (i < 9)
	{
		printf("i = %d, pos = %d\n", i, pos[i]);
		i++;
	}

	// scanf("%s", king_w);
	// scanf("%s", rook_w);
	// scanf("%s", king_b);

	// printf("king_w = %s\n", king_w);
	// printf("rook_w = %s\n", rook_w);
	printf("king_b = %s\n", king_b);
	printf("str = %s\n", str);



	return (0);
}