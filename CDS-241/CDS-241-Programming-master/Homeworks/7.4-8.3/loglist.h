#ifndef __loglist__
#define __loglist__
#include <vector>
#include <string>
#include "log.h"

class LogList {
    public:
        LogList() = default;
        LogList(const std::string& file);

        LogList filter_by_name(const std::string&);
        void prune_by_date(const std::string&); //I could add "date" here, but choosing not to just because


    private:
        std::vector<Log> list;

};


#endif 