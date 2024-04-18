#ifndef DISJOINTSET_H
#define DISJOINTSET_H
#include <vector>

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
    std::vector<int> d;
};

#endif
