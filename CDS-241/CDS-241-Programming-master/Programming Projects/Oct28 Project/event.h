#include <string>
#include <vector>

#ifndef __event__
#define __event__


class Event {

    public:
    //default initialize
    Event() = default;
    //initialize with name
    Event(const std::string& n);

    //adds attendee to event
    void add_attendee(const std::string& aName);
    //returns if attendee is in event
    bool is_attending(const std::string& aName) const;
    //returns number of attendees in event
    inline int num_attending() const {return attendees.size();}

    //returns name of event
    inline std::string get_name() const {return name;}
    //set name of event
    void set_name(const std::string& n);

    inline std::vector<std::string> get_copy_attendees() const {return attendees;};

    private: 
    std::string name;
    std::vector<std::string> attendees;

};


#endif 