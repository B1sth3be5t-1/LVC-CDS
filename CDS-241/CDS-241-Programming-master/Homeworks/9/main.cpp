#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

int main() {
    ifstream file{"../words.txt"};
    string word;
    vector<string> words;

    while (getline(file, word)) {
        bool added = false;
        for (auto it = words.begin(); it != words.end(); ++it) {
            if ((*it)[0] == word[0])
            {
                words.insert(it, word);
                added = true;
                break;
            }
        }
        if (added) continue;
        words.push_back(word);
    }


    for (auto word : words)
        cout << word << endl;
}
