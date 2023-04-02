#include <iostream>
#include "Graph.h"

using namespace std;

int main() {
    Graph g{7, true};

    g.add_edge(1, 2);
    g.add_edge(2, 3);
    g.add_edge(3, 4);
    g.add_edge(4, 5);
    g.add_edge(5, 1);
    g.add_edge(6, 1);
    g.add_edge(7, 1);

    g.print_graph(std::cout);

    cout << endl;
    vector<int> v = g.get_out_degrees();
    int c = 0;
    for (int i : v)
        cout << "Vertex " << c++ << " is connected out to " << i << " other vertices." << endl;

    cout << endl;

    vector<int> v2 = g.get_in_degrees();
    int c2 = 1;
    for (int i : v2)
        cout << "Vertex " << c2++ << " is connected inwards to " << i << " other vertices." << endl;

}
