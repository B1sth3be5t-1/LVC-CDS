#include <iostream>
#include "dynamic.h"
#include <memory>

using namespace std;

int main() {
    unique_ptr<Dynamic> d1 = make_unique<Dynamic>("d1");
    unique_ptr<Dynamic> d2 = make_unique<Dynamic>("d2");
    unique_ptr<Dynamic> d3 = make_unique<Dynamic>("d3");
    unique_ptr<Dynamic> d4 = make_unique<Dynamic>("d4");

    cout << "Objects created" << endl;
    //destroys in reverse order

    auto ptr = make_shared<Dynamic>("shared1");
    auto ptr2 = ptr;
    auto ptr3 = ptr;
    auto ptr4 = ptr2;

    ptr2 = nullptr;
    //destroys this shared object before other ones
    return 0;
}
