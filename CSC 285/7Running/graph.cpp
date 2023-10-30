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


bool dfs(int start) {
    //0 is non-explored, 1 is exploring, 2 is finished
    vector<int> reachable(graph.size(), 0);

    stack<int> s;
    s.push(start);


    while (!s.empty()) {
        int cur = s.top();
        s.pop();
        reachable[cur] = 1;

        for (const auto& e : graph[cur].edges) {
            if (reachable[e.dest] != 2) {
                //push here, is in progress
                if (reachable[e.dest] == 1)
                    return true;
                s.push(e.dest);
                reachable[e.dest] = 1;
            }
        }
    }
    return false;
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



    for (string s : searchList) {
        int num = map[s];

        bool dfss = dfs(num);

        if (dfss) cout << s << " safe" << endl;
        else cout << s << " trapped" << endl;
    }

}

/*
 * 13
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
Dallas x-ray
x-ray
Dallas
Arlington
San-Antonio
Baltimore
New_York
Pennsylvania
Zebra
Constantinople
Fragment
 */
