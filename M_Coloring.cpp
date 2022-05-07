#include <bits/stdc++.h>

using namespace std;
#define V 4

bool isSafe(int Graph[V][V], int color[V], int v, int c)
{
    for (int i = 0; i < v; i++)
        if (Graph[v][i] and color[i] == c)
            return false;
    return true;
}

bool MC_util(int Graph[V][V], int color[V], int m, int v)
{
    if (v == V)
        return true;
    for (int c = 1; c <= m; c++)
    {
        if (isSafe(Graph, color, v, c))
        {
            color[v] = c;
            if (MC_util(Graph, color, m, v + 1))
                return true;
            color[v] = 0;
        }
    }
    return false;
}


bool M_Coloring(int Graph[V][V], int m)
{
    int color[V] = {0};
    if (!MC_util(Graph, color, m, 0))
    {
        cout << "Solution doesn't exists" << endl;
        return false;
    }
    cout << "Solution is ->";
    for (int i = 0; i < V; i++)
        cout << " " << color[i] << " ";
    cout << endl;
    return true;
}

int main()
{

    system("CLS");

    int graph[V][V] = {
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0},
    };

    int m = 3;
    M_Coloring(graph, m);

    return 0;
}