#ifndef __FOLLOWBOT__
#define __FOLLOWBOT__

#include <vector>
#include "bot.h"

class followBot : public Bot {
public:
    followBot(char c);

    int move() override;

    void examine_neighbors(const std::vector<WorldLoc>& n) override;

private:
    std::vector<WorldLoc> n;
};


#endif