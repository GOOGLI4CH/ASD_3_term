#include <iostream>
#include <vector>

using namespace std;

const int INF = INT_MAX;

int findMinDistanceVertex(const vector<int>& distance, const vector<bool>& visited) 
{
    int minDistance = INF;
    int minVertex = -1;

    for (int i = 0; i < distance.size(); i++)
    {
        if (!visited[i] && distance[i] < minDistance) 
        {
            minDistance = distance[i];
            minVertex = i;
        }
    }

    return minVertex;
}

void printShortestDistances(const vector<int>& distance) 
{
    cout << "Вершина\tРасстояние до начальной вершины" << endl;
    for (int i = 0; i < distance.size(); i++)
    {
        cout << char(i + 65) << "\t" << distance[i] << endl;
    }
}

void dijkstra(const vector<vector<int>>& graph, char startVertexOut) 
{
    int numVertices = graph.size();
    int startVertex = int(startVertexOut - 65);
    vector<int> distance(numVertices, INF);
    vector<bool> visited(numVertices, false);

    distance[startVertex] = 0;

    for (int i = 0; i < numVertices - 1; i++)
    {
        int u = findMinDistanceVertex(distance, visited);
        visited[u] = true;

        for (int v = 0; v < numVertices; v++) 
        {
            if (!visited[v] && graph[u][v] && distance[u] != INF && distance[u] + graph[u][v] < distance[v]) 
            {
                distance[v] = distance[u] + graph[u][v];
            }
        }
    }

    printShortestDistances(distance);
}

int main() 
{
    /*
        Матрица смежности графа из задания:

           A  B  C  D  E  F  G  H  I
        A  0  7  10 0  0  0  0  0  0
        B  7  0  0  0  0  9  27 0  0
        C  10 0  0  0  31 8  0  0  0
        D  0  0  0  0  32 0  0  17 21
        E  0  0  31 32 0  0  0  0  0
        F  0  9  8  0  0  0  0  11 0
        G  0  27 0  0  0  0  0  0  15
        H  0  0  0  17 0  11 0  0  15
        I  0  0  0  21 0  0  15 15 0
    */

    setlocale(LC_ALL, "rus");

    int numVertices;
    char startVertex;

    cout << "Введите количество вершин графа: ";
    cin >> numVertices;

    vector<vector<int>> graph(numVertices, vector<int>(numVertices));

    /*cout << "Введите матрицу смежности графа:" << endl;

    for (int i = 0; i < numVertices; i++) 
    {
        for (int j = 0; j < numVertices; j++) 
        {
            cin >> graph[i][j];
        }
    }*/
    
    graph =
    {
        { 0, 7, 10, 0, 0, 0, 0, 0, 0 },
        { 7, 0, 0, 0, 0, 9, 27, 0, 0 },
        { 10, 0, 0, 0, 31, 8, 0, 0, 0 },
        { 0, 0, 0, 0, 32, 0, 0, 17, 21 },
        { 0, 0, 31, 32, 0, 0, 0, 0, 0 },
        { 0, 9, 8, 0, 0, 0, 0, 11, 0 },
        { 0, 27, 0, 0, 0, 0, 0, 0, 15 },
        { 0, 0, 0, 17, 0, 11, 0, 0, 15 },
        { 0, 0, 0, 21, 0, 0, 15, 15, 0 }
    };

    cout << "Введите начальную вершину: ";
    cin >> startVertex;

    dijkstra(graph, startVertex);
}
