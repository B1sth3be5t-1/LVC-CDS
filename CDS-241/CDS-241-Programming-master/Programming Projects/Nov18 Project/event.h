#ifndef __event__
#define __event__

#include <string>
#include <vector>

class Event {
public:
    // Default constructor
    Event() = default;

    // create a new event
    Event(const std::string& name, const std::string& org);

    // add an attendee to this event
    void add_attendee(const std::string& attendee);

    // check if this person is attending this event
    bool is_attending(const std::string& attendee) const;

    // returns the number of students attending this event
    inline int num_attending() const {return attendees.size();};

    // return the name of the organization running this event
    inline std::string organization() const {return org;};

    inline std::string get_name() const {return name;};

private:
    std::string name;
    std::string org;
    std::vector<std::string> attendees;
};

#endif // __event__