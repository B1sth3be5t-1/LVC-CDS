#ifndef BOTWORLDUTILS_H
#define BOTWORLDUTILS_H

#include <memory>

// Some small types used in our bot world library.

enum WorldLoc {
    EMPTY,
    EDGE,
    OBSTACLE,
    GOAL,
    BOT
};

// a location in our world.
struct Location {
    int r;
    int c;

    bool operator==(const Location& other) const {
        return r == other.r && c == other.c;
    }
};

// This is called a "forward declaration." It solves an interesting problem --
// this file needs to know about Bot, but bot.h needs to include this file...
// that circular dependency can't work. 

// We can only partly solve it. The forward declaration says, "There is a
// class called Bot." This is enough for the declaration of the unique pointer
// below to work -- we can declare pointers and things like that to a Bot, but
// we can't use Bot in a way where its details are needed.
class Bot;

// A struct that pairs a bot and its location, so
// we can store them together.
struct BotLoc {
    std::unique_ptr<Bot> bot;
    Location loc;
};


#endif
