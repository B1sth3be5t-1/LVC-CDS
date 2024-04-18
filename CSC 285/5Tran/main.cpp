#include <iostream>
#include <vector>

using namespace std;





int get_longest_from_train(vector<int>& trains, int curTrain, int begin, int end, vector<int>& beginMemo, vector<int>& endMemo, vector<int>& nullMemo) {
    //base case
    if (curTrain >= trains.size()) return 0;

    //get tren
    int trainWeight = trains[curTrain];

    //first train?
    if (begin == 0 && end == 0) {
        int putInTrain, dont;

        beginMemo[trainWeight] = 1;
        endMemo[trainWeight] = 1;
        nullMemo[trainWeight] = 0;

        putInTrain = 1 + get_longest_from_train(trains, curTrain + 1, trainWeight, trainWeight, beginMemo, endMemo, nullMemo);
        dont = get_longest_from_train(trains, curTrain + 1, 0, 0, beginMemo, endMemo, nullMemo);

        return max(putInTrain, dont);
    }

    int begWeight, endWeight, nullWeight;
    begWeight = 0;
    endWeight = 0;
    nullWeight = 0;

    if (trainWeight < begin && beginMemo[trainWeight] == -1)
    {
        begWeight = 1 + get_longest_from_train(trains, curTrain + 1, trainWeight, end, beginMemo, endMemo, nullMemo);
        beginMemo[trainWeight] = begWeight;
    }
    if (trainWeight > end && endMemo[trainWeight] == -1)
    {
        endWeight = 1 + get_longest_from_train(trains, curTrain + 1, begin, trainWeight, beginMemo, endMemo, nullMemo);
        endMemo[trainWeight] = endWeight;
    }
    if (nullMemo[trainWeight] == -1)
    {
        nullWeight = get_longest_from_train(trains, curTrain + 1, begin, end, beginMemo, endMemo, nullMemo);
        nullMemo[curTrain] = nullWeight;
    }


    return max(max(nullMemo[trainWeight], endMemo[trainWeight]), beginMemo[trainWeight]);
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

    vector<int> beginMemo, endMemo, nullMemo;

    beginMemo.assign(10000, -1);
    endMemo.assign(10000, -1);
    nullMemo.assign(10000, -1);

    int weight = get_longest_from_train(trains, 0, 0, 0, beginMemo, endMemo, nullMemo);

    cout << weight << endl;

}
