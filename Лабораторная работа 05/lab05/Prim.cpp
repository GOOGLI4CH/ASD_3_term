#include "Prim.h"


PrimMST::PrimMST(const vector<vector<int>>& g) : graph(g) 
{
    V = graph.size();
}

int PrimMST::minKey(const vector<int>& key, const vector<bool>& mstSet)
{
    int min = INF;
    int min_index = -1;

    for (int v = 0; v < V; v++) 
    {
        if (!mstSet[v] && key[v] < min) 
        {
            min = key[v];
            min_index = v;
        }
    }

    return min_index;
}

void PrimMST::findMST() 
{
    vector<int> parent(V, -1);
    vector<int> key(V, INF);
    vector<bool> mstSet(V, false);

    key[0] = 0;

    for (int count = 0; count < V - 1; count++) 
    {
        int u = minKey(key, mstSet);
        mstSet[u] = true;

        for (int v = 0; v < V; v++) 
        {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) 
            {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    for (int i = 1; i < V; i++) 
    {
        cout << "Ребро: " << parent[i] << " - " << i << " Вес: " << graph[i][parent[i]] << endl;
    }
}