#include <iostream>
#include <vector>
#include "graph.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");

    cout << "Введите количество вершин: ";
    int n;
    cin >> n;

    vector<vector<int>> nearby(n);
    vector<vector<int>> edgeList(n, vector<int>(n, -1));
    vector<vector<int>> matrix(n, vector<int>(n));


    int verticesCount = 0;

    for (int i = 0; i < n; ++i) 
    {
        int v, e;
        cout << "Сколько рёбер у вершины " << i + 1 << ": ";
        cin >> e;
        verticesCount += e;
        cout << "Введите рёбра через пробел: ";
        for (int j = 0; j < e; ++j) 
        {
            cin >> v;
            edgeList[i][v - 1] = 1;
            matrix[i][v - 1] = 1;
            matrix[v - 1][i] = 1;
            nearby[i].push_back(v - 1);

        }
    }

    cout << "Спиcок рёбер: " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int k = 0; k < n; k++)
        {
            if (edgeList[i][k] != -1 && edgeList[k][i] != 0)
            {
                edgeList[i][k] = 0;
                cout << '[' << i + 1 << ',' << k + 1 << ']' << endl;
            }
        }
    }

    cout << "Матрица смежности:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int k = 0; k < n; k++) 
        {
            cout << matrix[i][k] << " ";
        }
        cout << endl;
    }

    Graph g(11);
    
    g.addEdge(1, 2);
    g.addEdge(1, 5);
    g.addEdge(3, 8);
    g.addEdge(2, 7);
    g.addEdge(2, 8);
    g.addEdge(4, 6);
    g.addEdge(4, 9);
    g.addEdge(5, 6);
    g.addEdge(6, 9);
    g.addEdge(7, 8);
    g.addEdge(9, 10);

    cout << "Обход в ширину: ";
    g.BFS(1);
    cout << endl;
    cout << "Обход в глубину: ";
    g.DFS(1);
}