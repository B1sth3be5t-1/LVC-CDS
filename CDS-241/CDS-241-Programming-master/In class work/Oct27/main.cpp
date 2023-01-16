#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

int main() {
   
    ifstream file {"../numbers.txt"};
    vector<int> nums;

    int in;

    while (file >> in)
        nums.push_back(in);


    auto it = remove(nums.begin(), nums.end(), 0);
    nums.erase(it, nums.end());


    rotate(nums.begin(), nums.begin()+5 ,nums.end());

    ofstream ofs {"../newNums.txt"};
    for (auto x : nums) ofs << x << endl;
}
