#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int, char**) {
    #13
    /*

    (a) vector<int> v1; -> empty vector
    (b) vector<int> v2(10); -> vector of length 10 with elements all 0
    (c) vector<int> v3(10, 42); -> vector of length 10 with elements all 42
    (d) vector<int> v4{10}; -> vector of length 1 with element 10
    (e) vector<int> v5{10, 42}; -> vector of length 2 with elements 10 and 42
    (f) vector<string> v6{10}; -> vector of length 10 with elements all default initialized strings
    (g) vector<string> v7{10, "hi"}; -> vector of length 10 with elements all "hi"
    */




    #18

    /*
    vector<int> ivec;
    ivec[0] = 42;

    This is not legal because the vector contains no elements, so trying to assign a 
        value will produce an error. We can fix this by using push_back() to add a numbers
        to the vector, and then we can reassign it. 
    */



    #23
    vector<int> ivec {10, 42, 1, 123, 59, 328, 12, 3, 1289, 2459};
    for (auto it = ivec.begin(); it != ivec.end(); ++it)
        *it *= 2;

    for (auto i : ivec) 
        cout << i << ' ';

    cout << endl;
    

    
    
    vector<string> strs;
    string str, line, word;
    cout << "Enter a line: ";
    getline(cin, line);

    for (char str : line) {
        if (str != ' ') 
            word += str;
        else {
            strs.push_back(word);
            word = "";
        }
    }
    strs.push_back(word);
        
    

    for (int i = 0; i < strs.size(); ++i)
        if (isupper((strs[i])[0]))
            cout << strs[i] << "\t";
    
    cout << endl;

    for (auto it = strs.begin(); it != strs.end(); ++it)
        if (it->size() >= 10) 
            cout << *it + "\t";

    cout << endl;

    for (auto &s : strs)
    {
        s[0] = tolower(s[0]);
    }


    for (auto s : strs) cout << s + "\t";
}
