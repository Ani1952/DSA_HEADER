#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    int u;
    int v;
    int wt;
};

void printPath(int parent[], int vertex, int source)
{
    if (vertex < 0)
    {
        return;
    }

    printPath(parent, parent[vertex], source);
    if (vertex != source)
    {
        cout << ", ";
    }
    cout << (char)(65 + vertex);
}

void bellmanford(int n, int edges, int src, Edge arr[])
{
    int dist[n];
    for (int i = 0; i < n; i++)
    {
        dist[i] = INT_MAX;
    }
    dist[src] = 0;
    int parent[n];
    for (int i = 0; i < n; i++)
    {
        parent[i] = -1;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < edges; j++)
        {
            int u = arr[j].u;
            int v = arr[j].v;
            int wt = arr[j].wt;
            if (dist[u] != INT_MAX && dist[u] + wt < dist[v])
            {
                dist[v] = dist[u] + wt;
                parent[v] = u;
            }
        }
    }
    for (int j = 0; j < edges; j++)
    {
        int u = arr[j].u;
        int v = arr[j].v;
        int wt = arr[j].wt;
        if (dist[u] != INT_MAX && dist[u] + wt < dist[v])
        {
            cout << "Negative wt cycle exists!!!";
            return;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (i == src)
        {
            continue;
        }
        if (dist[i] < INT_MAX)
        {
            cout << "The distance of vertex " << i << " from the source is :  " << dist[i] << endl;
            // printPath(parent, i, src); cout << "]" << endl;
            printPath(parent, i, src);
            cout << endl;
        }
    }
}

int main()
{
    int v, e;
    cout << "Enter the number of vertices : ";
    cin >> v;
    cout << "Enter the number of edges : ";
    cin >> e;
    Edge arr[e];
    for (int i = 0; i < e; i++)
    {
        cin >> arr[i].u >> arr[i].v >> arr[i].wt;
    }
    int s;
    cout << "Enter the source vertex : ";
    cin >> s;
    bellmanford(v, e, s, arr);
}

/*
6 8 0
0 1 1
1 2 4
1 3 1
3 2 2
4 3 4
0 4 5
0 5 1
5 0 1
*/