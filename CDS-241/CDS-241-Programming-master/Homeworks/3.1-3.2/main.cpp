#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;

int main(int, char**) {
    //3.4
    
    cout << "Enter 2 strings: ";
    string s1, s2;
    cin >> s1 >> s2;
    cout << endl;

    if (s1 == s2) cout << "The strings are the same" << endl;
    else if (s1 > s2) cout << "s1 is > s2" << endl;
    else cout << "s1 is < s2" << endl;



    cout << "Enter 2 strings: ";
    string s3, s4;
    cin >> s3 >> s4;
    cout << endl;

    if (s3.size() == s4.size()) cout << "The strings are the same length" << endl;
    else if (s3.size() > s4.size()) cout << "s3.size() is > s4.size()" << endl;
    else cout << "s3.size() is < s4.size()" << endl;
    


    //3.10

    const string input ("hello there, this is a s@omewhat random str3am of characters@(!^$@# including punctuation");

    for (auto c : input)
        if (!ispunct(c))
            cout << c;
    cout << endl;

    const string s = "Keep out!";
    for (auto &c : s) { /* ... */ }

}
