#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

int knapsack(int W, int wt[], int val[], int n)
{
    if (n == 0 || W == 1)
        return 0;
    if (wt[n - 1] > W)
        return knapsack(W, wt, val, n - 1);
    else
        return max(val[n - 1] + knapsack(W - wt[n - 1], wt, val, n - 1), knapsack(W, wt, val, n - 1));
}

int knapSack(int W, int wt[], int val[], int n)
{
    int i, w;
    int **k = new int *[n + 1];
    for (int i = 0; i < n + 1; i++)
        k[i] = new int[w + 1];
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
    return k[n][W];
}

int main()
{

    auto start = high_resolution_clock::now();
    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);
    cout << knapsack(W, wt, val, n) << endl;

    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Time taken by knap : "
         << duration.count() << " microseconds" << endl
         << endl;

    return 0;
}