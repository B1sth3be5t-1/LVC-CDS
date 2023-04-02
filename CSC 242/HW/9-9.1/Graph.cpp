//
// Created by Brian Myers on 4/2/23.
//

#include "Graph.h"

struct Graph::edge {
    edge(int v, int v2, double w) : v1{v}, v2{v2}, weight{w}
    {};
    int v1, v2;
    double weight;
};

struct Graph::vertex {
    vertex(int i) : id{i}
    {};
    int id;
    std::vector<edge*> edges;
};

Graph::Graph(int v, bool dir) : directed{dir} {
    for (int i = 0; i < v; ++i)
        vertices.push_back(new vertex(i));
}

void Graph::add_edge(int v1, int v2, double w = 1) {
    vertices[v1]->edges.push_back(new edge(v1, v2, w));
    if (!directed) vertices[v2]->edges.push_back(new edge(v2, v1, w));
}

void Graph::print_graph(std::ostream& o) {
    for (int i = 0; i < vertices.size(); ++i) {
        o << "Vertex: " << i << " is connected to: ";
        for (int j = 0; j < vertices[i]->edges.size(); ++j)
            o << vertices[i]->edges[j]->v2 << ", ";
        o << std::endl;
    }
}

std::vector<int> Graph::get_out_degrees() {
    std::vector<int> v;
    for (int i = 0; i < vertices.size(); ++i)
        v.push_back(vertices[i]->edges.size());
    return v;
}

std::vector<int> Graph::get_in_degrees() {
    if (!directed) return get_out_degrees();
    std::map<int, int> m;
    for (int i = 0; i < vertices.size(); ++i) {
        for (int j = 0; j < vertices[i]->edges.size(); ++j)
            ++m[vertices[i]->edges[j]->v2];
    }

    std::vector<int> v;
    int c = 0;
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

std::vector<std::vector<double>> Graph::make_adjacency_matrix() {
    std::vector<std::vector<double>> map;
    map.resize(vertices.size());
    for (int v = 0; v < vertices.size(); ++v) {
        map[v].resize(vertices.size());
        for (int e = 0; e < vertices[v]->edges.size(); ++e)
            map[v][vertices[v]->edges[e]->v2] = vertices[v]->edges[e]->weight;
    }

    for (int v = 0; v < vertices.size(); ++v)
        for (int e = 0; e < vertices.size(); ++e)
            if (map[v][e] == 0) map[v][e] = INT_MAX;

    return map;
}

