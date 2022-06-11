#include <bits/stdc++.h>
using namespace std;

bool safe(int a[][25], int row, int col)
{
    int i, j;
    for (i = 0; i < row; i++)
        if (a[i][col])
            return false;
    i = row;
    j = col;
    while (i >= 0 and j >= 0)
    {
        if (a[i][j])
            return false;
        i--;
        j--;
    }

    while (i >= 0 and j < col)
    {
        if (a[i][j])
            return false;
        i--;
        j++;
    }

    return true;
}

void printboard(int a[][25], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << " | ";
        for (int j = 0; j < n; j++)
        {
            if (a[i][j])
                cout << 'Q' << " | ";
            else
                cout << " "
                     << " | ";
        }
        cout << endl;
    }
}

bool NQ(int a[][25], int n, int i = 0)
{
    if (i == n)
    {
        printboard(a, n);
        return true;
    }
    for (int j = 0; j < n; j++)
    {
        if (safe(a, i, j))
        {
            a[i][j] = 1;
            if (NQ(a, n, i + 1))
                return true;
            a[i][j] = 0;
        }
    }
    return false;
}

int main()
{
    system("CLS");
    int n;
    cout << "Enter Queen" << endl;
    cin >> n;
    int a[25][25] = {0};
    NQ(a, n);
    return 0;
}