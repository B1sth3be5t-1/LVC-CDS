#include <iostream>
#include <vector>
#include "Graph.h"

using namespace std;

int main() {
    Graph g{7, false};

    g.add_edge(0, 1, 2);
    g.add_edge(0, 3, 1);
    g.add_edge(1, 3, 3);
    g.add_edge(1, 4, 10);
    g.add_edge(2, 0, 4);
    g.add_edge(2, 5, 5);
    g.add_edge(3, 2, 2);
    g.add_edge(3, 4, 7);
    g.add_edge(3, 5, 8);
    g.add_edge(3, 6, 4);
    g.add_edge(4, 6, 6);
    g.add_edge(6, 5, 1);

    int n = 2;

    vector<pair<double, int>> dij = g.dijkstra(n);

    int count = 1;
    for (auto& p : dij) {
        cout << n+1 << "'s shortest path to " << count++ << " is " << p.first << endl;
    }

    Graph g2 = g.kruskal();

    g2.print_rep();

}
