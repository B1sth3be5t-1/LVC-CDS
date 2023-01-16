#include <vector>
#include <iostream>
#include <memory>
#include <string>
#include <random>
#include <thread>
#include <algorithm>

#include "botworld.h"
#include "botdisp.h"
#include "bot.h"
#include "botworldutils.h"

using namespace std;

// variables defined in an "unnamed" namespace are private to this file.
// This effectively gives you a way to create global variables that are 
// available only in a single file. Now, I could (and maybe should) have 
// made these instance variables, but I wanted to illustrate the technique.
namespace {
    random_device r;
    default_random_engine dev(r());
}

BotWorld::BotWorld(int h, int w, double p)
    : height{h}, width{w}, p_obstacles{p}, display(w, h)
{
    uniform_real_distribution<double> dist(0.0, 1.0);

    // place obstacles.
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            if (dist(dev) < p_obstacles) {
                obstacles.push_back({ i, j });
                display.add_obstacle(i, j);
            }
        }
    }
    
    uniform_int_distribution<int> dist_h(0, height);
    uniform_int_distribution<int> dist_w(0, width);

    // place the goal.
    while (true) {
        int r = dist_h(dev);
        int c = dist_w(dev);

        if (classify_loc({r, c}) == EMPTY) {
            goal = { r, c };
            display.add_goal(r, c);
            break;
        }
    }
}

void BotWorld::add_bot(std::unique_ptr<Bot>&& bot) 
{
    // randomly place this bot in our world.
    uniform_int_distribution<int> dist_h(0, height);
    uniform_int_distribution<int> dist_w(0, width);

    while (true) {
        // find an empty spot in the world.
        int r = dist_h(dev);
        int c = dist_w(dev);
        if (classify_loc({r, c}) == EMPTY) {
            bots.push_back({ std::move(bot), r, c });
            break;
        }
    }
}

bool BotWorld::step(int step_num) 
{
    // If a bot has reached the goal, quit!
    if (bot_wins()) {
        return true;
    }

    // second, show each bot its neighborhood.
    for (auto& b: bots) {
        // this vector has an entry for each neighbor in
        // order left, up, right, and down. 
        
        Location left = { b.loc.r, b.loc.c - 1};
        Location up = { b.loc.r - 1, b.loc.c };
        Location right = { b.loc.r, b.loc.c + 1 };
        Location down = { b.loc.r + 1, b.loc.c };
        // classify each neighbor, put the results in a
        // vector, send the vector to the bot.
        vector<WorldLoc> neighbors { classify_loc(left), classify_loc(up),
                                    classify_loc(right), classify_loc(down) };
        b.bot->examine_neighbors(neighbors);
    }

    // now, ask each bot for its move. Update the 
    // bot's position IF the move succeeds.
    for (auto& b: bots) {
        int mv = b.bot->move();
        
        Location trial_move = b.loc;
        
        // update location based on the bots requested move. 
        // 0 means go left, etc..
        if (mv == 0) {
            trial_move.c -= 1;
        }
        else if (mv == 1) {
            trial_move.r -= 1;
        }
        else if (mv == 2) {
            trial_move.c += 1;
        }
        else {
            trial_move.r += 1;
        }

        // if that spot is empty, move there.
        if (can_move(trial_move)) {
            b.loc = trial_move;
        }
    }

    // update the display with the new bot locations
    display.clear_bots();

    for (const auto& b: bots) {
        display.add_bot(b.bot->get_symbol(), b.loc.r, b.loc.c);
    }

    // display the board
    display.show();
    cout << "Step " << step_num << endl;
    return false;
}

bool BotWorld::run_sim(int k) 
{
    for (int i = 0; i < k; ++i) {
        if (step(i+1)) {
            return true;
        }
        // sleep for a few seconds in between steps.
        // the s suffix identifies a literal of type
        // chrono::duration<seconds>
        this_thread::sleep_for(.25s);
    }
    return false;
}

WorldLoc BotWorld::classify_loc(Location loc) const
{
    if (loc.r < 0 || loc.c < 0
        || loc.r >= height || loc.c >= width) {
        return EDGE;
    }
    else if (loc == goal) {
        return GOAL;
    }
    else if (bots.end() != find_if(bots.begin(), bots.end(), 
                            [loc](auto& b) {
                                return b.loc == loc;
                            })) 
    {
        return BOT;
    }
    else if (obstacles.end() != find(obstacles.begin(), obstacles.end(), loc)) {
        return OBSTACLE;
    }
    else {
        return EMPTY;
    }
}

bool BotWorld::can_move(Location loc) const
{
    auto c = classify_loc(loc);
    return c == EMPTY || c == GOAL;
}

bool BotWorld::bot_wins() const 
{
    for (const auto& b: bots) {
        if (b.loc == goal)
            return true;
    }
    return false;
}
