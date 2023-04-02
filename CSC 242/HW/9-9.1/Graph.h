//
// Created by Brian Myers on 4/1/23.
//

#ifndef INC_9_9_1_GRAPH_H
#define INC_9_9_1_GRAPH_H

#include <vector>
#include <iostream>
#include <map>

class Graph {
public:
    Graph(int v, bool dir);

    void add_edge(int v1, int v2, double w);

    void print_graph(std::ostream& o);

    std::vector<int> get_out_degrees();

    std::vector<int> get_in_degrees();

    std::vector<std::vector<double>> make_adjacency_matrix();

private:

    struct edge;
    struct vertex;
    std::vector<vertex*> vertices;
    bool directed;
};
#endif //INC_9_9_1_GRAPH_H
