#include <string>
#include <vector>

#ifndef EVENT_H_
#define EVENT_H_

struct Event {
    std::string name;
    std::vector<std::string> 
    attendees;
};

#endif