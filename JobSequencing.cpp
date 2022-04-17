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
    Job arr[] = {{'a', 2, 100}, {'b', 1, 19}, {'c', 2, 27}, {'d', 1, 25}, {'e', 3, 15}};
    int n = sizeof(arr) / sizeof(arr[0]);

    JS(arr, n);
    return 0;
}