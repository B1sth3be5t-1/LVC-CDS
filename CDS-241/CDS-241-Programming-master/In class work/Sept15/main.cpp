#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {
    ifstream file {"../file.txt"};
    string line, first;

    if (!file) {
        cout << "File not found" << endl;
        return 0;
    }

    
    getline(file, first);
    while (getline(file, line))
        if (line <= first)
            first = line;

    cout << first << endl;

    
        
}
