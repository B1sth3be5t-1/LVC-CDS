#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ifstream file1 {"../file1.txt"};
    ifstream file2 {"../file2.txt"};

    string line;

    vector<string> f1, f2;
    while (getline(file1, line)) f1.push_back(line);
    while (getline(file2, line)) f2.push_back(line);


    sort(f1.begin(), f1.end());
    sort(f2.begin(), f2.end());


    auto end1 = unique(f1.begin(), f1.end());
    auto end2 = unique(f2.begin(), f2.end());


    f1.erase(end1, f1.end());
    f2.erase(end2, f2.end());

    bool eq;

    if (f1.size() < f2.size()) 
        eq = equal(f1.cbegin(), f1.cend(), f2.cbegin());
    else 
        eq = equal(f2.cbegin(), f2.cend(), f1.cbegin());

    cout << ((eq) ? "The lists are the same" : "The lists are not the same") << endl;

}
