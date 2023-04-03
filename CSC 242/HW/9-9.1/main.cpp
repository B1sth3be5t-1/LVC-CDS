#include <iostream>
#include "Graph.h"

using namespace std;

int main() {
    Graph g{7, true};

    g.add_edge(0, 1, 10);
    g.add_edge(1, 2, 10);
    g.add_edge(2, 3, 10);
    g.add_edge(3, 4, 10);
    g.add_edge(4, 0, 10);
    g.add_edge(5, 0, 10);
    g.add_edge(6, 0, 10);
    g.add_edge(2, 6, 100);

    g.print_graph(std::cout);

    cout << endl;
    vector<int> out = g.get_out_degrees();
    int c = 0;
    for (int i : out)
        cout << "Vertex " << c++ << " is connected out to " << i << " other vertices." << endl;

    cout << endl;

    vector<int> in = g.get_in_degrees();
    int c2 = 0;
    for (int i : in)
        cout << "Vertex " << c2++ << " is connected inwards to " << i << " other vertices." << endl;

    cout << endl;

    vector<vector<double>> map = g.make_adjacency_matrix();
    for (vector<double>& v : map) {
        for (double d : v) {
            cout << d << " ";
        }
        cout << endl;
    }


}
