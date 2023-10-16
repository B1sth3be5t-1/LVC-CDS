#include <iostream>
#include <vector>

using namespace std;



int get_longest_from_train(vector<int>& trains, int curTrain, int begin, int end) {
    //base case
    if (curTrain >= trains.size()) return 0;

    //get tren
    int trainWeight = trains[curTrain];

    //first train?
    if (begin == 0 && end == 0) {
        int putInTrain, dont;
        putInTrain = dont = 0;

        putInTrain = 1 + get_longest_from_train(trains, curTrain + 1, trainWeight, trainWeight);
        dont = get_longest_from_train(trains, curTrain + 1, 0, 0);
        return max(putInTrain, dont);
    }

    int begWeight, endWeight, nullWeight;
    begWeight = endWeight = nullWeight = 0;

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

    cout << weight << endl;

}
