#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int abs(int a)
{
	if (a < 0)
		return (-a);
	return (a);
}


int main()
{
	char str[9];
	char king_w[3];
	char rook_w[3];
	char king_b[3];
	int pos[9], king_wh_pos[9], rook_wh_pos[9], i, dist;

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

//странно
	if (abs(king_b[0] - king_w[0]) == 0 && abs(king_b[1] - king_w[1]) == 1)
	{
		printf("Strange\n");
		return (0);
	}
	else if (abs(king_b[0] - king_w[0]) == 1 && abs(king_b[1] - king_w[1]) == 0)
	{
		printf("Strange\n");
		return (0);
	}
	else if (abs(king_b[0] - king_w[0]) == 1 && abs(king_b[1] - king_w[1]) == 1)
	{
		printf("Strange\n");
		return (0);
	}



//пат1
	dist = abs(king_b[0] - king_w[0]) + abs(king_b[1] - king_w[1]);
	if (king_b[0] == 'a' && king_b[1] == '1' && rook_w[0] == 'b' && rook_w[1] == '2' && dist >= 2 && dist <= 4)
	{
		printf("Stalemate\n");
		return 0;
	}
	else if (king_b[0] == 'a' && king_b[1] == '8' && rook_w[0] == 'b' && rook_w[1] == '7' && dist >= 2 && dist <= 4)
	{
		printf("Stalemate\n");
		return 0;
	}
	else if (king_b[0] == 'h' && king_b[1] == '1' && rook_w[0] == 'g' && rook_w[1] == '2' && dist >= 2 && dist <= 4)
	{
		printf("Stalemate\n");
		return 0;
	}
	else if (king_b[0] == 'h' && king_b[1] == '8' && rook_w[0] == 'g' && rook_w[1] == '7' && dist >= 2 && dist <= 4)
	{
		printf("Stalemate\n");
		return 0;
	}


//пат2	
	if (king_b[0] == 'a' && king_b[1] == '1')
	{
		if ((king_w[0] == 'c' && king_w[1] == '1' && rook_w[1] == '2')
		||  (king_w[0] == 'a' && king_w[1] == '3' && rook_w[0] == 'b'))
		{
			printf("Stalemate\n");
			return 0;
		}
	}
	else if (king_b[0] == 'a' && king_b[1] == '8')
	{
		if ((king_w[0] == 'c' && king_w[1] == '8' && rook_w[1] == '7')
		||  (king_w[0] == 'a' && king_w[1] == '6' && rook_w[0] == 'b'))
		{
			printf("Stalemate\n");
			return 0;
		}

	}
	else if (king_b[0] == 'h' && king_b[1] == '1')
	{
		if ((king_w[0] == 'f' && king_w[1] == '1' && rook_w[1] == '2')
		||  (king_w[0] == 'h' && king_w[1] == '3' && rook_w[0] == 'g'))
		{
			printf("Stalemate\n");
			return 0;
		}
	}
	else if (king_b[0] == 'h' && king_b[1] == '8')
	{
		if ((king_w[0] == 'f' && king_w[1] == '8' && rook_w[1] == '7')
		||  (king_w[0] == 'h' && king_w[1] == '6' && rook_w[0] == 'g'))
		{
			printf("Stalemate\n");
			return 0;
		}
	}
//мат
	if (king_b[0] == 'a' && king_b[1] == '1')
	{
		if ((king_w[0] == 'a' || king_w[0] == 'b') && king_w[1] == '3' && rook_w[1] == '1')
		{
			printf("Checkmate\n");
			return (0);
		}
		else if ((king_w[1] == '1' || king_w[1] == '2') && king_w[0] == 'c' && rook_w[0] == 'a')
		{
			printf("Checkmate\n");
			return (0);
		}
	}
	else if (king_b[0] == 'h' && king_b[1] == '1')
	{
		if ((king_w[0] == 'g' || king_w[0] == 'h') && king_w[1] == '3' && rook_w[1] == '1')
		{
			printf("Checkmate\n");
			return (0);
		}
		else if ((king_w[1] == '1' || king_w[1] == '2') && king_w[0] == 'f' && rook_w[0] == 'h')
		{
			printf("Checkmate\n");
			return (0);
		}
	}
	else if (king_b[0] == 'a' && king_b[1] == '8')
	{
		if ((king_w[0] == 'a' || king_w[0] == 'b') && king_w[1] == '6' && rook_w[1] == '8')
		{
			printf("Checkmate\n");
			return (0);
		}
		else if ((king_w[1] == '7' || king_w[1] == '8') && king_w[0] == 'c' && rook_w[0] == 'a')
		{
			printf("Checkmate\n");
			return (0);
		}
	}
//мат левая стенка
	if (king_b[1] == '1' && king_w[1] == '3' && king_w[0] == king_b[0] && rook_w[1] == '1')
	{
		printf("Checkmate\n");
		return (0);
	}
	else if (king_b[1] == '8' && king_w[1] == '7' && king_w[0] == king_b[0] && rook_w[1] == '8')
	{ //прав стенка
		printf("Checkmate\n");
		return (0);
	}
	else if (king_b[0] == 'h' && king_w[0] == 'f' && king_w[1] == king_b[1] && rook_w[0] == 'h')
	{//нижн стенка
		printf("Checkmate\n");
		return (0);
	}
	else if (king_b[0] == 'a' && king_w[0] == 'c' && king_w[1] == king_b[1] && rook_w[0] == 'a')
	{//врехн стенка
		printf("Checkmate\n");
		return (0);
	}

//мат
	if (king_b[0] == 'a' && rook_w[0] == 'c' && (king_b[1] == king_w[1]))
	{
		printf("Checkmate\n");
		return 0;
	}
	else if (king_b[0] == 'h' && rook_w[0] == 'f' && (king_b[1] == king_w[1]))
	{
		printf("Checkmate\n");
		return 0;		
	}
	else if (king_b[1] == '1' && rook_w[1] == '3' && (king_b[0] == king_w[0]))
	{
		printf("Checkmate\n");
		return 0;		
	}
	else if (king_b[1] == '8' && rook_w[1] == '6' && (king_b[0] == king_w[0]))
	{
		printf("Checkmate\n");
		return 0;		
	}
//шах
	if ((king_b[0] == rook_w[0] && king_w[0] != rook_w[0]) ||
		(king_b[1] == rook_w[1] && king_w[1] != rook_w[1]))
	{
		printf("Check\n");
		return (0);
	}
	if (king_b[0] == rook_w[0] && king_w[0] == rook_w[0])
	{
		if ((king_b[1] - rook_w[1]) * (king_w[1] - rook_w[1]) < 0)
		{
			printf("Check\n");
			return (0);
		}
	}
	if (king_b[1] == rook_w[1] && king_w[1] == rook_w[1])
	{
		if ((king_b[0] - rook_w[0]) * (king_w[0] - rook_w[0]) < 0)
		{
			printf("Check\n");
			return (0);
		}
	}
	printf("Normal\n");
	return (0);
}