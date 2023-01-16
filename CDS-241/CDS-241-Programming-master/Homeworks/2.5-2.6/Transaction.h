#include <string>
using std::string;

struct Transaction
{
    string id {""};
    string user_id {""};
    bool completed {false};
    double amount {0.0};
};

