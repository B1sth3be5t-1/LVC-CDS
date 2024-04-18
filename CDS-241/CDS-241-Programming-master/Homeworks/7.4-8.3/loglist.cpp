#include <vector>
#include <string>
#include <fstream>
#include "loglist.h"
#include "log.h"

using namespace std;

LogList::LogList(const string& file) {
    ifstream f{file};

    string line;

    while (getline(f, line)) 
    {
        Log l(line);
        this->list.push_back(l);
    }
}

LogList LogList::filter_by_name(const string& name) {
    LogList newList;
    for (auto& l : this->list) // I am making the choice to return the original log items, otherwise I would use auto for a copy
        if (l.getUser() == name)
            newList.list.push_back(l);
    return newList;
}

void LogList::prune_by_date(const string& d) {
    vector<Log> newList;
    for (auto& l : this->list)
        if (!(l.getDate() == d)) 
            newList.push_back(l);
    this->list = newList;
}