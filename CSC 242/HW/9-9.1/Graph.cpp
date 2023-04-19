#include <vector>
#include <iostream>
#include <queue>
#include <tuple>
#include <memory>

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
    graph[src].edges.emplace_back(src, dest, weight);
    if (!directed) {
        graph[dest].edges.emplace_back(dest, src, weight);
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

tuple<vector<int>, bool> Graph::top_sort() const
{
    // check pre-conditions?
    if (!directed)
        throw graph_exception();

    auto indeg = in_degree();

    // find an initial list of in-degree 0 vertices
    queue<int> next_up;

    for (int i=0; i<indeg.size(); ++i) {
        if (indeg[i] == 0) {
            next_up.push(i);
        }
    }

    vector<int> ts;

    while (!next_up.empty()) {
        auto next = next_up.front();
        next_up.pop();
        ts.push_back(next);
        // for each outbound edge, reduce the in-deg
        // of the destination by 1
        for (const auto& e: graph[next].edges) {
            if (--indeg[e.dest] == 0) {
                next_up.push(e.dest);
            }
        }
    }

    return make_tuple(ts, ts.size() < graph.size());
}

vector<pair<int, int>> Graph::shortest_path(int v) const {
    std::vector<pair<int, int>> ret(graph.size(), make_pair(-1, -1));
    queue<int> q;

    ret[v].first = 0;

    q.push(v);

    while (!q.empty()) {
        int i = q.front();
        q.pop();

        for (const auto& e : graph[i].edges) {
            if (ret[e.dest].first == -1) {
                ret[e.dest].first = ret[i].first + 1;
                ret[e.dest].second = i;
                q.push(e.dest);
            }

        }
    }



    return ret;
    //returns a vector of pairs. The first element is the length from given vertex, the second is the previous vertex in the path.
    //runtime: O(|E| + |V|)
    //goes through every vertex, and loops through every edge once

    /*
     * 9.5 b)
     * Shortest path from B
     * A - 3
     * C - 1
     * D - 2
     * E - 1
     * F - 2
     * G - 1
     */
}

vector<pair<double, int>> Graph::dijkstra(int n) const {
    vector<pair<double, int>> ret(graph.size(), make_pair(-1, -1));

    auto cmp = [&](const vertex* v1, const vertex* v2){return ret[v1->idx].first < ret[v2->idx].first;};
    priority_queue<const vertex*, vector<const vertex*>, decltype(cmp)> q(cmp);
    vector<bool> known(graph.size(), false);

    const vertex* v1 = &(graph[n]);
    q.push(v1);

    ret[n].first = 0;
    ret[n].second = n;

    while (!q.empty()) {
        const vertex* v = q.top();
        q.pop();
        if (known[v->idx]) continue;

        known[v->idx] = true;

        for (auto e : v->edges) {
            const vertex* dest = &(graph[e.dest]);
                if (!known[dest->idx]) {
                    q.push(dest);
                    if (ret[dest->idx].first == -1 || ret[v->idx].first + e.w < ret[dest->idx].first) {
                        ret[dest->idx].first = ret[v->idx].first + e.w;
                        ret[dest->idx].second = v->idx;
                    }
                }
        }
    }



    return ret;
}

Graph::edge::edge(int s, int d, double w)
        : src{s}, dest{d}, w{w}
{}

Graph::vertex::vertex(int idx)
        : idx{idx}
{}