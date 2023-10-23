﻿#include "stdafx.h"
#include "Prim.h"
#include "Kruskal.h"

int main()
{
	setlocale(LC_ALL, "rus");

	vector<vector<int>> graph =
	{
		{ 0, 2, 0, 8, 2, 0, 0, 0 },
		{ 2, 0, 3, 10, 5, 0, 0, 0 },
		{ 0, 3, 0, 0, 12, 0, 0, 7 },
		{ 8, 10, 0, 0, 14, 3, 1, 0 },
		{ 2, 5, 12, 14, 0, 11, 4, 8 },
		{ 0, 0, 0, 3, 11, 0, 6, 0 },
		{ 0, 0, 0, 1, 4, 6, 0, 9 },
		{ 0, 0, 7, 0, 8, 0, 9, 0 }
	};

	int V = graph.size();

	PrimMST mstPrim(graph);
	KruskalMST mstKruskal(V);

	for (int u = 0; u < V; u++)
	{
		for (int v = u + 1; v < V; v++)
		{
			int weight = graph[u][v];

			if (weight != 0)
			{
				mstKruskal.addEdge(u, v, weight);
			}
		}
	}

	cout << "�������� �����:" << endl;
	mstPrim.findMST();

	cout << endl << endl << "�������� ��������:" << endl;
	mstKruskal.findMST();
}
