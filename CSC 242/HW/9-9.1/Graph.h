#ifndef GRAPHS_GRAPH_H
#define GRAPHS_GRAPH_H

#include <vector>

class Graph {
public:
    Graph(int sz, bool is_directed = true);

    void add_edge(int src, int dest, double weight = 1.0);

    bool is_edge(int src, int dest) const;

    std::vector<int> out_degree() const;
    std::vector<int> in_degree() const;

    void print_rep() const;

    std::vector<int> top_sort() const;

private:
    struct edge {
        int src;
        int dest;
        double w;

        edge(int s, int d, double w);
    };

    struct vertex {
        int idx;
        std::vector<edge> edges;

        vertex(int idx = -1);
    };

private:
    std::vector<vertex> graph;
    bool directed;
};

#endif //GRAPHS_GRAPH_H