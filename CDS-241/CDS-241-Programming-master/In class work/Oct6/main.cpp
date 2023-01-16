#include <iostream>
#include <string>

using namespace std;

void censor(string& s, char ch) {
    for (int i = 0; i < s.size(); ++i)
        if (s[i] == ch)
            s[i] = '*';
}

int main() {
    
    string s = "Bubba";
    censor(s, 'b');
    cout << s << endl;

}
