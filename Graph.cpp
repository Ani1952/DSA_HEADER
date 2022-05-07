#include "algo_container.h"
using namespace std;

int main()
{ 
    Graph_Matrix g(6);
    g.add_edge(0, 1, 7);
    g.add_edge(1, 2, 6);
    g.add_edge(2, 3, 4);
    g.add_edge(1, 3, 3);
    g.add_edge(0, 3, 8);
    g.add_edge(3, 4, 3);
    g.add_edge(2, 4, 2);
    g.add_edge(4, 5, 2);
    g.add_edge(2, 5, 5);

    system("CLS");
    cout << endl;
    g.print();
    cout << endl;
    cout << "KRUSKAL's ALGORITHM" << endl;
    cout << g.kruskal() << endl<<endl;
    cout << "PRIM's ALGORITHM" << endl;
    cout << g.prim() << endl<<endl;
    cout << "DJIKSTRA's ALGORITHM" << endl;
    g.djikstra(0);
    cout << endl;

    return 0;
}