#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <map>
#include <algorithm>

using namespace std;

string isRuler(vector<int>* v) {
    std::map<int, int> map;

    for (int i = 0; i < v->size(); i++) {
        for (int j = 0; j < v->size(); j++) {
            if (j == i) continue;

            int a = v->at(j);
            int b = v->at(i);
            map[abs(a - b)]++;
            if (map[abs(a - b)] > 2) return "not a ruler";
        }
    }

    std::map<int, int>::iterator it = map.begin();
    vector<int> nums;
    while(it != map.end()) {
        nums.push_back(it->first);
        ++it;
    }

    std::sort(nums.begin(), nums.end());
    if (nums.size() == nums.back()) return "perfect";

    string out = "missing ";

    int index = 0;
    for (int i = 1; i <= nums.back(); i++) {
        if (i != nums[index]) out += to_string(i) + " ";
        else index++;
    }

    return out.substr(0, out.length() - 1);
}


int main() {
    vector<vector<int>> rulers;

    string str;


    while (getline(cin, str)) {
        if (str.empty()) break;
        stringstream ss(str);
        string num;
        vector<int> v;
        while (getline(ss, num, ' ')) {
            v.push_back(stoi(num));
        }
        rulers.push_back(v);
    }

    for (vector<int> v : rulers) {
        cout << isRuler(&v) << endl;
    }
}


