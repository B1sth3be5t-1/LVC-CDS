#include <iostream>
#include <vector>
using namespace std;

int main() {
    //4.1.1
    // 5 + 10 * 20 / 2 = 5 + ((10 * 20) / 2) = 5 + (200/2) = 5 + 100 = 105
    cout  << 5 + 10 * 20 / 2 << endl;


    //4.1.2
    //(a) * (vec.begin())
    //(b) (* (vec.begin())) + 1



    //4.2.6 Write an expression to determine whether an int value is even or odd
    int num = 5;
    bool isEven = (num % 2 == 0);




    //4.3.10 
    //Write the condition for a while loop that would read ints from the standard input and stop when the value read is equal to 42.
    int i;
    while (cin >> i && i != 42) { continue; }




    //4.4.16
    //(a) if (p = getPtr() != 0) -> if (getPtr() != 0), or (if ((p = getPtr()) != 0))
    //(b) if (i = 1024) -> if (i == 1024)



    //4.6.20
    /*
    (a) *iter++; -> this is fine gets the value at iter, then sets to iter + 1
    (b) (*iter)++; -> this is fine, gets the value at iter and prefixes it by 1
    (c) *iter.empty() -> this is fine, gets the value at iter and sees if it is empty
    (d) iter->empty(); -> this is fine, will see if the iterator is empty
    (e) ++*iter; -> this is fine, adds one to the value to which the iterator points
    (f) iter++->empty(); -> this is not fine, compiler won't be able to tell which iter value to check is empty

    */


    //4.9.28 Write a program to print the size of each of the built-in types.
    cout << "sizeof(int) = " << sizeof(int) << endl;
    cout << "sizeof(short) = " << sizeof(short) << endl;
    cout << "sizeof(long) = " << sizeof(long) << endl;
    cout << "sizeof(long long) = " << sizeof(long long) << endl;
    cout << "sizeof(unsigned char) = " << sizeof(unsigned char) << endl;
    cout << "sizeof(unsigned short) = " << sizeof(unsigned short) << endl;
    cout << "sizeof(unsigned long) = " << sizeof(unsigned long) << endl;
    cout << "sizeof(unsigned long long) = " << sizeof(unsigned long long) << endl;
    cout << "sizeof(bool) = " << sizeof(bool) << endl;
    cout << "sizeof(float) = " << sizeof(float) << endl;
    cout << "sizeof(double) = " << sizeof(double) << endl;
    cout << "sizeof(long double) = " << sizeof(long double) << endl;
    cout << "sizeof(void*) = " << sizeof(void*) << endl;




}
