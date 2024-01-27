#include <vector>

using namespace std;

class DisjointSet {
public:
    DisjointSet(int s);
    void join(int a, int b);
    bool are_joined(int a, int b);
    int largest_component();
    int num_sets();
private:
    int find(int a);
    int sz;
    vector<int> d;

};

DisjointSet::DisjointSet(int s)
        : sz {s}, d(sz, -1)
{
}
void DisjointSet::join(int a, int b) {
    int r1 = find(a);
    int r2 = find(b);
    if (r1 == r2)
        return;
// hang one tree off the other
    d[r2] += d[r1];
    d[r1] = r2;
    return;
}
bool DisjointSet::are_joined(int a, int b) {
    return find(a) == find(b);
}
int DisjointSet::largest_component() {
    int s = 0;
    for (auto r : d) {
        if (r < 0 && -r > s)
            s = -r;
    }
    return s;
}
int DisjointSet::num_sets() {
    int sum = 0;
    for (auto r: d)
        if (r < 0)
            sum++;
    return sum;
}
int DisjointSet::find(int a) {
    if (d[a] < 0)
        return a;
    return d[a] = find(d[a]);
}
