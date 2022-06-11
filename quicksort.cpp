#include <bits/stdc++.h>

using namespace std;

int hoare_left(int a[], int low, int high)
{
    int p = a[low];
    int i = low + 1;
    int j = high;
    do
    {
        while (a[i] <= p)
            i++;
        while (a[j] > p)
            j--;
        if (i < j)
            swap(a[i], a[j]);

    } while (i < j);
    swap(a[low], a[j]);
    return j;
}

int hoare_right(int a[], int low, int high)
{
    int p = a[high];
    int i = low;
    int j = high - 1;
    do
    {
        while (a[i] < p)
            i++;
        while (a[j] >= p)
            j--;
        if (i < j)
            swap(a[i], a[j]);

    } while (i < j);
    swap(a[high], a[i]);
    return j;
}

int hoare_mid(int a[], int low, int high)
{
    int m = (low + high) / 2;
    int p = a[low];
    int i = low;
    int j = high;
    do
    {
        while (a[i] <= p)
            i++;
        while (a[j] > p)
            j--;
        if (i < j)
            swap(a[i], a[j]);

    } while (i < j);
    swap(a[m], a[j]);
    return j;
}

int lomuto(int a[], int low, int high)
{
    int p = a[high];
    int i = low - 1;
    for (int j = low; j < high; j++)
    {
        if (a[j] < p)
        {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[high]);
    return i + 1;
}

void qs1(int a[], int low, int high)
{
    if (low < high)
    {
        int p = hoare_right(a, low, high);
        qs1(a, low, p - 1);
        qs1(a, p + 1, high);
    }
}
void qs2(int a[], int low, int high)
{
    if (low < high)
    {
        int p = lomuto(a, low, high);
        qs2(a, low, p - 1);
        qs2(a, p + 1, high);
    }
}

void print(int *arr, int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << "  ";
    cout << endl;
}
int main()
{

    system("CLS");
    int arr[] = {7, 9, 12, 6, 3, 4, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    print(arr, n);
    qs2(arr, 0, n - 1);
    print(arr, n);
    return 0;
}