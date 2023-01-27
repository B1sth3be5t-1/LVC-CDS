
#include <string>
#include <iostream>
#include <memory>
#include <functional>

#include "menu.h"
#include "menu_item.h"

using namespace std;

int fact(int d) {
    if (d == 1) return 1;
    else return d * fact(d - 1);
}

int fibb(int a, int b, int count, int target) {
    if (count == target) return a;
    else return fibb(b, a+b, ++count, target);
}
class Item1 : public MenuItem {
public:
    Item1(const std::string& d) 
        : MenuItem(d)
    {}

    void execute() {
        int d;
        std::cout << "Enter a number for factorial: ";
        std::cin >> d;
        std::cout << "The factorial for " << d << " is: " << fact(d) << std::endl;
    }
};

class Item2 : public MenuItem {
public:
    Item2(const std::string& d) 
        : MenuItem(d)
    {}

    void execute() {
        int d;
        std::cout << "Enter a number for fibbionaci sequence: ";
        std::cin >> d;
        std::cout << "The " << d << "th number in the fibbionaci sequence is: " << fibb(0, 1, 1, d) << std::endl;
    }
};

class Item3 : public MenuItem {
public:
    Item3(const std::string& d) 
        : MenuItem(d)
    {}

    void execute() {
        int d;
        std::cout << "Enter a number to square: ";
        std::cin >> d;
        std::cout << "The square of " << d << " is: " << d * d << std::endl;
    }
};


int main() {

    Menu m;

    m.add_item(make_unique<Item1>("Factorial a number"));
    m.add_item(make_unique<Item2>("Fibbonaci a number"));
    m.add_item(make_unique<Item3>("Square a number"));

    m.do_menu_loop();
}




//in menuItem: virtual ~MenuItem() = default; //This is ok because MenuItem only has a string member

//in menu.cpp
    //items.push_back(std::move(mip)); // since mip is a r value reference, mip will be deleted after
    //the move and is no longer needed, so it doesn't need to be copied. It can be stolen from.