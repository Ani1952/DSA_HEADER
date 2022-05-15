#include <bits/stdc++.h>

using namespace std;

void parenthesis(int i, int j, int n, int *braces, char &name)
{
    if (i == j)
    {
        cout << name++;
        return;
    }
    cout << "(";
    parenthesis(i, *((braces + i * n) + j), n, braces, name);
    parenthesis(*((braces + i * n) + j) + 1, j, n, braces, name);
    cout << ")";
}

void order(int p[], int n)
{
    int m[n][n];
    int braces[n][n];

    for (int i = 0; i < n; i++)
        m[i][i] = 0;

    for (int L = 2; L < n; L++)
    {
        for (int i = 1; i < n - L + 1; i++)
        {
            int j = i + L - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k < j; k++)
            {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j])
                {
                    m[i][j] = q;
                    braces[i][j] = k;
                }
            }
        }
    }

    char name = 'A';
    cout << "Optimal braces for multiplication order ::: ";
    parenthesis(1, n - 1, n, (int *)braces, name);
    cout << endl
         << "Optimal number of scalar multiplications are " << m[1][n - 1] << endl;
}

int main()
{

    system("CLS");

    int arr[] = {2,3,5,2,4};
    int n = sizeof(arr) / sizeof(arr[0]);
    order(arr, n);
    return 0;

}