#include "follow_bot.h"
#include <vector>
#include <algorithm>
#include <random>

using namespace std;

followBot::followBot(char c) : Bot(c) {};

void followBot::examine_neighbors(const vector<WorldLoc>& n) {

    this->n = n;

};

//The followBot will find another bot, and consistently follow it, unless a goal
//is found. Then it will move towards the goal
int followBot::move() {
    auto it = find(n.begin(), n.end(), GOAL);
    //if the goal is found move there
    if (n.end() != it) 
        return it - n.begin();

    //if another bot is found move there
    it = find(n.begin(), n.end(), BOT);

    if (n.end() != it) 
        return it - n.begin();

    //else move randomly
    random_device dev;
    mt19937 rng(dev());
    uniform_int_distribution<mt19937::result_type> dist6(0,3);

    return dist6(rng);
}