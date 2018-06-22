/* 
Breadth-first search traverses a tree or a graph as wide as possible along each level. [Problem] A map is filled with 0 and 1, where 0 stands for wall, 1 stands for road. Find the shortest path starting from the upper left (1,1) to the bottom right (R,C). One Can't move over the map or diagonally, but only to the left, right, up, down. The size of the map is given as R, C and its range is limited to 1 <= R, C <= 50. [Input] The first input line contains the number of test cases, T. The next line contains the row, R and the column, C. (1 <= R, C <= 50) Then, the map data will be listed [Output] For each given test case, print the shortest distance

Input:
2 // number of test cases 4 5 // R, C 1 1 1 1 0 // Map, 1 0 1 0 0 // 0: Wall 1 1 0 0 1 // 1: Road 0 1 1 1 1 // borders are considered as walls 10 10 1 1 1 1 1 1 0 1 1 1 1 0 0 0 0 1 0 1 0 1 1 0 0 0 0 1 1 1 0 1 1 0 0 1 1 1 0 0 0 1 1 0 0 1 0 1 0 1 1 1 1 0 0 1 0 1 1 1 0 1 1 0 0 1 0 0 1 0 0 1 1 1 0 1 1 1 0 0 0 1 0 1 0 1 0 1 1 1 0 1 0 1 1 1 0 0 1 1 1 1

Output:
#1 7 #2 20
*/

#include <stdio.h>

#define MAX_N 50

int MAP[MAX_N + 2][MAX_N + 2];
int queue[MAX_N * MAX_N][3];
int row;
int column;
int head;
int rear;

int isEmpty()
{
	return (head <= rear) ? 1 : 0;
}

int enqueue(int x, int y, int c)
{
	queue[head][0] = x;
	queue[head][1] = y;
	queue[head][2] = c;
	head++;
	return 1;
}

int dequeue(int *x, int *y, int *c)
{
	if (isEmpty())
	{
		return 0;
	}
	*x = queue[rear][0];
	*y = queue[rear][1];
	*c = queue[rear][2];
	rear++;
	return 1;
}

int breadthFirstSearch()
{
	int x;
	int y;
	int c;

	enqueue(1, 1, 0);
	MAP[1][1] = 0;
	while (!isEmpty()) 
	{
		dequeue(&x, &y, &c);
		if (x == column && y == row)
		{
			return c;
		}
		if (x + 1 <= column && MAP[x + 1][y]) 
		{
			enqueue(x + 1, y, c + 1);
			MAP[x + 1][y] = 0;
		}
		if (y + 1 <= row && MAP[x][y + 1]) 
		{
			enqueue(x, y + 1, c + 1);
			MAP[x][y + 1] = 0;
		}
		if (x - 1 > 0 && MAP[x - 1][y]) 
		{
			enqueue(x - 1, y, c + 1);
			MAP[x - 1][y] = 0;
		}
		if (y - 1 > 0 && MAP[x][y - 1]) 
		{
			enqueue(x, y - 1, c + 1);
			MAP[x][y - 1] = 0;
		}
	}
	return -1;
}


int main(void)
{
	int test_case;
	int T;

	scanf("%d", &T);

	for (test_case = 1; test_case <= T; test_case++) 
	{
		head = 0;
		rear = 0;
		scanf("%d %d", &row, &column);

		for (int i = 1; i <= row; i++) 
		{
			for (int j = 1; j <= column; j++)
			{
				scanf("%d", &MAP[j][i]);
			}
		}
		printf("#%d %d\n", test_case, breadthFirstSearch());
	}
	return 0;
}
