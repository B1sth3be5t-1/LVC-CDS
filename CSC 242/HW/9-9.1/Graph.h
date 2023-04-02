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
    Graph(int v, bool dir) : directed{dir} {
        for (int i = 0; i < v + 1; ++i)
            vertices.push_back(new vertex(i));
    };

    void add_edge(int v1, int v2, double w = 1) {
        vertices[v1]->edges.push_back(new edge(v1, v2, w));
        if (!directed) vertices[v2]->edges.push_back(new edge(v2, v1, w));
    }

    void print_graph(std::ostream& o) {
        for (int i = 1; i < vertices.size(); ++i) {
            o << "Vertex: " << i << " is connected to: ";
            for (int j = 0; j < vertices[i]->edges.size(); ++j)
                o << vertices[i]->edges[j]->v2 << ", ";
            o << std::endl;
        }
    }

    std::vector<int> get_out_degrees() {
        std::vector<int> v;
        v.push_back(0);
        for (int i = 1; i < vertices.size(); ++i)
            v.push_back(vertices[i]->edges.size());
        return v;
    }

    std::vector<int> get_in_degrees() {
        if (!directed) return get_out_degrees();
        std::map<int, int> m;
        for (int i = 1; i < vertices.size(); ++i) {
            for (int j = 0; j < vertices[i]->edges.size(); ++j)
                ++m[vertices[i]->edges[j]->v2];
        }

        std::vector<int> v;
        int c = 1;
        for (auto it = m.cbegin(); it != m.cend(); ++it) {
            if (it->first != c) v.push_back(0);
            else v.push_back(it->second);
            ++c;
        }
        while (c != vertices.size()) {
            v.push_back(0);
            ++c;
        }

        return v;
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
