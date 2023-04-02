//
// Created by Brian Myers on 4/1/23.
//

#ifndef INC_9_9_1_GRAPH_H
#define INC_9_9_1_GRAPH_H

#include <vector>
#include <iostream>

class Graph {
public:
    Graph(int v, bool dir) : directed{dir} {
        for (int i = 0; i < v + 1; ++i)
            vertices.push_back(new vertex(i));
    };

    void add_edge(int v1, int v2, double w = 1) {
        edge* e = new edge(v1, v2, w);
        vertices[v1]->edges.push_back(e);
        if (!directed) vertices[v2]->edges.push_back(e);
    }

    void print_graph(std::ostream& o) {
        for (int i = 1; i < vertices.size(); ++i) {
            o << "Vertex: " << i << " is connected to: ";
            for (int j = 0; j < vertices[i]->edges.size(); ++j)
                o << vertices[i]->edges[j]->v2 << ", ";
            o << std::endl;
        }
    }

private:

    struct edge {
        edge(int v, int v2, double w) : v1{v}, v2{v2}, weight{w}
        {};
        int v1, v2;
        double weight;
    };
    struct vertex {
        vertex(int i) : id{i}
        {};
        int id;
        std::vector<edge*> edges;
    };

    std::vector<vertex*> vertices;
    bool directed;
};
#endif //INC_9_9_1_GRAPH_H
