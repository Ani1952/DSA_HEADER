#include <bits/stdc++.h>

using namespace std;

#define V 4

bool nextvalue(bool G[V][V], int x[V])
{

    for (int i = 0; i < V; i++)
        for (int j = i + 1; j < V; j++)
            if (G[i][j] and x[i] == x[j])
                return false;
    return true;
}

void print(int x[V])
{
    cout << "Solution exists" << endl;
    for (int i = 0; i < V; i++)
        cout << "Vertex: " << i + 1 << " is given color" << x[i] << " " << endl;
}

bool mcoloring(bool G[V][V], int m, int x[V], int i = 0)
{
    if (i == V)
    {
        if (nextvalue(G, x))
        {
            print(x);
            return true;
        }
        return false;
    }
    for (int j = 1; j <= m; j++)
    {
        x[i] = j;
        if (mcoloring(G, m, x, i + 1))
            return true;
        x[i] = 0;
    }
    return false;
}

int main()
{

    system("CLS");
    bool G[V][V] = {{0, 1, 1, 1},
                    {1, 0, 1, 0},
                    {1, 1, 0, 1},
                    {1, 0, 1, 0}};
    int x[V] = {0};
    if (!mcoloring(G, 5, x, 0))
        cout << "No solution" << endl;
    return 0;
}