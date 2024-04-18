#ifndef __hasptr__
#define __hasptr__

#include <string>

class HasPtr {
    public:
        HasPtr(const std::string &s = std::string()):
            ps(new std::string(s)), i(0) { };
    private:
        std::string *ps;
        int i;
    };


    #endif // __hasptr__