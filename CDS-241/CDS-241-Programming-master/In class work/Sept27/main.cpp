#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    vector<int> vec;

    //fill vec
    vector<int> *other = &vec;
    // add nums in vec
    int sum = 0;
    for (auto i : *other) 
        sum += i;
    
    double avg = static_cast<double>(sum) / vec.size();

    
}
