
#include <bits/stdc++.h>
using namespace std;

#define V 5
#define nil -99
#define INF 99999

void printSolution(int dist[][V]);

int **floydWarshall(int graph[][V])
{

    int dist[V][V], i, j, k;
    int **p = new int *[V];
    for (int i = 0; i < V; i++)
        p[i] = new int[V];

    for (i = 1; i < V; i++)
        for (j = 1; j < V; j++)
        {
            dist[i][j] = graph[i][j];
            if (dist[i][j] == 0 or dist[i][j] == INF)
                p[i][j] = nil;
            else
                p[i][j] = i;
        }

    for (k = 1; k < V; k++)
    {
        for (i = 1; i < V; i++)
        {
            for (j = 1; j < V; j++)
            {
                if (dist[i][j] > (dist[i][k] + dist[k][j]) && (dist[k][j] != INF && dist[i][k] != INF))
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    p[i][j] = p[k][j];
                }
            }
        }
    }

    printSolution(dist);
    cout << endl;
    for (int i = 1; i < V; i++)
    {
        for (int j = 1; j < V; j++)
            cout << p[i][j] << "  ";
        cout << endl;
    }
    return p;
}

void ShortestPath(int **p, int i, int j)
{
    if (i == j)
        cout << i << "->";
    else if (p[i][j] == nil)
        cout << "No Path" << endl;
    else
    {
        ShortestPath(p, i, p[i][j]);
        cout << j << "->";
    }
}

void printSolution(int dist[][V])
{
    cout << "The following matrix shows the shortest "
            "distances"
            " between every pair of vertices \n";
    for (int i = 1; i < V; i++)
    {
        for (int j = 1; j < V; j++)
        {
            if (dist[i][j] == INF)
                cout << "INF"
                     << "	 ";
            else
                cout << dist[i][j] << "	 ";
        }
        cout << endl;
    }
}

int main()
{

    system("cls");
    int graph[V][V] = {{0, 0, 0, 0, 0},
                       {0, 0, -4, 6, INF},
                       {0, INF, 0, 8, INF},
                       {0, INF, INF, 0, 3},
                       {0, 1, -2, INF, 0}};

    // print(floydWarshall(graph));
    // cout << endl
    //      << endl;
    ShortestPath(floydWarshall(graph), 1, 4);
    return 0;
}
