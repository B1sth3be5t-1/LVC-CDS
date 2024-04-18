#include <string>
#include "hasptr.h"

//2
    //Sales_data::Sales_data(Sales_data rhs);
    /*
        For this to be a legal copy constructor definition, one must pass a Sales_data reference.
        This essentially uses the sales_data copy constructor in the copy constructor, which is what is being defined,
        so it can't be used yet.
    */

    //5
    HasPtr::HasPtr(const HasPtr& ptr) {
        this->ps = new std::string(*(ptr.ps));
        this->i = ptr.i;
    };
    

    //8
    HasPtr& HasPtr::operator=(const HasPtr& ptr) {
        ps = new std::string(*(ptr.ps));
        i = ptr.i;

        return *this;
    };

    //11
    HasPtr::~HasPtr() {
        delete ps;
    };

    //23 everything looks pretty close to good

    //24
    /*
        if HasPtr did not have a destructor, the user could not create an object
        because it could never be destroyed.
        if HasPtr didn't define the copy constructor, it would copy the pointer of ps
        to the new object instead of the value at ps implicitly.
    */
    

/*
Hasptr.h

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
*/