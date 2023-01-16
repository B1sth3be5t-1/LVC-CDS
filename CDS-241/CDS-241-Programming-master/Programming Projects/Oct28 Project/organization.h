#include <string>
#include <vector>

#include "event.h"

#ifndef __org__
#define __org__


class Organization {

    public:

    Organization() = default;
    Organization(const std::string& n);

    void add_event(Event& e);
    //this is a bool, such that if it is called and returns false, the event does not exist
    bool add_attendee(const std::string& eName, const std::string& aName); 
    bool is_sponsoring(const std::string& eName) const;

    std::vector<Event> attending_events(const std::string& aName) const;
    std::vector<std::string> get_attendee_list(const std::string& eName) const; 

    
    //should we have this?
    inline std::string get_name() const { return name; }


    private:
    std::string name;
    std::vector<Event> events;


};


#endif 