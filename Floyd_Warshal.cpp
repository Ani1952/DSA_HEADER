#include <bits/stdc++.h>

using namespace std;

#define V 5
#define inf 99999
#define nil -99999

void printsolution(int dist[][V]);

int **FLoyd_Warshal(int G[V][V])
{
    int dist[V][V], i, j, k;
    int **p = new int *[V];
    for (i = 0; i < V; i++)
        p[i] = new int[V];

    for (i = 1; i < V; i++)
        for (j = 1; j < V; j++)
        {
            dist[i][j] = G[i][j];
            if (dist[i][j] == inf or dist[i][j] == 0)
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
                if (dist[i][j] > (dist[i][k] + dist[k][j]) and dist[i][k] != inf and dist[k][j] != inf)
                {
                    dist[i][j] = (dist[i][k] + dist[k][j]);
                    p[i][j] = p[k][j];
                }
            }
        }
    }

    return p;
}

void shortestpath(int **p, int i, int j)
{
    if (i == j)
        cout << i << "->";
    else if (p[i][j] == nil)
        cout << "No Path Between " << i
             << " and " << j << endl;
    else
    {
        shortestpath(p, i, p[i][j]);
        cout << j << "->";
    }
}
void printsolution(int dist[][V])
{
    cout << "The shortest path distance between all pair of vertices are shown by the given matrix" << endl;
    for (int i = 1; i < V; i++)
    {
        for (int j = 1; j < V; j++)
        {
            if (dist[i][j] == inf)
                cout << "INF"
                     << "  ";
            else
                cout << dist[i][j] << "   ";
        }
        cout << endl;
    }
}

int main()
{

    system("CLS");
    int graph[V][V] = {{0, 0, 0, 0, 0},
                       {0, 0, -4, 6, inf},
                       {0, inf, 0, 8, inf},
                       {0, inf, inf, 0, 3},
                       {0, 1, -2, inf, 0}};

    for (int i = 1; i < V; i++)
    {
        for (int j = 1; j < V; j++)
        {
            shortestpath(FLoyd_Warshal(graph), i, j);
            cout<<"\t\t";
        }
        cout<<endl<<endl;
    }
    return 0;
}