#ifndef MENU_ITEM_H
#define MENU_ITEM_H

#include <string>

class MenuItem {
public:
    MenuItem(const std::string& d);

    std::string description() const;

    // our polymorphic function -- this is where the behavior
    // of menu item objects vary from type to type. 
    virtual void execute() = 0;

    virtual ~MenuItem() = default; //This is ok because MenuItem only has a string member

private:
    std::string desc;
};

#endif
