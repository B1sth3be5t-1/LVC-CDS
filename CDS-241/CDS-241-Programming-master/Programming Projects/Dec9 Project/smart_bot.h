#ifndef __SMARTBOT__
#define __SMARTBOT__

#include <deque>
#include <vector>

#include "bot.h"

class smartBot : public Bot {
public:
    smartBot(char c);

    int move() override;

    void examine_neighbors(const std::vector<WorldLoc>& n) override;

private:
    std::vector<WorldLoc> n;
    std::vector<int> potMoves;
    std::vector<std::pair<int, int>> pairs;
    int nextMove, x, y;
    
public:
    void outputKnown() const;
};


#endif