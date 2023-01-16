#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

int main() {
    
    vector<string> strs;

    {//Just to input stuff from file into strs
    ifstream f {"../words.txt"};
    string line;

    while (getline(f, line)) strs.push_back(line);
    }

    vector<int> lengths;
    lengths.reserve(strs.size()); // sets length's capacity to that of strs.size()
    transform(strs.cbegin(), strs.cend(), lengths.begin(), //Or could use back_inserter
                    [] (const string& str) { return str.size(); });    

    for (int i = 0; i < strs.size(); ++i)
        cout << strs[i] << ": " << lengths[i] << " characters." << endl;

    /*
        Captures allow us to either pass in external variables to a lambda, or to get data
        out of a lambda. We can either do this through reference, or through copy. If we want
        to call a lambda and return a value to copy into something else, we can use a lambda 
        set up as: auto wc = [=, &strs] () {return strs.size();}; This takes the reference of 
        strs and uses the lambda .size() to return a value that we capture (by copy) into wc.
        We can also capture the result of a lambda by reference with the form [&] (){something};
        This will perform the lambda and send out the result's reference to be captured by a
        variable in the program.
    */


}
