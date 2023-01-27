#ifndef MENU_H
#define MENU_H

#include <string>
#include <vector>
#include <memory>

#include "menu_item.h"

class Menu {
public:
    // construct an empty menu
    Menu();

    // display the menu
    void show() const;

    // get valid input from the keyboard
    int get_input() const;

    // run the given menu item. Returns true if the menu should
    // display again, false if not.
    bool run_item(int item) const;

    // run the "menu loop" -- repeatedly display the menu, get input,
    // and execute the chosen menu item, until run_item returns false.
    void do_menu_loop() const;

    // add an item to the menu. Parameters of type unique_ptr<> indicate
    // we are taking ownership of an object.
    void add_item(std::unique_ptr<MenuItem>&& mip);

private:
    // a vector containing pointers to menu item objects. We use 
    // pointers so that we get polymorphic behavior.
    std::vector<std::unique_ptr<MenuItem>> items;
};

#endif
