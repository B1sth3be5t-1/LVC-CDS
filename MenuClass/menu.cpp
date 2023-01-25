#include <iostream>
#include <string>
#include <vector>
#include <memory>

#include "menu.h"

using namespace std;

Menu::Menu()

{}

void Menu::show() const
{
    cout << endl;
    for (int i = 0; i < items.size(); ++i) {
        cout << (i+1) << ": " << items[i]->description() << "\n";
    }
    cout << (items.size() + 1) << ": Quit Menu\n";
}

int Menu::get_input() const
{
    cout << "\nplease enter your choice (1 -- " << items.size() + 1 << "): ";
    while (true) {
        int choice;
        if ((cin >> choice) && 1 <= choice && choice <= items.size()+1) {
            // throw away whatever is left on this input line.  
            string trash;
            getline(cin, trash);
            return choice;
        }
        else {
            // bad input -- reset the stream, throw away everything on 
            // the line, and try again.
            cin.clear();
            string trash;
            getline(cin, trash);
            cout << "sorry, I need a number between 1 and " 
                 << items.size() + 1 
                 << ": ";
        }
    }
    return -1;
}

bool Menu::run_item(int item) const
{
    --item;
    if (item == items.size())
        return false;
    else if (item >= 0 && item < items.size()) {
        items[item]->execute();
        return true;
    }
    else {
        // error -- bad item number?
        return false;
    }
}

void Menu::do_menu_loop() const 
{
    while (true) {
        // display the menu
        show();
        // get user input
        auto choice = get_input();
        // run the menu, and quit the loop if run_item returns false.
        if (! run_item(choice))
            break;
    }
}

void Menu::add_item(std::unique_ptr<MenuItem>&& mip) 
{
    // C++ question: why is move() required here?
    items.push_back(std::move(mip)); // since mip is a r value reference, mip will be deleted after
    //the move and is no longer needed, so it doesn't need to be copied. It can be stolen from.
}
