#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <random>

using namespace std;

void generate_random_data(const string& file_name, int size) {

    ofstream file(file_name);

    default_random_engine rand_engine;
    uniform_real_distribution<double> dist(-1000.0, 1000.0);

    for (int i = 0; i < size; ++i)
        file << dist(rand_engine) << endl;
    
}

vector<double> positives(const vector<double>& v) {
    vector<double> pos;
    copy_if(v.cbegin(), v.cend(), back_inserter(pos), 
                    [](double d) {return d > 0;});

    return pos;
};

bool test_all_positive(const vector<double>& v){
    return any_of(v.cbegin(), v.cend(), [](double d){return d < 0;});
}

int main() {

    string name = "../nums.txt";
    generate_random_data(name, 1000000);

    ifstream file(name);
    vector<double> nums;
    double val;

    while (file >> val)
        nums.push_back(val);



    vector<double> pos = positives(nums);

    cout << "size: " << pos.size() << endl;

    bool allPos = test_all_positive(pos);

    cout << "All pos: " << allPos << endl;

}
