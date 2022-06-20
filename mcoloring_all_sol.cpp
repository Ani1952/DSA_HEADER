#include <bits/stdc++.h>
using namespace std;

#define n 3

void doColor(int k, int m, int a[n][n], int colors[])
{
    while (true)
    {
        colors[k] = (colors[k] + 1) % (m + 1);
        if (!colors[k])
            return;

        int j = 0;
        while (j < k)
        {
            if (a[k][j] && colors[k] == colors[j])
                break;
            ++j;
        }

        if (j == k)
            return;
    }
}

void mColoring(int k, int m, int graph[n][n], int colors[])
{
    static int count;

    while (true)
    {
        doColor(k, m, graph, colors);
        if (colors[k] == 0)
            return;

        if (k + 1 == n)
        {
            cout <<endl<< ++count<<endl;
            for (int i = 0; i < n; ++i)
                cout << (char)('A' + i) << ':' << "    " << colors[i] << endl;
        }

        mColoring(k + 1, m, graph, colors);
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
