//сравнение с пожаром
/*
Хирьянов
лекция 3: https://www.youtube.com/watch?v=HlZMhDAcIIQ
лекция 4: https://www.youtube.com/watch?v=5cX3SBItOBc

Граф:
список ребер.
N = 5
[(1,2), (3,4), (1,4)]

матрица смежности

списки смежности
N = 5
G = {словарь: ключ-значение}
{0: {1,2,4},
1: {0, 2, 4},
2: {0, 1, 3},
3: {0, 1, 3}}.


Польза: выделяет компоненту связности
дает остовное дерево
дает кратчайшие пути по всем вершинам, измеряемые в кол-ве ребер

Реализация через очередь
def bfs(G, start, fired = set() ):
	Q = [start]
	fired.add(start)
	while len(Q) != 0:
		current = Q.pop(0)
		for neighbor in G[current]:
			if neighbor not in fired:
				fired.add(neighbor)
				Q.append(neighbor)
	current = 0 #текущая

*/

#include <stdio.h>
#include <stdlib.h>




int main()
{



	return (0);
}