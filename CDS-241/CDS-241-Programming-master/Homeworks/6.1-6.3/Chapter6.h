#include <iostream>

//4, Its odd but I wanted to try to build it recursively, even using the user input part from the problem
int fact(int time)
{
    if (time == 0) {
        int i;
        std::cout << "Enter a number to factorial: " << std::endl;
        std::cin >> i;
        return fact(i);
    }
    if (time == 1) return 1;
    else return time * fact(time - 1);
}


//5 absolute value
int abs(int i)
{
    if (i < 0) return -1 * i;
    return i;
}

//17
bool hasCap(const std::string& str){
    for (auto c : str)
        if (isupper(c)) return true;
    return false;
}

//17 pt. 2
void toLowerCase(std::string& str){
    for (auto c : str)
        c = tolower(c);
}


//These two functions do not have the same type
//In hasCap, there is no reason why the function should change any of the values
//  or characters in the string, so the parameter should be const string&
//In toLowerCase, the function should change the characters in the string
//  so a reference is used, however we want to change the characters, so it is not const