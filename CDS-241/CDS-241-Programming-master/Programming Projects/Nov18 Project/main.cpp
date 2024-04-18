#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <memory>
#include <algorithm>
#include <unordered_map>

#include "event.h"

using namespace std;

vector<shared_ptr<Event>> getEvents() {
    ifstream file {"../events.txt"};
    string line;
    vector<shared_ptr<Event>> events;

    while (getline(file, line)) {
        string name = line.substr(0, line.find('|'));
        string org = line.substr(line.find('|') + 1);

        events.push_back(make_shared<Event>(name, org));
    }

    return events;
}

unordered_map<string, vector<shared_ptr<Event>>> make_map(vector<shared_ptr<Event>>& events) {
    unordered_map<string, vector<shared_ptr<Event>>> map;

    ifstream file {"../attendees.txt"};
    string line, aName, eName;

    while (getline(file, line)) {
        aName = line.substr(0, line.find('|'));
        eName = line.substr(line.find('|') + 1);

        //gets the pointer to the event with given name
        shared_ptr<Event> e = *(find_if(events.begin(), events.end(), 
                    [eName](const shared_ptr<Event>& e){return e->get_name() == eName;}));

        //add person to event
        e->add_attendee(aName);  
        
        //push_back the event to the aName spot in the map
        map[aName].push_back(e);
    }

    return map;
}

int main() {
    vector<shared_ptr<Event>> events = getEvents();
    unordered_map<string, vector<shared_ptr<Event>>> map = make_map(events);

    const string output = "\n\nPick a number by entering it into the program:\n\t1) Enter event name\n\t2) Enter student's name to print events attending\n\t3) Enter student's name to print organizations\n\t4) Quit program";
    //start user choices
    int choice = 0;
    string choiceStr;

    do {
        string inp;
        //output general choices
        cout << output << endl;
        //get user input in str form (for ease of programming)
        getline(cin, choiceStr);
        //try to convert to int, if error set choice to -1 so loop repeats
        try {
            choice = stoi(choiceStr);
        } catch (exception &err) {
            choice = -1;
        }
        //based on choice
        switch (choice) {
            case 1:
            {
                cout << "Enter event name" << endl;
                getline(cin, inp);
                shared_ptr<Event> e;
                e = *(find_if(events.begin(), events.end(), 
                                [inp](shared_ptr<Event>& e) {return inp == e->get_name();}));

                if (e == nullptr)
                {
                    cout << "Error: No event found" << endl;
                    break;
                }

                vector<string> attendees;
                
                for (auto& p : map)
                {
                    const string name = p.first;
                    const vector<shared_ptr<Event>> vec = p.second;

                    if (find(vec.begin(), vec.end(), e) != vec.end()) 
                        attendees.push_back(name);
                }

                cout << "Attendees for " << e->get_name() << " are: " << endl;
                for (const auto& s : attendees) 
                    cout << "\t" << s << endl;
            }
                break; 
            case 2:
                cout << "Enter student name" << endl;
                getline(cin, inp);
                if (map.find(inp) == map.end()) {
                    cout << "Error: No such student found in map" << endl;
                    break;
                }

                for (const auto& e : map[inp]) {
                    cout << "Student is attending " << e->get_name() << " which has " 
                    << e->num_attending() << " attendees" << endl;
                }
                break;
            case 3:
            {
                cout << "Enter student name" << endl;
                getline(cin, inp);
                if (map.find(inp) == map.end()) {
                    cout << "Error: No such student found in map" << endl;
                    break;
                }

                vector<string> orgNames;

                for (const auto& e : map[inp])
                    if (find(orgNames.begin(), orgNames.end(), e->organization()) == orgNames.end())
                        orgNames.push_back(e->organization());
                
                cout << "Student is attending events hosted by: " << endl;
                for (const auto& s : orgNames)
                    cout << "\t" << s << endl;
                
            }
                break;
            case 4:
                break;
            //user is silly and didnt input 1-4
            default:
                cout << "\n\n\n\n" << endl;
                cout << "Please enter a number 1 - 4: " << endl;
        }
    } while (choice != 4);

    cout << "Thanks for using!" << endl;
}
