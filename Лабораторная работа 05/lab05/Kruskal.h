#pragma once
#include "stdafx.h"

class KruskalMST
{
public:
	KruskalMST(int);
	void addEdge(int, int, int);
	void findMST();

private:
	int V;
	vector<pair<int, pair<int, int>>> edges;
	vector<int> parent;

	int find(int);
	void unionSets(int, int);
};