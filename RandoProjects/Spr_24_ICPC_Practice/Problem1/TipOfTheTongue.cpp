#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
int main() {

    int n = 0, q = 0;

    cin >> n >> q;

    vector<string> words = {};

    string dummy;
    getline(cin, dummy);

    for (int i = 0; i < n; ++i) {
        string word;
        getline(cin, word);
        words.push_back(word);
    }

    for (int i = 0; i < q; ++i) {
        string str;
        getline(cin, str);

        string op = str.substr(0, str.find(' '));
        str = str.substr(str.find(' ') + 1);
        string f = str.substr(0, str.find(' '));
        str = str.substr(str.find(' ') + 1);
        string l = str;

        int tot = 0;

        for (const string& word : words) {
            bool pref = word.length() >= f.length() && word.substr(0, f.length()) == f;
            bool suff = word.length() >= l.length() && word.substr(word.length() - l.length()) == l;

            if (op == "AND") {
                if (pref && suff)
                    ++tot;
            }
            else if (op == "OR") {
                if (pref || suff)
                    ++tot;
            }
            else if (op == "XOR") {
                if ((pref || suff) && !(pref && suff))
                    ++tot;
            }
        }
        cout << tot << endl;
    }


}
*/
/*
1 2
and
AND a d
OR anda dead



 */