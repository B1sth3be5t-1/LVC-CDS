#include <iostream>
#include <queue>

using namespace std;

/*
int main() {
    int n, lph;
    cin >> n >> lph;

    auto l = [](int a, int b){return a > b;};

    priority_queue<int, vector<int>, decltype(l)> pq(l);

    for (int i = 0; i < n; ++i){
        int inp;
        cin >> inp;
        pq.push(inp);
    }

    lph *= 5;

    int tot = 0, num = 0;

    while (tot <= lph) {
        int next = pq.top();
        pq.pop();

        if (next + tot <= lph) {
            num++;
            tot += next;
        }
        else break;
    }

    cout << num << endl;
}
*/