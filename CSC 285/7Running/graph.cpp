#include <iostream>
#include <vector>
#include <array>
#include <fstream>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>

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


vector<bool> dfs(int start) {
    vector<bool> reachable(graph.size(), false);
    
    stack<int> s;
    s.push(start);
    reachable[start] = true;

    while (!s.empty()) {
        int cur = s.top(); 
        s.pop();

        for (const auto& e : graph[cur].edges) {
            if (! reachable[e.dest]) {
                s.push(e.dest);
                reachable[e.dest] = true;
            }
        }
    }   
    return reachable;
}

vector<bool> bfs(int start) {
    vector<bool> reachable(graph.size(), false);

    queue<int> q;
    q.push(start);
    reachable[start] = true;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (const auto& e : graph[cur].edges) {
            if (! reachable[e.dest]) {
                q.push(e.dest);
                reachable[e.dest] = true;
            }
        }
    }
    return reachable;
}

vector<int> top_sort() {
    vector<int> degrees;
    for (int i=0; i<graph.size(); ++i)
        degrees.push_back(0);

    for (vertex& v : graph) {
        for (edge& e : v.edges) {
            ++degrees[e.dest];
        }
    }

    stack<int> guys;
    for (int i=0; i<degrees.size(); ++i) {
        if (degrees[i] == 0)
            guys.push(i);
    }

    guys.push(0);

    vector<int> ret;

    while (! guys.empty()) {
        int cur = guys.top(); guys.pop();
        ret.push_back(cur);
        for (edge& e : graph[cur].edges) {
            --degrees[e.dest];
            if (degrees[e.dest] == 0) {
                guys.push(e.dest);
            }
        }
    }

    return ret;
}



int main() {
    int n;
    string sn;
    getline(cin, sn);
    n = stoi(sn);

    vector<pair<string, string>> lis;
    map<string, int> map;
    vector<string> searchList;
    int count = 0;

    for (int i = 0; i < n; i++) {
        string s, d;
        string comb;
        getline(cin, comb);
        s = comb.substr(0, comb.find(" "));
        d = comb.substr(comb.find(" ") + 1);
        if (map.find(s) == map.end())
            map[s] = count++;
        if (map.find(d) == map.end())
            map[d] = count++;

        lis.push_back(pair(s, d));
    }

    string line;

    while (getline(cin, line)) {
        if (line == "/e") break;
        searchList.push_back(line);
    }

    for (int i=0; i<map.size(); ++i) {
        graph.push_back(vertex(i));
    }

    for (pair<string, string> p : lis) {
        int u = map[p.first];
        int v = map[p.second];
        graph[u].edges.push_back(edge(v, 1));
    }

    vector<int> cycles;

    //this loop is wrong. will fix later

    vector<int> order = top_sort();

    for (int i : order) cout << i << endl;

    for (string s : searchList) {
        int num = map[s];
        if (std::find(cycles.begin(), cycles.end(), num) != cycles.end()) cout << s << " safe" << endl;
        else cout << s << " trapped" << endl;
    }

}

/*
 * 6
Arlington San_Antonio
San_Antonio Baltimore
Baltimore New_York
New_York Dallas
Dallas Arlington
Baltimore Arlington
San_Antonio
Baltimore
New_York
Dallas

 */
