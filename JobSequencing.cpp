#include <iostream>
#include <algorithm>

using namespace std;

struct Job
{
    char id;
    int dead;
    int profit;
};

bool compare(Job a, Job b)
{
    return (a.profit > b.profit);
}

void JS(Job arr[], int n)
{
    sort(arr, arr + n, compare);

    int result[n];
    bool slot[n];

    for (int i = 0; i < n; i++)
        slot[i] = false;

    for (int i = 0; i < n; i++)
    {
        for (int j = min(n, arr[i].dead) - 1; j >= 0; j--)
        {
            if (!slot[j])
            {
                slot[j] = true;
                result[j] = i;
                break;
            }
        }
    }

    for (int i = 0; i < n; i++)
        if (slot[i])
            cout << arr[result[i]].id << " ";
    cout << endl;
}

int main()
{
    system("CLS");
    Job arr[] = {{'1', 7, 15}, {'2', 2, 20}, {'3', 5, 30}, {'4', 3, 18}, {'5', 4, 18}, {'6', 5, 10}, {'7', 2, 23}, {'8', 7, 16}, {'9', 3, 25}};
    int n = sizeof(arr) / sizeof(arr[0]);

    JS(arr, n);
    return 0;
}