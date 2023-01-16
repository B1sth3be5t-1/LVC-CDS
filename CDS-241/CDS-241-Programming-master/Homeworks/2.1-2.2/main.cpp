#include <iostream>

int main() {
    
    /*
    2.1


    int: basic integer, typically up to 2^31
    long: long integer, double the size of bits as an int
    long long: double the size of bits as a long
    short: a short integer, typcially reserved for very small numbers

    unsigned: does not have a sign associated, meaning value cannot be negative
    signed: has either a positive or negative value

    float: "single-precision floating-point", decimal with min size of 6 sig digits
    double: "double-precision floating-point", decimal with min size of 10 sig digits






    2.2

    rate: double, lots of percentage and decimal point calculations are typically done with
        rates, so a double is the best bet for getting the most precise answers and 
        calculations
    principal: int, most times principals are taken out in whole dollar values, such as
        $25,000. It is highly unlikely to be a $24,987.23 loan.
    payment: float, typically payments are done in whole dollar values as well, however if a 
        payments were to need to have decimals, it would not need much calculation, therefore
        using a float would be ok. I am aware the book says to use double over float, however
        I don't believe this would be an issue in this instance.






    2.3

    unsigned u = 10, u2 = 42;
    std::cout << u2 - u << std::endl; -> 32
    std::cout << u - u2 << std::endl; -> 4294967295 - 31 = 4294967264

    int i = 10, i2 = 42;
    std::cout << i2 - i << std::endl; -> 32
    std::cout << i - i2 << std::endl; -> -32

    std::cout << i - u << std::endl; -> 0
    std::cout << u - i << std::endl; -> 0

    */

    //2.4
    unsigned u = 10, u2 = 42;
    std::cout << u2 - u << std::endl;
    std::cout << u - u2 << std::endl;

    int i = 10, i2 = 42;
    std::cout << i2 - i << std::endl;
    std::cout << i - i2 << std::endl;

    std::cout << i - u << std::endl;
    std::cout << u - i << std::endl;


    /*

    2.5

    (a) 
        ’a’ -> single char a
        L’a’ -> wide char a
        "a" -> string literal a + nullChar
        L"a" -> string literal of wide characters
    (b) 
        10 -> int 10
        10u -> unsigned int 10
        10L -> long 10
        10uL -> unsigned long 10
        012 -> the octal character 10
        0xC -> the hexadecimal number 12
    (c) 
        3.14 -> 3.14 as a double
        3.14f -> float 3.14
        3.14L -> long double 3.14
    (d) 
        10 -> int 10
        10u -> unsigned int 10
        10. -> double 10
        10e-2 -> Scientific notation floating point value of .1




    2.6
    int month = 9, day = 7; -> these are initialized as integers
    int month = 09, day = 07; -> This part could not be compiled, as the day portion is ok,
        however it is initializing the octal version of 7. It happens to be 7, however the
        month portion is initializing as the octal version of 9, and octal characters can
        only be 0-7, as they define the 8 characters of the octal set (just as binary is 
        only 0 and 1, making up 2 (prefix bi) numbers)




    2.9
        (a) std::cin >> int input_value; -> This is illegal because initializing a type is 
            "not allowed here", as the computer will be taking an input from the console
        (b) int i = { 3.14 }; -> error, will give a truncation error, because the program
            will not let us initialize this with the potential loss of data.
        (c) double salary = wage = 9999.99; -> this would work if wage is defined earlier in
            the program, however it is trying to set salary to a value that does not exist
            within another variable. 
        (d) int i = 3.14; -> this will work, however i will = 3




    2.10 
        std::string global_str; -> ""
        int global_int; -> 0
        int main()
        {
            int local_int; -> both are uninitialized, so they cannot be used, however they
                will be recognized by the program. 
            std::string local_str;
        }




    2.11
        (a) extern int ix = 1024; -> definition, gives a value
        (b) int iy; -> defines iy (auto initializes as 0)
        (c) extern int iz; -> declares the int, but doesn't define it. 




    2.14
    int i = 100, sum = 0;
    for (int i = 0; i != 10; ++i)
        sum += i;
    std::cout << i << " " << sum << std::endl;    

    yes the program is legal, however i is redefined with block scope inside the for loop,
        so when the external cout statement calls it, it will refer to int i = 100;

        output: 100 45 
    */ 

}
