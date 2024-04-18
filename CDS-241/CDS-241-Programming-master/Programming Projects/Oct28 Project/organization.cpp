#include <string>
#include <vector>

#include "organization.h"
#include "event.h"

using namespace std;

Organization::Organization(const string& n) : name(n) {};

void Organization::add_event(Event& e) { events.push_back(e); }

bool Organization::add_attendee(const string& eName, const string& aName) {
    for (auto& e : events) {
        if (e.get_name() == eName)
        {
            e.add_attendee(aName);
            return true;
        }
    }

    return false;
}

bool Organization::is_sponsoring(const string& eName) const {
    for (const auto& e : events)
        if (e.get_name() == eName)
            return true;
    
    return false;
}

vector<Event> Organization::attending_events(const string& aName) const {
    vector<Event> events;
    for (auto e : this->events)
        if (e.is_attending(aName))
            events.push_back(e);

    return events;
}

vector<string> Organization::get_attendee_list(const string& eName) const {
    vector<string> names;
    for (const auto& e : this->events)
        if (e.get_name() == eName)
        {
            //no way for us to get attendee list in event
            for (string name : e.get_copy_attendees()) //<----------------------------------------------------------------
                names.push_back(name);

            break;
        }

    return names;
}

