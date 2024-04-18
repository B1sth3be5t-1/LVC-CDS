#include <iostream>
#include <string>
#include <fstream>

#include "organization.h"
#include "event.h"

using namespace std;

const string output = "\n\nPick a number by entering it into the program:\n\t1) Enter event name\n\t2) Enter a person's name\n\t3) Quit";

void add_event(vector<Organization>& orgs, const string& line) {
        //gets event and org names
        string eName = line.substr(0, line.find('|'));
        string oName = line.substr(line.find('|') + 1);

        //creates new event
        Event e(eName);

        //loops through events
        for (auto& o : orgs)
            //if org already is in list
            if (o.get_name() == oName)
            {
                //add to list and kill method
                o.add_event(e);
                return;
            }

        //if org is not in event, create new org
        Organization o(oName);

        //adds event to org
        o.add_event(e);

        //add org to organization list
        orgs.push_back(o);
}

void put_attendee_in_event(vector<Organization>& orgs, const string& line) {
    //gets attendee and event names
    string aName = line.substr(0, line.find('|'));
    string eName = line.substr(line.find('|') + 1);

    //loop through orgs
    for (auto& o : orgs)
        if (o.is_sponsoring(eName) && o.add_attendee(eName, aName))
            return;
}

int main() {
    //list of orgs
    vector<Organization> orgs;
    //opens file to read in events
    ifstream file{"../events.txt"};
    string line;

    //add events to orgs
    while (getline(file, line)) 
        add_event(orgs, line);
    
    //opens file with attendees
    ifstream file2{"../attendees.txt"};

    //adds attendees to event
    while (getline(file2, line)) 
        put_attendee_in_event(orgs, line);

    //"\n\nPick a number by entering it into the program:\n\t1) Enter event name\n\t2) Enter a person's name\n\t3) Quit";
    //start user choices
    int choice = 0;
    string choiceStr;

    do {
        //used in 1 and 2 for if input was found or not
        bool found = false;
        string str;

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
                //reset found
                found = false;
                cout << "Please enter an event name: " << endl;
                getline(cin, str);
                cout << "\n\n\n\n" << endl;
                //loop through orgs
                for (const auto& o : orgs)
                    //if org is sponsoring the event
                    if (o.is_sponsoring(str))
                    {
                        //output general statement
                        cout << str << " is sponsored by: " << o.get_name() << ", and here are attendees:" << endl;
                        //get attendee list
                        vector<string> atts = o.get_attendee_list(str);
                        //output attendees
                        for (const string& att : atts) cout << "\t" << att << endl;
                        //event was found
                        found = true;
                        break;
                    }
                //if event wasnt found output statement
                if (!found)
                    cout << "That event was not found" << endl;
                break;
            case 2:
                //reset found
                found = false;
                cout << "Please enter a person's name: " << endl;
                getline(cin, str);
                cout << "\n\n\n\n" << endl;
                //loop through orgs
                for (const auto& o : orgs)
                {
                    //get events in which input str (name) is attending
                    vector<Event> events = o.attending_events(str);
                    //output event name, and set found (name) to true
                    for (const auto& e : events)
                    {
                        cout << str << " is attending " << e.get_name() << endl;
                        found = true;
                    }
                }
                //if name was not found, output statement
                if (!found) cout << str << " is not attending any events." << endl;
                break;
            case 3:
                //skip this and goes to end of loop
                break;
            //user is silly and didnt input 1-3
            default:
                cout << "\n\n\n\n" << endl;
                cout << "Please enter a number 1, 2, or 3: " << endl;
        }
    } while (choice != 3);

    cout << "Thanks for using!" << endl;
}
