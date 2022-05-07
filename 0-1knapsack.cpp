#include <bits/stdc++.h>
using namespace std;

int knapsack(int W, int wt[], int val[], int n)
{
    if (n == 0 || W == 1)
        return 0;
    if (wt[n - 1] > W)
        return knapsack(W, wt, val, n - 1);
    else
        return max(val[n - 1] + knapsack(W - wt[n - 1], wt, val, n - 1), knapsack(W, wt, val, n - 1));
}

void knapSack(int W, int wt[], int val[], int n)
{
    int i, w;
    int k[n + 1][W + 1];
    for (i = 0; i <= n; i++)
    {
        for (w = 0; w <= W; w++)
        {
            if (!i || !w)
                k[i][w] = 0;
            else if (wt[i - 1] <= w)
                k[i][w] = max(val[i - 1] +
                                  k[i - 1][w - wt[i - 1]],
                              k[i - 1][w]);

            else
                k[i][w] = k[i - 1][w];
        }
    }
    cout << "Knapsack Profit is ::" << k[n][W] << endl;
    ;
    int X = k[n][W];
    int Y = W;
    int j;
    for (j = n; j > 0; j--)
    {
        if (X = k[j - 1][Y])
        {
            continue;
        }
        else
        {
            cout << j << " Added to Knapasck " << endl;
            Y -= wt[j];
            X -= val[j];
            if (!X)
                break;
        }
    }
}

int main()
{
    system("cls");
    int val[] = {100, 20, 40, 60, 50, 30, 80};
    int wt[] = {5, 4, 3, 2, 1, 3, 2};
    int W = 10;
    int n = sizeof(val) / sizeof(val[0]);
    knapSack(W, wt, val, n);
    return 0;
}