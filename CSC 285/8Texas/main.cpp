#include <iostream>
#include <vector>
#include <array>
#include <queue>
#include <stack>
#include <cmath>

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



int main() {
    int N;
    cin >> N;

    class shade {
        int x, y;
    public:
        shade(int xLoc, int yLoc) : x{xLoc}, y{yLoc} {}
        double const getDis(shade& other) {return sqrt(pow(other.x - x, 2) + pow(other.y - y, 2));}
    };

    vector<shade> shades;
    shades.reserve(N + 2);
    graph.reserve(N + 2);

    for (int i=0; i<N + 2; ++i) {
        int x, y;
        cin >> x >> y;
        graph.push_back(vertex(i));
        shades.push_back(shade(x, y));
    }


    for (int s=0; s < N + 2; ++s) {
        for (int o=0; o < N + 2; ++o) {
            if (s == o) continue;
            double d = shades[s].getDis(shades[o]);
            graph[s].edges.push_back(edge(o, pow(d, 2)));
        }
    }



    vector<int> di = dijkstra(N);

    deque<int> print;

    int pred = di[N + 1];
    while (pred != N) {
        print.push_front(pred);
        pred = di[pred];
    }

    for (int i : print) cout << i << endl;

    if (print.size() == 0) cout << "-" << endl;
}
