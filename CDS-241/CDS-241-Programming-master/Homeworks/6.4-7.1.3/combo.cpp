#include <string>
#include "combo.h"

using namespace std;

//This totally can return an int, it takes two unique parameters, so a call to combine
//with two int parameters will initially start with a search for two int parameters, and
//will find this function first. 
//If this took two const string references, then it would be illegal because there are two 
//functions that take two const string references as parameters
int combine(int i1, int i2){
    int ret;
    ret += i1;
    ret += i2;
    return ret;
}

/*

this was:
string combine(int i1, int i2) {
    string ret;
    ret += std::to_string(i1);
    ret += to_string(i2);
    return ret;
}

*/

string combine(const string& s1, const string& s2) {
    string ret;
    ret += s1;
    ret += s2;
    return ret;
}

string combine(const string& s1, int i1) {
    string ret;
    ret += s1;
    ret += to_string(i1);
    return ret;
}

