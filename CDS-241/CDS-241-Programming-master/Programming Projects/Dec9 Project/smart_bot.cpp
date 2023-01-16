#include <deque>
#include <vector>
#include <algorithm>
#include <iostream>
#include <random>

#include "smart_bot.h"

using namespace std;

smartBot::smartBot(char c) : Bot(c), nextMove{-1}, x{0}, y{0} {};

void smartBot::examine_neighbors(const vector<WorldLoc>& n) {
    potMoves.clear();
    this->n = n;
    if (n[0] == EMPTY && n[0] != EDGE && n[0] != BOT && (pairs.end() == find(pairs.begin(), pairs.end(), make_pair(x - 1, y))))
    {
        potMoves.push_back(0);
    }
    if (n[1] == EMPTY && n[1] != EDGE && n[1] != BOT && (pairs.end() == find(pairs.begin(), pairs.end(), make_pair(x, y - 1)))) 
    {
        potMoves.push_back(1);
    }
    if (n[2] == EMPTY && n[2] != EDGE && n[2] != BOT && (pairs.end() == find(pairs.begin(), pairs.end(), make_pair(x + 1, y)))) 
    {
        potMoves.push_back(2);
    }
    if (n[3] == EMPTY && n[3] != EDGE && n[3] != BOT && (pairs.end() == find(pairs.begin(), pairs.end(), make_pair(x, y + 1)))) 
    {
        potMoves.push_back(3);
    }
    

    pairs.push_back(make_pair(x, y));
}



int smartBot::move() {
    auto it = find(n.begin(), n.end(), GOAL);
    //if the goal is found move there
    if (n.end() != it) 
        return it - n.begin();

    if (nextMove != -1) 
    {   
        int temp = nextMove;
        nextMove = -1;
        return temp;
    }

    random_device dev;
    mt19937 rng(dev());

    if (potMoves.size() == 0) potMoves.resize(4);

    
    int size = potMoves.size();
    uniform_int_distribution<mt19937::result_type> dist6(0, size);

    int i = potMoves[dist6(rng)];

    if (i == 0) --x;
    else if (i == 1) --y;
    else if (i == 2) ++x;
    else ++y;

    
    return i;


}