
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
    return p;
}

void ShortestPath(int **p, int i, int j)
{
    if (i == j)
        cout << i << "->";
    if (p[i][j] == nil)
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
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
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

void print(int **p)
{
    for (int i = 0; i < V; i++)
    {