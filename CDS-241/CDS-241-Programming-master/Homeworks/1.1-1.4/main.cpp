#include <iostream>
#include <fstream>

using std::cout;
using std::endl;

//#9
static void num_9() {

    int sum = 0;

    for (int x = 50; x <= 100; x++) sum += x;

    cout << "The summation from 50 to 100 are: " << sum << endl;
}


void file_io() {
    std::ofstream out {"../foo.txt"};

    out << "hello there, GENERAL KENOBI2\n";

    std::ifstream bar {"../bar.txt"};

    int sum = 0, val;
    while (bar >> val) sum += val;

    cout << sum << endl;
}



int main(int, char **)
{
    //#3
    cout << "Hello, world!\n";

    //--------------------------------------------------

    /*
    #6
    std::cout << "The sum of " << v1;
    << " and " << v2;
    << " is " << v1 + v2 << std::endl;


    ^^^ This is not a valid piece of code, because each << operand takes
    an input and an output side for both the left and the right. The
    second two lines do not have an input to either of the << operands,
    and would need something such as:

    std::cout << " and " << v2;
    std::cout << " is " << v1 + v2 << std::endl;
    */

    //---------------------------------------------------

    //#7

    /*
        I am going to start typing here, and show that /* this
        does not work.
     */

    //------------------------------------------------------------

    num_9();
    file_io();

    //#11

    /*
    int n1, n2;
#include <iostream>
#include <fstream>

using std::cout, std::endl;

//#9
static void num_9() {

    int sum = 0;

    for (int x = 50; x <= 100; x++) sum += x;

    cout << "The summation from 50 to 100 are: " << sum << endl;
}


void file_io() {
    std::ofstream out {"../foo.txt"};

    out << "hello there, GENERAL KENOBI2\n";

    std::ifstream bar {"../bar.txt"};

    int sum = 0, val;
    while (bar >> val) sum += val;

    cout << sum << endl;
}



int main(int, char **)
{
    //#3
    cout << "Hello, world!\n";

    //--------------------------------------------------

    /*
    #6
    std::cout << "The sum of " << v1;
    << " and " << v2;
    << " is " << v1 + v2 << std::endl;


    ^^^ This is not a valid piece of code, because each << operand takes
    an input and an output side for both the left and the right. The
    second two lines do not have an input to either of the << operands,
    and would need something such as:

    std::cout << " and " << v2;
    std::cout << " is " << v1 + v2 << std::endl;
    */

    //---------------------------------------------------

    //#7

    /*
        I am going to start typing here, and show that /* this
        does not work.
     */

    //------------------------------------------------------------

    num_9();
    file_io();

    //#11

    /*
    int n1, n2;

    std::cout << "Enter two numbers: " << std::endl;
    std::cin >> n1 >> n2;
    std::cout << "The numbers from " << n1 << " to " << n2 << " are:" << std::endl;

    while (n1 <= n2)
    {
        std::cout << n1 << std::endl;
        ++n1;
    }
    */
}
