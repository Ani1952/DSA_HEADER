#include <bits/stdc++.h>
using namespace std;

struct knap
{

    int cost;
    int weight;
};

void make_knap(knap arr[], int a[][2], int n)
{

    for (int i = 0; i < n; i++)
    {
        arr[i].cost = a[i][0];
        arr[i].weight = a[i][1];
    }
}

void print(knap arr[], int n)
{
    cout << "ITEM \t\tCost \t\tWeight" << endl;
    for (int i = 0; i < n; i++)
        cout << i << "\t\t" << arr[i].cost << "\t\t" << arr[i].weight << endl;
}
bool compare(struct knap a, struct knap b)
{

    double l1 = double(a.cost / a.weight);
    double l2 = double(b.cost / b.weight);
    return l1 > l2;
}

double knapsack(int w, struct knap arr[], int n)
{
    sort(arr, arr + n, compare); // compare on the basis of cost/weight.
    int curweight = 0;
    double finalcost = 0.0; // knapsack cost
    cout << "Item"
         << "\t\t"
         << "Part Of It" << endl;
    for (int i = 0; i < n; i++)
    {
        if (curweight + arr[i].weight <= w)
        {
            curweight += arr[i].weight;
            finalcost += arr[i].cost;
            cout << i << "\t\t"
                 << "1.0" << endl;
        }
        else
        {

            // for fractional part
            int remain = (w - curweight);
            finalcost += arr[i].cost * ((double)remain / (double)arr[i].weight);
            cout << i << "\t\t"
                 << ((double)remain / (double)arr[i].weight) << endl;
            break;
        }
    }

    return finalcost;
}

int main()
{

    int a[][2] = {{280, 40}, {100, 10}, {120, 20}, {120, 24}};
    int n = sizeof(a) / sizeof(a[0]);
    knap arr[n];
    for (int i = 0; i < n; i++)
        make_knap(arr, a, n);
    print(arr, n);
    cout<<endl;
    cout<<knapsack(65,arr,n);
}