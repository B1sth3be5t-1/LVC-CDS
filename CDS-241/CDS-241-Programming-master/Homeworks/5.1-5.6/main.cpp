#include <iostream>
#include <vector>

using namespace std;   

bool checker(const vector<int>& v1, const vector<int>& v2) {
    const vector<int>* small;
    const vector<int>* large;
    if (v1.size() < v2.size()) {
        small = &v1;
        large = &v2;
    }
    else {
        small = &v2;
        large = &v1;
    }


    for (int i = 0; i < (*small).size(); ++i)
        if ((*small)[i] != (*large)[i]) return false;
    return true;

}

int main() {
    
    //5.4
    /*
    (a) while (string::iterator iter != s.end()) { /* ...  }
        This creates a new string iterator every pass, and will infinitely run
            It should be written:
        string::iterator iter = s.begin();
        while (iter!= s.end()) { /* stuff here }

    (b) while (bool status = find(word)) { /* ...  }
        if (!status) { /* ...  }
        Since status is created inside the while loop, first off there is nothing to exit
            the loop, unless there is a break; statement in the loop.
            Also, accessing status after the loop is not possible. It should be:
        bool status;
        while (status = find(word)) { /* stuff here }
        if (!status) { /* ... }

    */
    


    //5.7

    /*
    (a) if (ival1 != ival2)
            ival1 = ival2;
        else ival1 = ival2 = 0;

    (b) if (ival < minval) {   
            minval = ival;
            occurs = 1;
        }

    (c) if (int ival == get_value())
            cout << "ival = " << ival << endl;
        if (!ival)
            cout << "ival = 0\n";

    (d) if (ival == 0)
            ival = get_value();
    */




    //5.17
    vector<int> v1, v2;
    cout << checker(v1, v2) << endl; //see below for checker function
    



    //5.20
    cout << "enter strings: " << endl;
    string s, lastS = "";
    bool twice = false;
    while (cin >> s)
    {
        if (s == lastS) {
            cout << s << endl;
            twice = true;
            break;
        }
        lastS = s;
    }

    if (!twice) cout << "No words were repeated twice in a row" << endl;

    //so you have to hit CTRL + D to stop the terminal line? How do you check the end of a singular line....?

}


