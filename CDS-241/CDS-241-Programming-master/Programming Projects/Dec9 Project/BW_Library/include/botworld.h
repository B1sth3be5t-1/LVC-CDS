#ifndef BOTWORLD_H
#define BOTWORLD_H

#include <memory>
#include <vector>

#include "botdisp.h"
#include "bot.h"
#include "botworldutils.h"

class BotWorld {
public: 
    /**
     * @brief Construct a new Bot World object
     * 
     * @param height the height of the world (#rows)
     * @param width the width of the world (#columns)
     * @param p_obstacles the likelihood that a cell will contain an obstacle
     */
    BotWorld(int height, int width, double p_obstacles);

    // add a bot to our world. 
    void add_bot(std::unique_ptr<Bot>&& bot);

    // execute a single step of our simulation.
    bool step(int step_num);

    // run our simulation for k steps
    bool run_sim(int k);

    // check whether a bot has reached the goal.
    bool bot_wins() const;

private:
    // some private helper methods that others shouldn't
    // call directly.

    // identify the occupant of a location
    WorldLoc classify_loc(Location loc) const;

    // true if the location is empty.
    bool can_move(Location loc) const;

private:
    int height;
    int width;
    double p_obstacles;

    // this is our "display device"
    BotDisp display;

    // the bots in our world
    std::vector<BotLoc> bots;

    // the obstacle locations in our world.
    std::vector<Location> obstacles;

    // The location of the goal
    Location goal;
};

#endif
