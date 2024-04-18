#include <string>
#include <vector>
#include "organization.h"
#include "event.h"

void addEvent(std::vector<Organization>& orgs, 
                        const std::string& eventStr);

std::vector<Organization> createOrganizations();

void addAttendeeToEvent(std::vector<Organization>& orgs, const std::string& attendeeStr);

void addAttendees(std::vector<Organization>& orgs);

std::string getLargestOrgName(const std::vector<Organization>& orgs);

std::vector<std::string> getSmallEvents(const std::vector<Organization>& orgs);