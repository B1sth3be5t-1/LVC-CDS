#include <string>
#include <iostream>

#include "menu_item.h"

using namespace std;




MenuItem::MenuItem(const std::string& d)
    : desc{d}
{}

std::string MenuItem::description() const
{
    return desc;
}
