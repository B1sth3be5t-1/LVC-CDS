#include <iostream>
#include "GOB_Graph.h"

using namespace std;

int main() {
    GOB g("input.txt");
    vector<pair<string, double>> set = g.influencerRanking();

    int count = 0;
    for (auto s : set) {
        if (++count > 10) break;
        cout << "Influencer #" << count << " is: " << s.first << " with score: " << s.second << endl;
    }

}
