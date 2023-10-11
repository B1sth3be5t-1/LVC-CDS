#include <iostream>
#include <vector>
#include <array>
#include <fstream>
#include <queue>
#include <stack>
#include <set>

#include "disjointset.h"

using namespace std;

struct edge {
    edge(int d, double ww) 
        : dest{d}, w{ww}
    {}

    double w;
    int dest;
};

struct vertex {
    vertex(int i)
        : idx{i}
    {}

    int idx;  // ?
    vector<edge> edges;
};

vector<vertex> graph;


struct dijk {
    int v;
    double dist;

    dijk(int vv, double d)
        : v{vv}, dist{d}
    {}

    bool operator<(const dijk& rhs) const {
        return rhs.dist < this->dist;
    }
};

vector<int> dijkstra(int start)
{
    vector<bool> found(graph.size(), false);
    vector<double> dist(graph.size(), -1.0);
    vector<int> pred(graph.size(), -1);

    auto cmp = [](const dijk& d1, const dijk& d2) {
        return d2.dist < d1.dist;
    };

    priority_queue queue(cmp, vector<dijk>());

    dist[start] = 0.0;
    pred[start] = start;

    queue.push({ start, 0.0 });

    while (! queue.empty()) {
        //set cur = min dist such vertex
        auto d = queue.top();
        queue.pop();

        int cur = d.v;
        if (found[cur])
            continue;

        found[cur] = true;

        for (auto e : graph[cur].edges) {
            if (dist[e.dest] == -1 || dist[cur] + e.w < dist[e.dest]) {
                dist[e.dest] = dist[cur] + e.w;
                pred[e.dest] = cur;
                queue.push({ e.dest, dist[e.dest] });
            }
        }
    }
    return pred;
}

void print_path(int dest, const vector<int>& pred) {
    stack<int> path;
    if (pred[dest] == -1) {
        cout << "no path to " << dest << endl;
        return;
    }
    while (pred[dest] != dest) {
        path.push(dest);
        dest = pred[dest];
    }

    path.push(dest);

    while (!path.empty()) {
        cout << path.top() << endl;
        path.pop();
    }
}

// all pairs shortest paths.

vector<vector<double>> floyd_warshall() {
    int n = graph.size();

    vector<vector<double>> m;
    m.resize(n);
    for (int i=0; i<n; ++i) {
        m[i].resize(n);
        for (int j=0; j<n; ++j)
            m[i][j] = -1.0;
    }

    for (int i=0; i<n; ++i) {
        for (const auto& e : graph[i].edges) {
            m[i][e.dest] = e.w;
        }
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; ++i) {
            if (m[i][k] == -1)
                continue;
            for (int j = 0; j < n; ++j) {
                if (m[k][j] == -1)
                    continue;
                if (m[i][j] == -1.0 || m[i][k] + m[k][j] < m[i][j]) {
                    m[i][j] = m[i][k] + m[k][j];
                }
            }
        }
    }

    return m;
}









struct mst_edge {
    int u;
    int v;
    double w;

    bool operator<(const mst_edge& other) {
        if (w < other.w) {
            return true;
        }
        else if (w == other.w && u < other.u) {
            return true;
        }
        else if (w == other.w && u == other.u && v < other.v) {
            return true;
        }
        else {
            return false;
        }
    }

    bool operator==(const mst_edge& other) const {
        return (w == other.w && u == other.u && v == other.v);
    }

    bool operator<(const mst_edge& other) const {
        return this->w < other.w;
    }
};

vector<vertex> mst(const vector<vertex>& graph) {
    set<mst_edge> edge_set;

    for (const vertex& v : graph) {
        for (const edge& e : v.edges) {
            int a = min(v.idx, e.dest);
            int b = max(v.idx, e.dest);
            edge_set.insert({a, b, e.w});
        }
    }

    DisjointSet ds(graph.size());
    vector<vertex> mst;
     for (int i=0; i<graph.size(); ++i) {
        mst.push_back(vertex(i));
    }

    int edge_count = 0;
    for (const mst_edge& e : edge_set) {
        if (! ds.are_joined(e.u, e.v)) {
            ds.join(e.u, e.v);
            mst[e.u].edges.push_back({e.v, e.w});
            mst[e.v].edges.push_back({e.u, e.w});
            edge_count++;
            if (edge_count == graph.size() - 1)
                break;
        }
    }
    return mst;
}

