/*
Depth-first search traverses a tree or a graph as deep as possible along each branch before backtracking. [Problem] Each circled number represents a vertex. Each line connecting vertices denotes an edge. When the information of the edges is given as adjacent matrix, traverse with DFS and print the vertex numbers in visited order. [Input] The first input line contains the number of test cases, T. The next line contains the number of vertices and the starting vertex. Then, the information of the edges will be listed. For Instance, 1 2 means one can move from 1 to 2. There can be max 30 vertices. [Output] For each given test case, print the visited vertices.

1 2
1 3
2 4
2 5
3 8
5 8
3 6
3 7
6 8
7 8

Input 
1 //number of test cases 8 1 // number of Vertices, Starting Vertex 1 2 // 1 2 means one can move from 1 to 2 1 3 2 4 2 5 4 8 5 8 3 6 3 7 6 8 7 8 -1 -1 // end

Output
#1 1 2 4 8 5 6 3 7 // order of visited vertices

*/

#include <stdio.h>

#define MAX_VERTEX 30

int vertex;
int map[MAX_VERTEX][MAX_VERTEX];
int visit[MAX_VERTEX];

void depthFirstSearch(int v)
{
	int i;
	visit[v] = 1;
	for (i = 1; i <= vertex; i++)
	{
		if (map[v][i] == 1 && !visit[i]) 
		{
			printf("%d ", i);
			depthFirstSearch(i);
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
		}

		scanf("%d %d", &vertex, &start);

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
		printf("%d ", start);
		depthFirstSearch(start);
		printf("\n");
	}

	return 0;
}
