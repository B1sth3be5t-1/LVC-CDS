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

std::map<int, bool> top_sort() {
    vector<int> degrees;
    for (int i=0; i<graph.size(); ++i)
        degrees.push_back(0);

    for (vertex& v : graph) {
        for (edge& e : v.edges) {
            ++degrees[e.dest];
        }
    }

    queue<int> guys;
    for (int i=0; i<degrees.size(); ++i) {
        if (degrees[i] == 0)
            guys.push(i);
    }

    if (guys.size() == 0) guys.push(0);

    std::map<int, bool> ret;

    while (! guys.empty()) {
        int cur = guys.front(); guys.pop();

        vector<bool> bools = dfs(cur);
        bool canGetToSelf = bools[cur];

        int dup = 0;
        if (ret.count(cur) != 0)
            dup++;

        if (ret.count(cur) == 0) {
            ret[cur] = canGetToSelf;
            cout << cur << ": canGetToSelf - " << canGetToSelf << endl;
        }

        int lastDest = 0;

        for (edge& e : graph[cur].edges) {
            --degrees[e.dest];
            if (degrees[e.dest] == 0) {
                guys.push(e.dest);
            }
            lastDest = e.dest;
        }

        if (guys.size() == 0 && ret.size() < graph.size() + dup)
            guys.push(lastDest);
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

    std::map<int, bool> order = top_sort();



    for (string s : searchList) {
        int num = map[s];
        if (std::find(cycles.begin(), cycles.end(), num) != cycles.end()) cout << s << " safe" << endl;
        else cout << s << " trapped" << endl;
    }

}

/*
 * 12
Arlington San_Antonio
San_Antonio Baltimore
Baltimore New_York
New_York Dallas
Baltimore Arlington
Pennsylvania San_Antonio
New_York Zebra
Zebra Constantinople
Tennessee Pennsylvania
Fragment New_York
Baltimore Fragment
Constantinople New_York
San_Antonio
Baltimore
New_York
Dallas
 */
