#include "algo_container.h"
using namespace std;

int main()
{
    Graph_Matrix g(7);
    g.add_edge(0, 1, 1);
    g.add_edge(0, 4, 3);
    g.add_edge(1, 4, 4);
    g.add_edge(1, 2, 7);
    g.add_edge(1, 5, 2);
    g.add_edge(4, 5, 2);
    g.add_edge(2, 5, 6);
    g.add_edge(2, 3, 5);
    g.add_edge(5, 3, 1);

    cout<<g.kruskal();
}