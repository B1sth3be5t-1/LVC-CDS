#include <string>
#ifndef __dynamic__
#define __dynamic__

class Dynamic {
public:
    Dynamic(const std::string& n);
    ~Dynamic();
private:
    std::string name;
};




#endif