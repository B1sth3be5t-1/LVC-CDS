#ifndef LOG
#define LOG
#include <string>

//#2 We need to make sure to explicitly define the default constructor if we
//define other constructors, else the compliler will not automatically do it
//for us, as it will try to look for one of the constructors we have defined

class Log {
public:
    //default
    Log() = default;
    //initialized
    Log(const std::string& str);

    /*
        For part three, is this another copy paste error? I looked up
        the copy assign and destroy in the book and it's in chapter 13....
        I think these are correct however
    */

    //copy constructor
    Log(const Log& other) = default;
    //assign constructor
    Log& operator=(const Log& other) = default;
    //destructor
    ~Log() = default;


    std::string to_string() const;
    //technically these should be const funtions, so that the caller cannot change the object's data
    inline std::string getDate() const {return date;};
    inline std::string getTime() const {return time;};
    inline std::string getUser() const {return user;};
    inline std::string getIp() const {return ip;};
    inline bool getSuccess() const {return success;};



    
private:
    std::string date;
    std::string time;
    std::string user;
    std::string ip;
    bool success;
};

#endif /* LOG */
