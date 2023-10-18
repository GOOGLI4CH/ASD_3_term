#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e9;


void floydWarshall(vector<vector<int>>& graph, vector<vector<int>>& path_matrix)
{
    int n = graph.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i != j && graph[i][j] == 0)
            {
                graph[i][j] = INF;
            }
        }
    }

    for (int k = 0; k < n; k++) 
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (graph[i][k] < INF && graph[k][j] < INF)
                {
                    if (graph[i][j] > graph[i][k] + graph[k][j])
                    {
                        graph[i][j] = graph[i][k] + graph[k][j];
                        path_matrix[i][j] = path_matrix[i][k];
                    }
                }
            }
        }
    }
}

int main() 
{
    setlocale(LC_ALL, "rus");

    int n = 6;
    vector<vector<int>> graph(n, vector<int>(n));
    vector<vector<int>> path_matrix(n, vector<int>(n));

    graph =
    {
        { 0, 28, 21, 59, 12, 27 },
        { 7, 0, 24, INF, 21, 9 },
        { 9, 32, 0, 13, 11, INF},
        { 8, INF, 5, 0, 16, INF},
        { 14, 13, 15, 10, 0, 22},
        { 15, 18, INF, INF, 6, 0}
    };

    path_matrix = 
    {
        { 0, 2, 3, 4, 5, 6 },
        { 1, 0, 3, 4, 5, 6 },
        { 1, 2, 0, 4, 5, 6 },
        { 1, 2, 3, 0, 5, 6 },
        { 1, 2, 3, 4, 0, 6 },
        { 1, 2, 3, 4, 5, 0 }
    };

    floydWarshall(graph, path_matrix);

    cout << "Матрица кратчайших путей" << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (graph[i][j] == INF)
            {
                cout << "INF ";
            }
            else 
            {
                cout << graph[i][j] << " ";
            }
        }
        cout << endl;
    }

    cout << "Матрица последовательности" << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << path_matrix[i][j] << " ";
        }
        cout << endl;
    }
}
