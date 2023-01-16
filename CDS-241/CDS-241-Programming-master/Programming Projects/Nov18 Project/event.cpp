#include <string>
#include <vector>
#include <algorithm>

#include "event.h"

using namespace std;

Event::Event(const std::string& name, const std::string& org) : 
    name(name), org(org) {}; //I'm a little surprised to see this works

void Event::add_attendee(const std::string& attendee) {
    attendees.push_back(attendee);
}

bool Event::is_attending(const std::string& attendee) const {
    return (find(attendees.begin(), attendees.end(), attendee) == attendees.end()) 
    ? false : true; 
}