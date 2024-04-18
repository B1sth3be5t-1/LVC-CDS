#include <iostream>
#include <string>
#include "combo.h"
#include "log.h"

using namespace std;

int main() {
    string s1 = "Hello there ";
    string s2 = "comp sci student!";
    int i = 420;
    int j = 769;

    int comb1 = combine(i, j);
    cout << comb1 << endl;

    string comb2 = combine(s1, s2); 
    cout << comb2 << endl;

    string comb3 = combine(s1, i);
    cout << comb3 << endl;


    Log l1;
    string init = "10/12/21, 15:56, bjm008@lvc.edu, someIPThatIWontGiveYou, true";
    l1.from_string(init);
    cout << l1.to_string() << endl;

}
