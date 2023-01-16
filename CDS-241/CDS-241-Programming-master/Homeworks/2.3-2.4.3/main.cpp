#include <iostream>

int main() {

    /*

    #15
    (a) int ival = 1.01; -> ok
    (b) int &rval1 = 1.01; -> not ok, the reference value must point to an object, not a value
    (c) int &rval2 = ival; -> ok
    (d) int &rval3; -> not ok, the reference must actually point to an object, and cannot be rebound later






    #17

    int i, &ri = i;
    i = 5; ri = 10;
    std::cout << i << " " << ri << std::endl;

    This code will print 10 10, since both ri and i refer to the same object i, and any operations done to either will be done to the object itself
    */



   //#18

    int val42 = 42, val69 = 69;
    int *p = &val42; //p now holds address of val42, which results to 42
    std::cout << *p << std::endl;
    *p = NULL; //p now holds no value; p is null
    std::cout << *p << std::endl;

    int *p69 = &val42;
    *p69 = val69; //changes the value to that of 69
    std::cout << *p69 << std::endl;



   //20 
   /*
    int i = 42; -> creates int i
    int *p1 = &i; -> creates an int pointer p1 and sets to address of int i
    *p1 = *p1 * *p1; -> sets the value at address held by p1 to that of p1 * p1, so 42 x 42
   */




    /*
    //28
    (a) int i, *const cp; -> int i creates declares variable i, *const cp is illegal because cp is a pointer, and must point to an object. 
    (b) int *p1, *const p2; -> first part is legal, creates an int pointer to the const pointer p2, however p2 must be initialized and point to an object.
    (c) const int ic, &r = ic; -> creates a const int ic, however must be initialized. &r creates a const int reference to ic through variable &r
    (d) const int *const p3; -> creates a constant int pointer called p3, however p3 must be initialized, as it is both const and a pointer. 
    (e) const int *p; -> creates a const int pointer

    */

}
