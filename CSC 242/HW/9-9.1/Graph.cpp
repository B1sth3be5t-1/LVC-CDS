#include <vector>
#include <iostream>
#include <queue>

#include "graph.h"

using namespace std;

Graph::Graph(int sz, bool is_directed)
        : graph(sz), directed(is_directed)
{
    for (int i = 0; i < graph.size(); ++i) {
        graph[i].idx = i;
    }
}

void Graph::add_edge(int src, int dest, double weight)
{
    graph[src].edges.push_back({src, dest, weight});
    if (!directed) {
        graph[dest].edges.push_back({dest, src, weight});
    }
}

void Graph::print_rep() const
{
    for (const auto& v: graph) {
        cout << v.idx << ": ";
        for (const auto& e: v.edges) {
            cout << e.dest << "(" << e.w << ")" << " ";
        }
        cout << "\n";
    }
}

bool Graph::is_edge(int src, int dest) const
{
    for (const auto& e: graph[src].edges) {
        if (e.dest == dest) {
            return true;
        }
    }
    return false;
}

std::vector<int> Graph::out_degree() const
{
    vector<int> ret(graph.size());

    for (int i=0; i<graph.size(); ++i) {
        ret[i] = graph[i].edges.size();
    }
    return ret;
}

std::vector<int> Graph::in_degree() const
{
    vector<int> ret(graph.size());

    if (!directed)
        return out_degree();

    for (const auto& v: graph) {
        for (const auto& e: v.edges) {
            ++ret[e.dest];
        }
    }
    return ret;
}

vector<int> Graph::top_sort() const {
    std::vector<int> ret(graph.size());
    int count = 0;
    queue<vertex> q;

    vector<int> in_degs = in_degree();
    for (int i = 0; i < in_degs.size(); ++i)
        if (in_degs[i] == 0)
            q.push(graph[i]);

    while (!q.empty()) {
        vertex v = q.front();
        q.pop();

        ret[v.idx] = ++count;
        for (auto& e : v.edges) {
            vertex o = graph[e.dest];
            if (--in_degs[o.idx] == 0)
                q.push(o);
        }
    }

    if (count != graph.size()) throw stderr;

    return ret;


    //for 9.1
    // top sort is: s, G, D, A, B, H, E, I, F, C, t
    //I looked at the graph and did this by hand. Remove a vertex with in-degree 0, delete all edges, and repeat.

}

Graph::edge::edge(int s, int d, double w)
        : src{s}, dest{d}, w{w}
{}

Graph::vertex::vertex(int idx)
        : idx{idx}
{}