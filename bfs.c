/*
Breadth-first search traverses a tree or a graph as wide as possible along each level. [Problem] Each circled number is called a vertex. Each line connecting vertices is called an edge. The maximum number of vertices is 30. When the information of the edges is given as adjacent matrices, traverse with BFS and print the numbers of the vertices in the visited order. [Input] The first input line contains the number of test cases, T. The next line contains the number of vertices and the starting vertex. Then, the edge info will be listed. For Instance, 1 2 means that one can move from 1 to 2. There can be max 30 vertices. [Output] For each given test case, print the visited vertices.

Input:
1 //number of test cases 8 1 // number of Vertices, Starting Vertex 1 2 // 1 2 means one can move from 1 to 2 1 3 2 4 2 5 4 8 5 8 3 6 3 7 6 8 7 8 -1 -1 // end

Output:
#1 1 2 3 4 5 6 7 8 // visited vertices
*/

#include <stdio.h>

#define MAX_VERTEX 30

int num;
int map[MAX_VERTEX][MAX_VERTEX];
int visit[MAX_VERTEX];
int queue[MAX_VERTEX];
int rear, front;

void breadthFirstSearch(int vertex)
{
	int i;
	
	visit[vertex] = 1; 
	printf("%d ", vertex);
	queue[rear++] = vertex;
	while (front < rear)
	{
		vertex = queue[front++];
		for (i = 1; i <= num; i++)
		{
			if (map[vertex][i] == 1 && !visit[i])
			{
				visit[i] = 1;
				printf("%d ", i);
				queue[rear++] = i;
			}
		}
	}
}

int main(void)
{
	int T;
	int test_case;
	int i,j;
	int start;
	int v1;
	int v2;

	scanf("%d", &T);

	for (test_case = 1; test_case <= T; test_case++)
	{

		for (i = 0; i < MAX_VERTEX; i++)
		{
			for (j = 0; j < MAX_VERTEX; j++)
			{
				map[i][j] = 0;
			}
			visit[i] = 0;
			queue[i] = 0;
		}
		front = 0;
		rear = 0;

		scanf("%d %d", &num, &start);

		while (true)
		{
			scanf("%d %d", &v1, &v2);
			if (v1 == -1 && v2 == -1)
			{
				break;
			}
			map[v1][v2] = map[v2][v1] = 1;
		}

		printf("#%d ", test_case);
		breadthFirstSearch(start);
		printf("\n");
	}

	return 0;
}
