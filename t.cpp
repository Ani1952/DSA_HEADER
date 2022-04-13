#include "structure.h"
using namespace std;

int main()
{

    int a[] = {2, 4, 7, 12, 9, 6, 3};
    int n = sizeof(a) / sizeof(a[0]);
    Heap_max h(n);
    for (int i = 0; i < n; i++)
        h.insert(a[i]);
    cout << h.extract_max() << endl;

    h.print();
    h.remove(2);
    cout << h.get_max() << endl;
    h.print();
    return 0;
}