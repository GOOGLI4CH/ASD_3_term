#include "graph.h"

Graph::Graph(int countEdges)
{
	this->countEdges = countEdges;
	this->adj.resize(countEdges);
}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w);
	adj[w].push_back(v);
}

void Graph::BFS(int start)
{
	vector<bool> visited(this->countEdges, false);
	queue<int> queue;

	visited[start] = true;
	queue.push(start);

	while (!queue.empty())
	{
		start = queue.front();
		cout << start << " ";
		queue.pop();

		for (const auto& v : adj[start])
		{
			if (!visited[v])
			{
				visited[v] = true;
				queue.push(v);
			}
		}
	}
}

void Graph::DFS(int start)
{
	vector<bool> visited(this->countEdges, false);
	stack<int> stack;

	visited[start] = false;
	stack.push(start);

	while (!stack.empty())
	{
		start = stack.top();
		cout << start << " ";
		stack.pop();

		for (const auto& v: adj[start])
		{
			if (!visited[v])
			{
				visited[v] = true;
				stack.push(v);
			}
		}
	}
}