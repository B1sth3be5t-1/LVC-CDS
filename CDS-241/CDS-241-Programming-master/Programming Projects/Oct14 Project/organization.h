#include <string>
#include <vector>
#include "event.h"

#ifndef ORGANIZATION_H_
#define ORGANIZATION_H_

struct Organization {
    std::string name;
    std::vector<Event> events;
};

#endif