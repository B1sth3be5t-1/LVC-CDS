#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

int main() {

    vector<int> nums {1,4,6,8,10,11,12};
    auto it = nums.begin();
    while (*it++ % 2 == 0);

    --it;
    cout << *it << endl;

}
