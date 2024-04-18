#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct person {
    int rank, start, end;
    person(int r, int s, int e) : rank{r}, start{s}, end{e} {}
};

struct team {
    person a, b, c;
    team(person& an, person& bn, person& cn) : a{an}, b{bn}, c{cn} {}

    [[nodiscard]] int find_min() const {return min(a.rank, min(b.rank, c.rank));}
    [[nodiscard]] int find_max() const {return max(a.rank, max(b.rank, c.rank));}
};

int main() {
    int n;
    cin >> n;

    vector<person> lis = {};

    int num = 1;
    for (int i = 0; i < n; ++i) {
        int s, e;
        cin >> s >> e;
        lis.emplace_back(num++, s, e);
    }

    vector<team> teams = {};

    for (int i = 0; i < lis.size() - 2; ++i) {
        for (int j = i + 1; j < lis.size() - 1; ++j) {
            for (int k = j + 1; k < lis.size(); ++k) {
                person& a = lis[i];
                person& b = lis[j];
                person& c = lis[k];

                bool cInRange = (c.rank >= a.start && c.rank >= b.start && c.rank <= a.end && c.rank <= b.end);
                bool aInRange = (a.rank >= c.start && a.rank >= b.start && a.rank <= c.end && a.rank <= b.end);
                bool bInRange = (b.rank >= a.start && b.rank >= c.start && b.rank <= a.end && b.rank <= c.end);

                if (cInRange && aInRange && bInRange)
                    teams.emplace_back(lis[i], lis[j], lis[k]);
            }
        }
    }

    sort(teams.begin(), teams.end(),
         [](team const& a, team const& b){return a.find_max() < b.find_max();});

    int tot = 0;

    if (teams.size() >= 1)
        tot = 1;

    int r1 = teams[0].find_max();
    for (int i = 1; i < teams.size(); ++i) {
        int l1 = teams[i].find_min();
        int r2 = teams[i].find_max();


        if (l1 > r1) {
            tot++;
            r1 = r2;
        }
    }

    cout << tot << endl;
}
/*
6
1 3
1 3
1 3
2 6
2 6
2 6


 */
