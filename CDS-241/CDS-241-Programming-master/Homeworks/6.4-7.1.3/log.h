#include <string>

class Log {
    std::string date, time, username, IPAddress;
    bool success;

    public:
        std::string to_string(){
            std::string out = "Date: " + date + ", Time: " + time + ", Username: " + username + ", IPAddress: " + IPAddress + ", Success: " + std::to_string(success);
            return out;
        }

        
        Log& from_string(std::string s){
            std::string d, t, u, i, bString;
            bool b;
            //assuming s is formatted as: "Date, Time, Username, IPAddress, Success"
            int param = 0;
            for (auto c : s) {
                //if c is ',', increase param to signify next variable
                if (c == ',') ++param;
                //increase param to remove whitespace
                else if (c == ' ') ++param;
                //else, depending on what param is, add character to the respective variable of log
                else switch (param) {
                    case 0: 
                        d += c;
                        break;
                    case 2: 
                        t += c;
                        break;
                    case 4: 
                        u += c;
                        break;
                    case 6: 
                        i += c;
                        break;
                    default: bString += c;
            }
        } 

            b = (bString == "true");
            date = d;
            time = t;
            username = u;
            IPAddress = i;
            success = b;

            return *this;
        }
};