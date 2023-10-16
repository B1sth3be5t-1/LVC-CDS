#include <iostream>
#include <vector>

using namespace std;

int get_longest_from_train(vector<int>& trains, int curTrain, int begin, int end) {
    if (begin == 0 && end == 0) {
        int putInTrain, dont;


    }

    //base case
    if (curTrain >= trains.size()) return 0;

    //get tren
    int trainWeight = trains[curTrain];

    int begWeight, endWeight, nullWeight;

    if (trainWeight < begin)
        begWeight = 1 + get_longest_from_train(trains, curTrain + 1, trainWeight, end);
    if (trainWeight > end)
        endWeight = 1 + get_longest_from_train(trains, curTrain + 1, begin, trainWeight);
    nullWeight = get_longest_from_train(trains, curTrain + 1, begin, end);

    return max(max(begWeight, endWeight), nullWeight);
}


int main() {
    int numTrains;

    vector<int> trains;

    cin >> numTrains;

    for (int i = 0; i < numTrains; ++i) {
        int tren;
        cin >> tren;
        trains.push_back(tren);
    }

    int weight = get_longest_from_train(trains, 0, 0, 0);



}
