#include <iostream>
#include <string>
#include <vector>

#include "Chapter6.h"

using namespace std;    


int main() {
    //4
    int f = fact(0);
    cout << "Factorial: " << f << endl;

    //5
    cout << "Absolute: " << abs(-42) << endl;

    //6
    /*
    Parameter: an input to a function, gets copied to the function when it is called
        ex in usefulness: the absolute value function
    local variable: a variable only used inside the scope of the block that is it in,
        whether that be a function, a loop, or main (which is still a function)
        ex in usefulness: used in main to store a vector of inputted strings
    static variable: A variable that stays in memory once a function is called and 
        destroyed. Can be used next time the function is called
        ex in usefulness: recursive functions to get the variable from the last time the
        function was called.

    */

    //8 for problems 4, 5
    //done

    //13
    /*
        void f(T): This takes in a type T, copies the value into the function, and then returns
            nothing. The function does its thing
        void f(T&): This takes in a memory location of the type T, meaning T could be changed inside
            the function. It still returns nothing.
    */

    //15
    /*
    s: s is a const reference because if s is very large, the program would spend lots of time copying
        the input into s. Using a reference allows for quicker access to the value at the parameter location.
        However, this allows s to be changed. To ensure that s is not changed, the function parameter uses
        const, so that the value at memory location s is not changed
    occurs: occurs is a plain reference because it acts as another "return" value. It must be changed so that 
        outside the function, it can be accessed.
    c: c is not a reference because it is a single character, and it is just as quick to copy a char then to 
        use a reference. There is also nothing that is storing c outside of the function
    s: if s was a plain reference, it could be changed
    occurs: if occurs is a const, then it cannot be changed inside the function, and negates the point of the 
        function "returning" more than one value. 

    */

    //17
    //written inside Chapter6.h
}
