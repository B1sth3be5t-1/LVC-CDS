#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
    ifstream file("../strings.txt");
    string category, line;
    unordered_map<string, int> categories;

    while (getline(file, line))
    {
        category = line.substr(line.find(',') + 2);
        ++categories[category];
    }
    
    for (const auto& c : categories)
        cout << c.first << " had " << c.second << " searches." << endl;
}
