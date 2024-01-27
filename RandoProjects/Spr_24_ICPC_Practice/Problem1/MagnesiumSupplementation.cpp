#include <iostream>
#include <vector>

using namespace std;

/*
int main() {
    int n, k, p;

    cin >> n >> k >> p;

    // rules:
    // any output must be <= k
    // find all integers where n / p == 0

    vector<int> pq = {};

    for (int i = p; i > 0; --i) {
        if (n % i == 0 && k * i >= n)
            pq.push_back(n / i);
    }

    cout << pq.size() << endl;

    for (int i = 0; i < pq.size(); ++i) cout << pq[i] << endl;
}
*/