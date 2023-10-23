#pragma once
#include "stdafx.h"

class PrimMST 
{
public:
    PrimMST(const vector<vector<int>>& graph);
    void findMST();

private:
    int V;
    vector<vector<int>> graph;
    const int INF = INT_MAX;

    int minKey(const vector<int>& key, const vector<bool>& mstSet);
};