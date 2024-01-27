#include <iostream>
#include <vector>

using namespace std;

/*
int main() {
    int num = 0, min = 0, max = 0;

    cin >> num >> min >> max;

    vector<int> log = {};

    for (int i = 0; i < num - 1; ++i) {
        int n;
        cin >> n;
        log.push_back(n);
    }

    bool usedMin = false;
    bool usedMax = false;

    for (int i : log) {
        if (i == min)
            usedMin = true;
        if (i == max)
            usedMax = true;
        if (i < min || i > max) {
            cout << -1 << endl;
            return 0;
        }
    }

    if ((!usedMin && !usedMax) && (min != max))
        cout << -1 << endl;
    else if ((!usedMin && !usedMax) && (min == max))
        cout << min << endl;
    else if (!usedMin) cout << min << endl;
    else if (!usedMax) cout << max << endl;
    else
        for (int i = min; i <= max; ++i)
            cout << i << endl;
}

*/
