#include <string>
#include <vector>

#include "event.h"

using namespace std;

Event::Event(const string& n) : name(n) {};

void Event::add_attendee(const string& n) {attendees.push_back(n);}

bool Event::is_attending(const string& aName) const {
    //loop through all attendees
    for (auto name : attendees)
    //if name matches, return true
        if (name == aName)
            return true;
    //else at end of loop, return false
    return false;
}

//sets the event name
void Event::set_name(const string& n) {name = n;}