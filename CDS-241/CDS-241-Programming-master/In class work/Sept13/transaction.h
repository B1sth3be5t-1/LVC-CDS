#ifndef transaction.h
#define transaction.h

#include <string>

//never ever ever ever rename w/ "using" within a header file

struct Transaction {
    std::string id {""};
    std::string user_id {""};
    bool completed {false};
    double amount {0.0};
};


#endif

