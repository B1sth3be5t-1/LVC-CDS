#include "drunk_bot.h"
#include <random>

using namespace std;

drunkBot::drunkBot(char c) : Bot(c) {};

int drunkBot::move() {
    //create random move
    random_device dev;
    mt19937 rng(dev());
    uniform_int_distribution<mt19937::result_type> dist6(0,3);

    return dist6(rng);
}

void drunkBot::examine_neighbors(const vector<WorldLoc>& n) {}