#include <iostream>
#include "Transaction.h"



//Do i need #include <string> here? It works just fine without,
//however the book says this main cpp program does need it.



int main() {
    Transaction t;

    t.id = "First transaction test";
    t.user_id = "bjm008";
    t.completed = true;
    t.amount = 470.47;

    std::cout << "ID:\t\t" << t.id << "\nUser_ID:\t" << t.user_id;
    std::cout << "\nComp:\t\t" << t.completed << "\nAmnt:\t\t" << t.amount;
    std::cout << std::endl;
}



/* #2.39 

struct Foo { /* empty  } // Note: no semicolon
int main() {
    return 0;
}

*/



