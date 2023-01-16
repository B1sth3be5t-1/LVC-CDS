#include <iostream>
#include <unordered_map>
#include <string>
#include <fstream>

using namespace std;

int main() {
    
    ifstream file {"../hours.txt"};
    unordered_map<string, int> stud_hours;

    string name;
    int hours;

    while (file >> name >> hours)
        stud_hours[name] += hours;

    
    while (true)
    {
        cout << "Enter a student name: ";
        cin >> name;

        if (name == "quit") break;

        auto it = stud_hours.find(name);

        if (it == stud_hours.cend())
            cout << "That student has not submitted any hours" << endl;
        else 
            cout << name << " has submitted " << it->second << " hours." << endl;
    }


}
