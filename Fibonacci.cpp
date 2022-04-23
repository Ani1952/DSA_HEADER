#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

int fib1(int n)
{
    if (n <= 1)
        return 1;
    return (fib1(n - 1) + fib1(n - 2));
}


int dp1[100] = {0};
void fib2(int n)
{
    dp1[0] = 0;
    dp1[1] = 1;
    for (int i = 2; i <= n; i++)
        dp1[i] = dp1[i - 1] + dp1[i - 2];
    for (int i = 0; i <= n; i++)
        cout << dp1[i] << " ";
}



int main()
{
    system("cls");
    auto start = high_resolution_clock::now();

    for (int i = 0; i <= 9; i++)
        cout << fib1(i) << " ";
    cout << endl;

    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Time taken by fib recur: "
         << duration.count() << " microseconds" << endl
         << endl;

    start = high_resolution_clock::now();

    fib2(9);
    cout << endl;

    stop = high_resolution_clock::now();

    duration = duration_cast<microseconds>(stop - start);

    cout << "Time taken by fib recur: "
         << duration.count() << " microseconds" << endl << endl;
}