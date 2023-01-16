#ifndef __DRUNKBOT__
#define __DRUNKBOT__

#include <vector>
#include "bot.h"

class drunkBot : public Bot {
public:
    drunkBot(char c);

    int move() override;

    void examine_neighbors(const std::vector<WorldLoc>& n) override;
};


#endif