#include <bits/stdc++.h>

using namespace std;

struct Edge
{
    int src, dest, weight;
};
struct Graph
{
    int V, E;
    struct Edge *edge;
};
struct Graph *create(int V, int E)
{
    struct Graph *graph = new Graph;
    graph->E = E;
    graph->V = V;
    graph->edge = new Edge[E];
    return graph;
}
void print(int *dist, int n)
{
    cout << "VERTEX \t Distance From Source" << endl;
    for (int i = 0; i < n; i++)
        cout << i << "\t\t" << dist[i] << endl;
}
void BellmanFord(struct Graph *graph, int src)
{
    int v = graph->V;
    int e = graph->E;
    int dist[v];
    for (int i = 0; i < v; i++)
        dist[i] = INT_MAX;
    dist[src] = 0;

    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < e; j++)
        {
            int u = graph->edge[j].src;
            int v = graph->edge[j].dest;
            int w = graph->edge[j].weight;
            if (dist[u] != INT_MAX and dist[u] + w < dist[v])
                dist[v] = dist[u] + w;
        }
    }

    for (int i = 0; i < e; i++)
    {
        int u = graph->edge[i].src;
        int v = graph->edge[i].dest;
        int w = graph->edge[i].weight;
        if (dist[u] != INT_MAX and dist[u] + w < dist[v])
        {
            cout << "Negative Cycle Detected" << endl;
            return;
        }
    }

    print(dist, v);
}

int main()
{

    system("CLS");
    int v = 5, e = 8;
    struct Graph *graph = create(v, e);
    int a[][3] = {{0, 1, -1},
                  {0, 2, 4},
                  {1, 2, 3},
                  {1, 3, 2},
                  {1, 4, 2},
                  {3, 2, 5},
                  {3, 1, 1},
                  {4, 3, -3}};

    for (int i = 0; i < e; i++)
    {
        graph->edge[i].src = a[i][0];
        graph->edge[i].dest = a[i][1];
        graph->edge[i].weight = a[i][2];
    }

    BellmanFord(graph, 0);

    return 0;
}