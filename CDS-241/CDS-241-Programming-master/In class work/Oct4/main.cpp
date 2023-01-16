#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

int main() {

    vector<string> w1, w2, dup;

    ifstream f1 {"../test1.txt"};
    ifstream f2 {"../test2.txt"};


    string s;

    while (getline(f1, s)) w1.push_back(s);
    while (getline(f2, s)) w2.push_back(s);

    for (auto s : w1) 
        for (auto s2 : w2) 
            if (s == s2) {
                bool repeated = false;
                for (auto found : dup)
                    if (found == s) {
                        repeated = true;
                        break;
                    }
                if (!repeated)
                    dup.push_back(s);
            }
        
    
    int count = 1;
    for (auto s : dup) {
        cout << count << ") " << s << endl;
        ++count;
    }

}
