#include "Kruskal.h"

KruskalMST::KruskalMST(int V) : V(V)
{
	parent.resize(V, -1);
}

void KruskalMST::addEdge(int u, int v, int weight)
{
	edges.push_back({ weight, {u, v} });
}

void KruskalMST::findMST()
{
	sort(edges.begin(), edges.end());

	int e = 0;
	int i = 0;

	while (e < V - 1 && i < edges.size())
	{
		int weight = edges[i].first;
		int u = edges[i].second.first;
		int v = edges[i].second.second;
		i++;

		int x = find(u);
		int y = find(v);

		if (x != y)
		{
			cout << "Ребро: " << u << " - " << v << " Вес: " << weight << endl;
			unionSets(x, y);
			e++;
		}
	}
}

int KruskalMST::find(int u)
{
	if (parent[u] == -1)
		return u;
	return find(parent[u]);
}

void KruskalMST::unionSets(int u, int v)
{
	int uRoot = find(u);
	int vRoot = find(v);
	parent[uRoot] = vRoot;
}