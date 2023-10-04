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




int main() {
    int n;
    cin >> n;

    vector<pair<string, string>> lis;
    map<string, int> map;
    vector<string> searchList;
    int count = 0;

    for (int i = 0; i < n; i++) {
        string s, d;
        string comb;
        cin >> s >> d;
        if (map.find(s) == map.end())
            map[s] = count++;
        if (map.find(d) == map.end())
            map[d] = count++;

        lis.push_back(pair(s, d));
    }

    string line;

    while (getline(cin, line)) {
        searchList.push_back(line);
    }

    for(std::map<string, int>::iterator it = map.begin(); it != map.end();)
        if((it->second) == -1)
            it = map.erase(it);
        else
            it++;

    for (int i=0; i<map.size(); ++i) {
        graph.push_back(vertex(i));
    }

    for (pair<string, string> p : lis) {
        int u = map[p.first];
        int v = map[p.second];
        graph[u].edges.push_back(edge(v, 1));
    }

    vector<int> cycles;

    for (const auto& v : graph) {
        vector<bool> bools = dfs(v.idx);
        bool partOfCycle = true;
        for (bool b : bools) if (!b) {partOfCycle = false; break;}
        if (partOfCycle) cycles.push_back(v.idx);
    }

    for (string s : searchList) {
        if (s == "") continue;
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
