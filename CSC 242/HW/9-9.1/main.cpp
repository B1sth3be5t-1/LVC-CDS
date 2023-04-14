#include <iostream>
#include <random>
#include "Graph.h"

using namespace std;

//num vertices, random edges

Graph random_graph(int n, int out, bool d) {
    static random_device rd;
    static default_random_engine re(rd());
    static uniform_int_distribution<int> dist(0, n - 1);
    Graph g(n, d);

    for (int i = 0; i < n * out; ++i) {
        auto u = dist(re);
        auto v = dist(re);
        g.add_edge(u, v);
    }
    return g;
}

int main() {
    Graph g{7, true};

    g.add_edge(0, 1, 10);
    g.add_edge(0, 2, 10);
    g.add_edge(0, 3, 10);
    g.add_edge(1, 3, 10);
    g.add_edge(1, 4, 10);
    g.add_edge(2, 5, 10);
    g.add_edge(3, 5, 10);
    g.add_edge(3, 6, 10);
    g.add_edge(3, 2, 10);
    g.add_edge(4, 3, 10);
    g.add_edge(4, 6, 10);
    g.add_edge(6, 5, 10);

    g.print_rep();

    cout << endl;
    vector<int> out = g.out_degree();
    int c = 0;
    for (int i : out)
        cout << "Vertex " << c++ << " is connected out to " << i << " other vertices." << endl;

    cout << endl;

    vector<int> in = g.in_degree();
    int c2 = 0;
    for (int i : in)
        cout << "Vertex " << c2++ << " is connected inwards to " << i << " other vertices." << endl;

    cout << endl;

    Graph rand = random_graph(10'000, 4, true);

    rand.print_rep();



}
