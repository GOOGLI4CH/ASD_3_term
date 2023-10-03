#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using std::vector, std::queue, std::stack, std::cout;

class Graph
{
public:
	Graph(int);
	void addEdge(int, int);
	void BFS(int);
	void DFS(int);
	
private:
	int countEdges;
	vector<vector<int>> adj;
};