#include <bits/stdc++.h>
using namespace std;

#define n 3

void doColor(int v, int m, int a[n][n], int colors[])
{
    while (true)
    {
        colors[v] = (colors[v] + 1) % (m + 1);
        if (!colors[v])
            return;

        int j = 0;
        while (j < v)
        {
            if (a[v][j] && colors[v] == colors[j])
                break;
            ++j;
        }

        if (j == v)
            return;
    }
}

void mColoring(int v, int m, int graph[n][n], int colors[])
{
    static int count;

    while (true)
    {
        doColor(v, m, graph, colors);
        if (colors[v] == 0)
            return;

        if (v + 1 == n)
        {
            cout <<endl<< ++count<<endl;
            for (int i = 0; i < n; ++i)
                cout << (char)('A' + i) << ':' << "    " << colors[i] << endl;
        }

        mColoring(v + 1, m, graph, colors);
    }
}

int main()
{
    system("CLS");
    int m;
    cin >> m;
    int colors[n];
    for (int i = 0; i < n; ++i)
    {
        colors[i] = 0;
    }

    int graph[n][n];
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
            cin >> graph[i][j];
    }

    char start = 'A';
    mColoring(start - 'A', m, graph, colors);

    return 0;
}
