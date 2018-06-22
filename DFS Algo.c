/*
Depth-first search refers to traversing a tree or a graph as deep as possible along each branch before backtracking. [Problem] Each circled number represents a vertex. Each line connecting the vertices denotes an edge. For given start and destination vertices, print the shortest distance between them when traversing with DFS algorithm. [Input] The first input line contains the number of test case, T. The next line contains the number of vertices, the number of edges, starting point, and destination point. Then, the information of vertices will be listed. For Instance, 1 2 means that one can move from 1 to 2. There can be max 30 vertices. The length of an edge is 1. [Output] For each given test case, print the shortest distance. Print -1, if it’s unreachable.

Input:
2 // number of test cases 8 10 1 8// number of vertices, number of edges, Starting Point, Destination point 1 2 // 1 2 means one can move from 1 to 2 1 3 2 7 2 4 3 5 3 6 4 7 5 7 6 7 6 8 8 10 2 8 1 2 1 3 2 7 2 4 3 5 3 6 4 7 5 7 6 7 6 8

Output:
#1 3 // length of shortest path #2 -1
*/

#include <stdio.h>

#define MAX_VERTEX 30

int map[MAX_VERTEX][MAX_VERTEX];
int visit[MAX_VERTEX];
int vertex;
int edge;
int maxEdge;
int start;
int end;

void depthFirstSearch(int v, int depth)
{
	int i;
	if (v == end) 
	{
		if (maxEdge < 0 || depth < maxEdge)
		{
			maxEdge = depth;
		}
		return;
	}

	visit[v] = 1;
	for (i = 1; i <= vertex; i++) 
	{
		if (map[v][i] == 1 && !visit[i]) 
		{
			depthFirstSearch(i, depth + 1);
			visit[i] = 0;
		}
	}
}


int main(void)
{
	int T;
	int test_case;
	int i;
	int v1;
	int v2;

	scanf("%d", &T);

	for (test_case = 1; test_case <= T; test_case++)
	{
		scanf("%d %d %d %d", &vertex, &edge, &start, &end);

		for (i = 0; i < edge; i++)
		{
			scanf("%d %d", &v1, &v2);
			map[v1][v2] = 1;
		}

		maxEdge = -1;
		depthFirstSearch(start, 0);
		printf("#%d %d\n", test_case, maxEdge);
	}
	return 0;
}
