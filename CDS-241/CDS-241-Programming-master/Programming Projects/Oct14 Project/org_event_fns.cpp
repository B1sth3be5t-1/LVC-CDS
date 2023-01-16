#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include "organization.h"
#include "event.h"

using namespace std;

void addEvent(std::vector<Organization>& orgs, const std::string& eventStr) {
    //separates input string into event and organization    
    string evStr, orgStr;
    bool isOrg = false;
    for (auto c : eventStr)
    {
        if (!isOrg)
            if (c == '|')
                isOrg = true;
            else evStr += c;
        else orgStr += c;
    }

    //creates a blank vector of attendees
    vector<string> blankAttendees {};
    //creates a new Event and sets fields
    Event newEvent;
    newEvent.name = evStr;
    newEvent.attendees = blankAttendees;

    //loop through inputted orgs
    for (auto& org : orgs)
        //if the input org name is = to the org loop name
        if (org.name == orgStr)
        {
            //add the event to the vector of the organization and kill method
            org.events.push_back(newEvent);
            return;
        }

    //if org was not in inputted list, create new organization
    Organization newOrg;
    newOrg.name = orgStr;
    //initialize the organization event to a new vector *with the event* (<- important)
    newOrg.events = vector<Event> {newEvent};
    //add new org to the inputted org list
    orgs.push_back(newOrg);
    
}

std::vector<Organization> createOrganizations() {
    ifstream file {"../events.txt"};
    string s;
    vector<Organization> orgs;
    while (getline(file, s)) 
        addEvent(orgs, s);
    return orgs;
}

void addAttendeeToEvent(std::vector<Organization>& orgs, const std::string& attendeeStr) {
    //separates input string into event and attendee    
    string evStr, attendee;
    bool isOrg = false;
    for (auto c : attendeeStr)
    {
        if (!isOrg)
            if (c == '|')
                isOrg = true;
            else attendee += c;
        else evStr += c;
    }

    //loop through all organizations
    for (auto& o : orgs)
        //loop through all events in said organization
        for (auto& e : o.events)
            //if event name matches input string name
            /*
                Something is being very funky with my strings, the last one
                always matches if its correct, but the rest are off. I'd assume
                theres some hidden character thats giving me an issue but I don't
                know what to do about it.
            */
            if (e.name.compare(evStr) == 0 || e.name.compare(evStr) == -1) 
                //add attendee
                e.attendees.push_back(attendee);
}

void addAttendees(std::vector<Organization>& orgs) {
    ifstream file {"../attendees.txt"};
    string s;
    while (getline(file, s)) 
        addAttendeeToEvent(orgs, s);
}


std::string getLargestOrgName(const std::vector<Organization>& orgs) {
    string largest;
    int largestAtt = 0;

    //loop through organizations
    for (const auto& o : orgs) {
        int numAttendees;
        //for event in organization
        for (const auto& e : o.events)
            //for attendee in event
            for (const auto& attendee : e.attendees)
                //++total num of org attendees
                ++numAttendees;
        //at the end of all the events, if numAttendees in org > largest previous
        if (numAttendees >= largestAtt) 
        {
            //set largest number of attendees and name
            largestAtt = numAttendees;
            largest = o.name;
        }
    }

    return largest;
}

std::vector<string> getSmallEvents(const std::vector<Organization>& orgs) {
    vector<string> s;
    for (auto& o : orgs)
        for (auto& e : o.events)
            if (e.attendees.size() < 3)
                s.push_back(e.name);

    return s;
}