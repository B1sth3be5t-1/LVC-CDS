#include <iostream>
#include <vector>
#include <string>
#include "transaction.h"
// NEVER INCLUDE SOURCE FILE
// #include "second.cpp"


using std::vector, std::string, std::cout, std::endl;






int main() {
    vector<string> vec;

    using itr = vector<string>::iterator;
    //code that puts in vec

    //old version
    for (itr it = vec.begin(); it != vec.end(); ++it)
        cout << *it << endl;

    //auto version
    for (auto it = vec.begin(); it != vec.end(); ++it)
        cout << *it << endl;

    //new version (that can CHANGE STRINGS)
    for (auto& s : vec)
        cout << s << endl;

    Transaction data1;
    //access field (or data member)
    data1.id = "ugly desk with broken computer thing";



}
