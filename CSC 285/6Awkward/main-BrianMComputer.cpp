#include <iostream>
#include <map>

using namespace std;

int main() {
    int numSeats;
    cin >> numSeats;
    std::map<int, int> map;


    int minDis = -1;
    int index = 0;

    for (int i = 0; i < numSeats; i++) {
        int num;
        cin >> num;

        if (map.find(num) != map.end() && (minDis == -1 || index - map[num] < minDis)) {
            minDis = index - map[num];
        }

        if (minDis == 1) {
            cout << 1;
            return 0 ;
        }

        map[num] = index;

        index++;
    }

    if (map.size() == numSeats) {
        cout << numSeats;
        return 0;
    }

    cout << minDis;
}
